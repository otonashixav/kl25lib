#include "common.h"
#include "MKL25Z4.h"

typedef enum color_t {
	LED_BLUE = 0b001,
	LED_GREEN = 0b010,
	LED_CYAN = 0b011,
	LED_RED = 0b100,
	LED_MAGENTA = 0b101,
	LED_YELLOW = 0b110,
	LED_WHITE = 0b111
} color_t;

/**
 * Initializes the necessary registers to set the relevant LED pins to GPIO
 */
void init_led(void);

/**
 * Sets the led to a certain color from those in color_t.
 * @param[in] color color to set the led to.
 */
void set_led(color_t color);


/**
 * Sets the intensity of the red led.
 * @param[in] value value to set the led to (0 or 1 currently; possible upgrade to higher bit color).
 */
void set_red_led(uint8_t value);


/**
 * Sets the intensity of the green led.
 * @param[in] value value to set the led to (0 or 1 currently; possible upgrade to higher bit color).
 */
void set_green_led(uint8_t value);


/**
 * Sets the intensity of the blue led.
 * @param[in] value value to set the led to (0 or 1 currently; possible upgrade to higher bit color).
 */
void set_blue_led(uint8_t value);
