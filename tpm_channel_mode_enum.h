#ifndef TPM_CHANNEL_MODE_ENUM_H
#define TPM_CHANNEL_MODE_ENUM_H

/**
 * Enums for setting the TPM channel modes. CPWMS should be 0 for
 * all modes, except for PWM_LOW and PWM_HIGH, where it should be
 * enabled if center aligned PWM is desired. 
 */
typedef enum tpm_channel_mode_t {
    // Disables the channel
    DISABLED =                  0x00,
    // Captures current count into CnV on rising edge
    CAPTURE_ON_RISING =         0x04, 
    // Captures current count into CnV on falling edge
    CAPTURE_ON_FALLING =        0x08,
    // Captures current count into CnV on any edge
    CAPTURE_ON_ANY =            0x0c,
    // Toggles the pin's output when count matches CnV
    OUTPUT_COMPARE_TOGGLE =     0x14,
    // Clears the pin's output when count matches CnV
    OUTPUT_COMPARE_CLEAR =      0x18,
    // Sets the pin's output when count matches CnV
    OUTPUT_COMPARE_SET =        0x1c,
    // Sets PWM with initial output low, setting high on match
    PWM_LOW =                   0x24,
    // Sets PWM with initial output high, setting low on match
    PWM_HIGH =                  0x28,
    // Sends a high pulse on output match, else low
    OUTPUT_COMPARE_PULSE_HIGH = 0x34,
    // Sends a low pulse on output match, else high
    OUTPUT_COMPARE_PULSE_LOW =  0x38
} tpm_channel_mode_t;
#endif // TPM_CHANNEL_MODE_ENUM_H
