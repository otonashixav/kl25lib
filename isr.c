#include "isr.h"

// https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/WInterrupts.c
// Used as an example for setting up a decent isr library. Accessed 26/2/2020.
#define PORTA_ISR_SIZE 32
#define PORTD_ISR_SIZE 8

// "nodes" for isr lists
typedef struct isr {
	void (*function)(void);
	uint8_t next;
} isr;

// staticly allocate some memory for isr information
static volatile struct isr porta_isr_list[PORTA_ISR_SIZE] = {{&empty_function, PORTA_ISR_SIZE}};
static volatile struct isr portd_isr_list[PORTD_ISR_SIZE] = {{&empty_function, PORTD_ISR_SIZE}};

// list heads; initialize to size which acts as null
static volatile uint8_t porta_isr_head = PORTA_ISR_SIZE;
static volatile uint8_t portd_isr_head = PORTD_ISR_SIZE;

static void empty_function(void) {}

static void isr_list_add(volatile struct isr list[], uint8_t size, volatile uint8_t *head, uint8_t add) {
	while (*head != size) {
		head = &(list[*head].next);
	}
	*head = add;
	list[add].next = size;
}

static void isr_list_remove(volatile struct isr list[], uint8_t size, volatile uint8_t *head, uint8_t remove) {
	while (*head != remove) {
		if (*head == size) {
			return;
		}
		head = &(list[*head].next);
	}
	*head = list[remove].next;
}

static void execute_isr_list(volatile struct isr list[], PORT_Type *port, volatile uint8_t head, uint8_t size) {
	while (head != size) {
		if (!(port->ISFR & MASK(head))) {
			(*list[head].function)();
			port->ISFR |= MASK(head);
		}
		head = list[head].next;
	}
}

void PORTA_IRQHandler(void) {
	NVIC_ClearPendingIRQ(PORTA_IRQn);
	execute_isr_list(porta_isr_list, PORTA, porta_isr_head, PORTA_ISR_SIZE);
}

void PORTD_IRQHandler(void) {
	NVIC_ClearPendingIRQ(PORTD_IRQn);
	execute_isr_list(portd_isr_list, PORTA, portd_isr_head, PORTD_ISR_SIZE);
}

static void init_isr(uint32_t scgc5_mask, enum IRQn irqn, uint8_t priority) {
	// Enable Clock
	SIM->SCGC5 |= (scgc5_mask);
	
	// Enable interrupts
	NVIC_SetPriority(irqn, priority);
	NVIC_ClearPendingIRQ(irqn);
	NVIC_EnableIRQ(irqn);
}

static void attach_isr(PORT_Type *port, GPIO_Type *gpio, uint8_t pin, 
	void (*function)(void), uint8_t pull_enable, uint8_t pull_select, uint8_t irqc) {
	
	port->PCR[pin] &= ~PORT_PCR_MUX_MASK; // Clear MUX settings
	// Set MUX to GPIO, enable pull and set pull direction to up, set interrupt to falling edge
	port->PCR[pin] |= PORT_PCR_MUX(1) | PORT_PCR_PE(pull_enable) | PORT_PCR_PS(pull_select) | PORT_PCR_IRQC(irqc);
	// Set the pin direction to input
	gpio->PDDR &= ~MASK(pin);
}

void init_porta_isr(uint8_t priority) {
	init_isr(SIM_SCGC5_PORTA_MASK, PORTA_IRQn, priority);
}

void attach_porta_isr(uint8_t pin, void (*function)(void), uint8_t pull_enable, uint8_t pull_select, uint8_t irqc, uint8_t priority) {
	isr_list_add(porta_isr_list, PORTA_ISR_SIZE, &porta_isr_head, pin);
	porta_isr_list[pin].function = function;
	attach_isr(PORTA, PTA, pin, function, pull_enable, pull_select, irqc);
}

void detach_porta_isr(uint8_t pin) {
	isr_list_remove(porta_isr_list, PORTA_ISR_SIZE, &porta_isr_head, pin);
}

void disable_porta_isr(void) {
	NVIC_DisableIRQ(PORTA_IRQn);
}

void init_porta_isr(uint8_t priority) {
	init_isr(SIM_SCGC5_PORTD_MASK, PORTD_IRQn, priority);
}

void attach_portd_isr(uint8_t pin, void (*function)(void), uint8_t pull_enable, uint8_t pull_select, uint8_t irqc, uint8_t priority) {
	isr_list_add(portd_isr_list, PORTD_ISR_SIZE, &portd_isr_head, pin);
	portd_isr_list[pin].function = function;
	attach_isr(PORTD, PTD, pin, function, pull_enable, pull_select, irqc);
}

void attach_portd_isr(uint8_t pin) {
	isr_list_remove(portd_isr_list, PORTD_ISR_SIZE, &portd_isr_head, pin);
}

void disable_portd_isr(void) {
	NVIC_DisableIRQ(PORTD_IRQn);
}
