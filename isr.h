/**
 * Simply initiates a pin on Port D to act as an interrupt on falling edge. 
 * PORTD_IRQHandler should be specified elsewhere. 
 * @param[in] switch_pin the pin to use. 
 */
void init_switch(unsigned int switch_pin);
