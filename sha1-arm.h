#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

void sha1_process_arm(uint32_t state[5], const uint8_t data[], uint32_t length);

#ifdef __cplusplus
}
#endif
