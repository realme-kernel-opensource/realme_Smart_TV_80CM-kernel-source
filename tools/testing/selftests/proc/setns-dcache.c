/*
 * Copyright © 2019 Alexey Dobriyan <adobriyan@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
/*
 * Test that setns(CLONE_NEWNET) points to new /proc/net content even
 * if old one is in dcache.
 *
 * FIXME /proc/net/unix is under CONFIG_UNIX which can be disabled.
 */
#undef NDEBUG
#include <assert.h>
#include <errno.h>
#include <sched.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>

static pid_t pid = -1;

static void f(void)
{
	if (pid > 0) {
		kill(pid, SIGTERM);
	}
}

int main(void)
{
	int fd[2];
	char _ = 0;
	int nsfd;

	atexit(f);

	/* Check for priviledges and syscall availability straight away. */
	if (unshare(CLONE_NEWNET) == -1) {
		if (errno == ENOSYS || errno == EPERM) {
			return 4;
		}
		return 1;
	}
	/* Distinguisher between two otherwise empty net namespaces. */
	if (socket(AF_UNIX, SOCK_STREAM, 0) == -1) {
		return 1;
	}

	if (pipe(fd) == -1) {
		return 1;
	}

	pid = fork();
	if (pid == -1) {
		return 1;
	}

	if (pid == 0) {
		if (unshare(CLONE_NEWNET) == -1) {
			return 1;
		}

		if (write(fd[1], &_, 1) != 1) {
			return 1;
		}

		pause();

		return 0;
	}

	if (read(fd[0], &_, 1) != 1) {
		return 1;
	}

	{
		char buf[64];
		snprintf(buf, sizeof(buf), "/proc/%u/ns/net", pid);
		nsfd = open(buf, O_RDONLY);
		if (nsfd == -1) {
			return 1;
		}
	}

	/* Reliably pin dentry into dcache. */
	(void)open("/proc/net/unix", O_RDONLY);

	if (setns(nsfd, CLONE_NEWNET) == -1) {
		return 1;
	}

	kill(pid, SIGTERM);
	pid = 0;

	{
		char buf[4096];
		ssize_t rv;
		int fd;

		fd = open("/proc/net/unix", O_RDONLY);
		if (fd == -1) {
			return 1;
		}

#define S "Num       RefCount Protocol Flags    Type St Inode Path\n"
		rv = read(fd, buf, sizeof(buf));

		assert(rv == strlen(S));
		assert(memcmp(buf, S, strlen(S)) == 0);
	}

	return 0;
}
