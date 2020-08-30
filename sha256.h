#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

void sha256_process(uint32_t state[8], const uint8_t data[], uint32_t length);

#ifdef __cplusplus
}
#endif
