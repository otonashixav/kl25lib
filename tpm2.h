#ifndef TPM2_H
#define TPM2_H
#include "tpm_channel_mode_enum.h"
typedef unsigned int uint32_t;

#define TPM_CLOCK_MASK SIM_SCGC6_TPM2_MASK
#define PORT_CLOCK_MASK SIM_SCGC5_PORTB_MASK
#define PORT PORTB
#define TPM TPM2
#define TPM_MODULE_NAME tpm2
#define CHANNEL_0_PIN 18
#define CHANNEL_0_PIN_MUX 3
#define CHANNEL_1_PIN 19
#define CHANNEL_1_PIN_MUX 3

/**
 * Initializes TPM2
 * @param[in] cpwms      the value of cpwms; 1 when using PWM and center alignment is desired, else 0
 * @param[in] cmod       the value of cmod; 0: disabled  1: LPTPM clock  2: LPTPM_EXTCLK
 * @param[in] prescaler  the prescaler applied to the clock; 3-bit value that slows the clock by a factor of 2^prescaler
 */
void tpm2_init(uint32_t cpwms, uint32_t cmod, uint32_t prescaler);

/**
 * Sets the value of mod for TPM2
 * @param[in] mod  the value of mod, a 16-bit number
 */
extern inline void tpm2_set_mod(uint32_t mod);

/**
 * Sets the mode of a channel of TPM2
 * @param[in] channel  the channel whose mode to set
 * @param[in] mode     the mode to set the channel to
 */
void tpm2_set_channel_mode(unsigned int channel, tpm_channel_mode_t mode);

/**
 * Sets the value of a channel of TPM2
 * @param[in] channel  the channel whose mode to set
 * @param[in] mode     the mode to set the channel to
 */
extern inline void tpm2_set_channel_val(unsigned int channel, uint32_t val);
#endif // TPM2_H
