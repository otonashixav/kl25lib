#include "tpm_channel_mode_enum.h"
typedef unsigned int uint32_t;

void init(uint32_t cpwms, uint32_t cmod, uint32_t prescaler);
void set_mod(uint32_t mod);
void init_channel(unsigned int channel, tpm_channel_mode_t mode);
void set_channel_val(unsigned int channel, uint32_t val);
