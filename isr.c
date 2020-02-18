#include "MKL25Z4.h"
#include "common.h"
#define SWITCH_PIN 6
void init_switch(void) {
	// Enable PortD Clock
	SIM->SCGC5 |= (SIM_SCGC5_PORTD_MASK);
	
	PORTD->PCR[SWITCH_PIN] &= ~PORT_PCR_MUX_MASK; // Clear MUX settings
	// Set MUX to GPIO, enable pull and set pull direction to up, set interrupt to falling edge
	PORTD->PCR[SWITCH_PIN] |= PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK | PORT_PCR_IRQC(0xA);
	// Set the pin direction to input
	PTD->PDDR &= ~MASK(SWITCH_PIN);
	
	// Enable interrupts
	NVIC_SetPriority(PORTD_IRQn, 2);
	NVIC_ClearPendingIRQ(PORTD_IRQn);
	NVIC_EnableIRQ(PORTD_IRQn);
}
