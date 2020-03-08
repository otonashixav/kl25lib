#ifndef TPM_CHANNEL_MODE_ENUM_H
#define TPM_CHANNEL_MODE_ENUM_H
typedef enum tpm_channel_mode_t {
    DISABLED =                  0x00,
    CAPTURE_ON_RISING =         0x04,
    CAPTURE_ON_FALLING =        0x08,
    CAPTURE_ON_ANY =            0x0c,
    OUTPUT_COMPARE_TOGGLE =     0x14,
    OUTPUT_COMPARE_CLEAR =      0x18,
    OUTPUT_COMPARE_SET =        0x1c,
    PWM_LOW =                   0x24,
    PWM_HIGH =                  0x28,
    OUTPUT_COMPARE_PULSE_HIGH = 0x34,
    OUTPUT_COMPARE_PULSE_LOW =  0x38
} tpm_channel_mode_t;
#endif // TPM_CHANNEL_MODE_ENUM_H
