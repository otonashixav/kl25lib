#ifndef TPM0_H
#define TPM0_H
#include "tpm_channel_mode_enum.h"
typedef unsigned int uint32_t;

#define TPM_CLOCK_MASK SIM_SCGC6_TPM0_MASK
#define PORT_CLOCK_MASK SIM_SCGC5_PORTD_MASK
#define PORT PORTD
#define TPM TPM0
#define TPM_MODULE_NAME tpm0
#define CHANNEL_0_PIN 0
#define CHANNEL_0_PIN_MUX 4
#define CHANNEL_1_PIN 1
#define CHANNEL_1_PIN_MUX 4
#define CHANNEL_2_PIN 2
#define CHANNEL_2_PIN_MUX 4
#define CHANNEL_3_PIN 3
#define CHANNEL_3_PIN_MUX 4
#define CHANNEL_4_PIN 4
#define CHANNEL_4_PIN_MUX 4
#define CHANNEL_5_PIN 5
#define CHANNEL_5_PIN_MUX 4

void tpm0_init(uint32_t cpwms, uint32_t cmod, uint32_t prescaler);
extern inline void tpm0_set_mod(uint32_t mod);
void tpm0_init_channel(unsigned int channel, tpm_channel_mode_t mode);
extern inline void tpm0_set_channel_val(unsigned int channel, uint32_t val);
#endif // TPM0_H
