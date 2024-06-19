#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

void sha512_process_p8(uint64_t state[8], const uint8_t data[], uint32_t length);

#ifdef __cplusplus
}
#endif
