typedef enum color_t {
	LED_RED,
	LED_GREEN,
	LED_BLUE
} color_t;

/**
 * Initializes the necessary registers to set the relevant LED pins to GPIO
 */
void init_led(void);

/**
 * Clears the led i.e. turns it off. 
 */
void clear_led(void);

/**
 * Sets the led to a certain color from those in color_t.
 * @param[in] color color to set the led to.
 */
void set_led(color_t color);
