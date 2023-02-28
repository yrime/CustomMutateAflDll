//#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#pragma warning(disable : 4996)
#include "pch.h"
#include "CustomAflMutate.h"
#include <stdio.h>

void mutate(u8* buf, u8* out_buf, u32 len) {

}

CUSTOM_MUTATE_API u8 dll_mutate_testcase(
	char **argv,
	u8 *buf,
	u32 len,
	u8(*common_fuzz_stuff)(char**, u8*, u32))
{
	//printf("buf in %s", buf);
	u8 *out_buf;
	out_buf = (u8*)malloc(len);
	mutate(buf, out_buf, len);
	printf("in t");
	common_fuzz_stuff(argv, out_buf, len);
	printf("buf out %s", out_buf);

	return 0;
}

CUSTOM_MUTATE_API void dll_write_to_testcase(
	u8 * out_file, 
	s32 out_fd, 
	const void * mem, 
	u32 len)
{
	s32 fd = out_fd;
	if (out_file) {
		fd = open((const char*)out_file, O_WRONLY | O_BINARY | O_CREAT | O_TRUNC, DEFAULT_PERMISSION);
	}
	else lseek(fd, 0, SEEK_SET);

	ck_write(fd, mem, len, out_file);
	if (!out_file) {

		if (_chsize(fd, len)) PFATAL("ftruncate() failed");
		lseek(fd, 0, SEEK_SET);

	}
	else close(fd);
	return ;
}

