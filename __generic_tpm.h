#include "common.h"
#include "MKL25Z4.h"
#include "tpm_channel_mode_enum.h"

#ifndef TPM_CLOCK_MASK
#error Missing #define TPM_CLOCK_MASK
#endif
#ifndef PORT_CLOCK_MASK
#error Missing #define PORT_CLOCK_MASK
#endif
#ifndef PORT
#error MISSING #define PORT
#endif
#ifndef TPM
#error MISSING #define UART
#endif
#ifndef TPM_MODULE_NAME
#error MISSING #define UART_MODULE_NAME
#endif

#define INIT(N) CONCAT(N, _init)
void INIT(TPM_MODULE_NAME)(uint32_t cpwms, uint32_t cmod, uint32_t prescaler) {
    // enable clocks
    SIM->SOPT2 &= ~SIM_SOPT2_TPMSRC_MASK;
    SIM->SOPT2 |= SIM_SOPT2_TPMSRC(1);
    SIM->SCGC5 |= PORT_CLOCK_MASK;
    SIM->SCGC6 |= TPM_CLOCK_MASK;

    // set cpwms cmod prescaler
    TPM->SC &= ~(TPM_SC_CPWMS_MASK | TPM_SC_CMOD_MASK | TPM_SC_PS_MASK);
    TPM->SC |= TPM_SC_CPWMS(cpwms) | TPM_SC_CMOD(cmod) | TPM_SC_PS(prescaler);

    #if defined(CHANNEL_0_PIN) && defined(CHANNEL_0_PIN_MUX)
    PORT->PCR[CHANNEL_0_PIN] &= ~PORT_PCR_MUX_MASK;
    PORT->PCR[CHANNEL_0_PIN] |= PORT_PCR_MUX(CHANNEL_0_PIN_MUX);
    #endif
    #if defined(CHANNEL_1_PIN) && defined(CHANNEL_1_PIN_MUX)
    PORT->PCR[CHANNEL_1_PIN] &= ~PORT_PCR_MUX_MASK;
    PORT->PCR[CHANNEL_1_PIN] |= PORT_PCR_MUX(CHANNEL_1_PIN_MUX);
    #endif
    #if defined(CHANNEL_2_PIN) && defined(CHANNEL_2_PIN_MUX)
    PORT->PCR[CHANNEL_2_PIN] &= ~PORT_PCR_MUX_MASK;
    PORT->PCR[CHANNEL_2_PIN] |= PORT_PCR_MUX(CHANNEL_2_PIN_MUX);
    #endif
    #if defined(CHANNEL_3_PIN) && defined(CHANNEL_3_PIN_MUX)
    PORT->PCR[CHANNEL_3_PIN] &= ~PORT_PCR_MUX_MASK;
    PORT->PCR[CHANNEL_3_PIN] |= PORT_PCR_MUX(CHANNEL_3_PIN_MUX);
    #endif
    #if defined(CHANNEL_4_PIN) && defined(CHANNEL_4_PIN_MUX)
    PORT->PCR[CHANNEL_4_PIN] &= ~PORT_PCR_MUX_MASK;
    PORT->PCR[CHANNEL_4_PIN] |= PORT_PCR_MUX(CHANNEL_4_PIN_MUX);
    #endif
    #if defined(CHANNEL_5_PIN) && defined(CHANNEL_5_PIN_MUX)
    PORT->PCR[CHANNEL_5_PIN] &= ~PORT_PCR_MUX_MASK;
    PORT->PCR[CHANNEL_5_PIN] |= PORT_PCR_MUX(CHANNEL_5_PIN_MUX);
    #endif
}
inline void set_mod(uint32_t mod) {
    TPM->MOD = TPM_MOD_MOD(mod);
}
void init_channel(unsigned int channel, tpm_channel_mode_t mode) {
    TPM->CONTROLS[channel].CnSC &= ~(TPM_CnSC_MSB_MASK | TPM_CnSC_MSA_MASK | TPM_CnSC_ELSB_MASK | TPM_CnSC_ELSA_MASK);
    TPM->CONTROLS[channel].CnSC |= mode;
    
}
inline void set_channel_val(unsigned int channel, uint32_t val) {
    TPM->CONTROLS[channel].CnV = TPM_CnV_VAL(val);
}
