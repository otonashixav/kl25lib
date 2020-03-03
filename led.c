#define RED_LED_PIN     18 // PortB Pin 18
#define GREEN_LED_PIN   19 // PortB Pin 19
#define BLUE_LED_PIN    1  // PortD Pin 1
#include "led.h"

void init_led(void){
	// Enable PortB and PortD Clocks
	SIM->SCGC5 |= ((SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK));
	
	// Configure MUX settings to make RGB pins GPIO
	PORTB->PCR[RED_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[RED_LED_PIN] |= PORT_PCR_MUX(1);
	
	PORTB->PCR[GREEN_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[GREEN_LED_PIN] |= PORT_PCR_MUX(1);
	
	PORTD->PCR[BLUE_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[BLUE_LED_PIN] |= PORT_PCR_MUX(1);
	
	PTB->PDDR |= (MASK(RED_LED_PIN) | MASK(GREEN_LED_PIN));
	PTD->PDDR |= MASK(BLUE_LED_PIN);
	
	set_red_led(0);
	set_green_led(0);
	set_blue_led(0);
}

void set_led_color(color_t color) {
	if (MASK(2) & color) {
		set_red_led(1);
	}
	
	if (MASK(1) & color) {
		set_green_led(1);
	}
	
	if (MASK(0) & color) {
		set_blue_led(1);
	}
}

void set_red_led(uint8_t value) {
	if (value) {
		PTB->PCOR = MASK(RED_LED_PIN);
	} else {
		PTB->PSOR = MASK(RED_LED_PIN);
	}
}

void set_green_led(uint8_t value) {
	if (value) {
		PTB->PCOR = MASK(GREEN_LED_PIN);
	} else {
		PTB->PSOR = MASK(GREEN_LED_PIN);
	}
}

void set_blue_led(uint8_t value) {
	if (value) {
		PTB->PCOR = MASK(BLUE_LED_PIN);
	} else {
		PTB->PSOR = MASK(BLUE_LED_PIN);
	}
}
