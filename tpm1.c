#include "tpm1.h"

#define TPM_CLOCK_MASK SIM_SCGC6_TPM1_MASK
#define PORT_CLOCK_MASK SIM_SCGC5_PORTB_MASK
#define PORT PORTB
#define TPM TPM1
#define TPM_MODULE_NAME tpm1
#define CHANNEL_0_PIN 0
#define CHANNEL_0_PIN_MUX 3
#define CHANNEL_1_PIN 1
#define CHANNEL_1_PIN_MUX 3

#include "__generic_tpm.h"
