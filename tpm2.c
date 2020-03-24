#include "tpm2.h"

#define TPM_CLOCK_MASK SIM_SCGC6_TPM2_MASK
#define PORT_CLOCK_MASK SIM_SCGC5_PORTB_MASK
#define PORT PORTB
#define TPM TPM2
#define TPM_MODULE_NAME tpm2
#define CHANNEL_0_PIN 18
#define CHANNEL_0_PIN_MUX 3
#define CHANNEL_1_PIN 19
#define CHANNEL_1_PIN_MUX 3

#include "__generic_tpm.h"
