#include "MKL25Z4.h"
#include "common.h"

void init_pwm(uint8_t);
void set_pwm(uint8_t, uint8_t);
void init_pit(uint8_t, void(*function)(void));