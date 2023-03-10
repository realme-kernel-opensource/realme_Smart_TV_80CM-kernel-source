/*
 * vdso_test.c: Sample code to test parse_vdso.c
 * Copyright (c) 2014 Andy Lutomirski
 * Subject to the GNU General Public License, version 2
 *
 * Compile with:
 * gcc -std=gnu99 vdso_test.c parse_vdso.c
 *
 * Tested on x86, 32-bit and 64-bit.  It may work on other architectures, too.
 */

#include <stdint.h>
#include <elf.h>
#include <stdio.h>
#include <sys/auxv.h>
#include <sys/time.h>

#include "../kselftest.h"

extern void *vdso_sym(const char *version, const char *name);
extern void vdso_init_from_sysinfo_ehdr(uintptr_t base);
extern void vdso_init_from_auxv(void *auxv);

/*
 * ARM64's vDSO exports its gettimeofday() implementation with a different
 * name and version from other architectures, so we need to handle it as
 * a special case.
 */
#if defined(__aarch64__)
const char *version = "LINUX_2.6.39";
const char *name = "__kernel_gettimeofday";
#else
const char *version = "LINUX_2.6";
const char *name = "__vdso_gettimeofday";
#endif

int main(int argc, char **argv)
{
	unsigned long sysinfo_ehdr = getauxval(AT_SYSINFO_EHDR);
	if (!sysinfo_ehdr) {
		printf("AT_SYSINFO_EHDR is not present!\n");
		return KSFT_SKIP;
	}

	vdso_init_from_sysinfo_ehdr(getauxval(AT_SYSINFO_EHDR));

	/* Find gettimeofday. */
	typedef long (*gtod_t)(struct timeval *tv, struct timezone *tz);
	gtod_t gtod = (gtod_t)vdso_sym(version, name);

	if (!gtod) {
		printf("Could not find %s\n", name);
		return KSFT_SKIP;
	}

	struct timeval tv;
	long ret = gtod(&tv, 0);

	if (ret == 0) {
		printf("The time is %lld.%06lld\n",
		       (long long)tv.tv_sec, (long long)tv.tv_usec);
	} else {
		printf("%s failed\n", name);
		return KSFT_FAIL;
	}

	return 0;
}
