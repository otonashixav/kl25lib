#ifndef TPM1_H
#define TPM1_H
#include "tpm_channel_mode_enum.h"
#include <stdint.h>

/**
 * Initializes TPM1
 * @param[in] cpwms      the value of cpwms; 1 when using PWM and center alignment is desired, else 0
 * @param[in] cmod       the value of cmod; 0: disabled  1: LPTPM clock  2: LPTPM_EXTCLK
 * @param[in] prescaler  the prescaler applied to the clock; 3-bit value that slows the clock by a factor of 2^prescaler
 */
void tpm1_init(uint32_t cpwms, uint32_t cmod, uint32_t prescaler);

/**
 * Sets the value of mod for TPM1
 * @param[in] mod  the value of mod, a 16-bit number
 */
void tpm1_set_mod(uint32_t mod);

/**
 * Sets the mode of a channel of TPM1
 * @param[in] channel  the channel whose mode to set
 * @param[in] mode     the mode to set the channel to
 */
void tpm1_set_channel_mode(unsigned int channel, tpm_channel_mode_t mode);

/**
 * Sets the value of a channel of TPM1
 * @param[in] channel  the channel whose mode to set
 * @param[in] mode     the mode to set the channel to
 */
void tpm1_set_channel_val(unsigned int channel, uint32_t val);
#endif // TPM1_H
