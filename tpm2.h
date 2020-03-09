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

void tpm2_init(uint32_t cpwms, uint32_t cmod, uint32_t prescaler);
extern inline void tpm2_set_mod(uint32_t mod);
void tpm2_init_channel(unsigned int channel, tpm_channel_mode_t mode);
extern inline void tpm2_set_channel_val(unsigned int channel, uint32_t val);
#endif // TPM2_H
