#include <asm/ucontext.h>

struct sigframe {
	struct ucontext uc;
	unsigned long retcode[4];
};

struct rt_sigframe {
	struct siginfo info;
	struct sigframe sig;
};
