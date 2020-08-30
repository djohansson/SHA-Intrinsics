#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

void sha512_process(uint64_t state[8], const uint8_t data[], uint64_t length);

#ifdef __cplusplus
}
#endif
