#include "tpm.h"
#include "common.h"
#include "MKL25Z4.h"

void init(uint32_t cpwms, uint32_t cmod, uint32_t prescaler) {
    // enable clocks

    // set pins to tpm

    // set cpwms cmod prescaler
}
void set_mod(uint32_t mod) {
    // set mod
    // why is this even a function 
    // maybe dont make this a function
    // it's one line
}
void init_channel(unsigned int channel, tpm_channel_mode_t mode) {
    // set mode
    // ???
}
void set_channel_val(unsigned int channel, uint32_t val) {
    // ???????????
}
