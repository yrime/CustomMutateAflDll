//TestAfl.h

#pragma once

//#ifdef TESTAFL_EXPORTS
#define CUSTOM_MUTATE_API __declspec(dllexport)
//#else
//#define TESTAFL_API __declspec(dllimport)
//#endif

#include <stdint.h>
#include <stdlib.h>

#include <fcntl.h>
#include <corecrt_io.h>

#include "debug.h"

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef int8_t   s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;

#define DEFAULT_PERMISSION  0600

extern "C" CUSTOM_MUTATE_API u8 dll_mutate_testcase(
		char **argv, 
		u8 *buf, 
		u32 len, 
		u8 (*common_fuzz_stuff)(char**, u8*, u32)
);

extern "C" CUSTOM_MUTATE_API void dll_write_to_testcase(
	u8* out_file, 
	s32 out_fd, 
	const void* mem, 
	u32 len);
