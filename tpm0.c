#include "tpm0.h"

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

#include "__generic_tpm.h"
