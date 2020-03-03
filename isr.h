#include "MKL25Z4.h"
#include "common.h"

void attach_porta_isr(uint8_t pin, void (*function)(void), uint8_t pull_enable, uint8_t pull_select, uint8_t irqc, uint8_t priority);
void detach_porta_isr(uint8_t pin);
void disable_porta_isr(void);
void set_portd_isr(uint8_t pin, void (*function)(void), uint8_t pull_enable, uint8_t pull_select, uint8_t irqc, uint8_t priority);
void detach_portd_isr(uint8_t pin);
void disable_portd_isr(void);
