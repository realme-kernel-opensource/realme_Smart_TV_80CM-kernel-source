# SPDX-License-Identifier: GPL-2.0
#
# Arch-specific network modules
#
ifdef CONFIG_PPC64
obj-$(CONFIG_BPF_JIT) += bpf_jit_comp64.o
else
obj-$(CONFIG_BPF_JIT) += bpf_jit_asm.o bpf_jit_comp.o
endif
