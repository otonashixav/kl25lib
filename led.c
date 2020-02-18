#define RED_LED_PIN     18 // PortB Pin 18
#define GREEN_LED_PIN   19 // PortB Pin 19
#define BLUE_LED_PIN    1  // PortD Pin 1
#include "common.h"
#include "MKL25Z4.h"
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
	
	clear_led();
}

void clear_led() {
	PTB->PSOR = (MASK(RED_LED_PIN) | MASK(GREEN_LED_PIN));
	PTD->PSOR = MASK(BLUE_LED_PIN);
}

void set_led(color_t color) {
	clear_led();
	if (color == LED_RED) {
		PTB->PCOR = MASK(RED_LED_PIN);
	} else if (color == LED_GREEN) {
		PTB->PCOR = MASK(GREEN_LED_PIN);
	} else if (color == LED_BLUE) {
		PTD->PCOR = MASK(BLUE_LED_PIN);
	}
}
