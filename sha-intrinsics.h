#pragma once

#if defined(__arm__) || defined(__aarch32__) || defined(__arm64__) || defined(__aarch64__) || defined(_M_ARM)
#include "sha1-arm.h"
#include "sha256-arm.h"
#include "sha512.h"
#define SHA1_PROCESS sha1_process_arm
#define SHA256_PROCESS sha256_process_arm
#define SHA512_PROCESS sha512_process
#elif defined(__i386__) || defined(_M_IX86) || defined(_X86_) || defined(__x86_64__) || defined(_M_X64)
#include "sha1-x86.h"
#include "sha256-x86.h"
#include "sha512.h"
#define SHA1_PROCESS sha1_process_x86
#define SHA256_PROCESS sha256_process_x86
#define SHA512_PROCESS sha512_process
#else
#define SHA256_PROCESS sha256_process
#define SHA512_PROCESS sha512_process
#endif
