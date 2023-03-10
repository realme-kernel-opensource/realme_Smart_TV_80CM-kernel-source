======================
Memory Management APIs
======================

User Space Memory Access
========================

.. kernel-doc:: arch/x86/include/asm/uaccess.h
   :internal:

.. kernel-doc:: arch/x86/lib/usercopy_32.c
   :export:

.. kernel-doc:: mm/util.c
   :functions: get_user_pages_fast

Memory Allocation Controls
==========================

Functions which need to allocate memory often use GFP flags to express
how that memory should be allocated. The GFP acronym stands for "get
free pages", the underlying memory allocation function. Not every GFP
flag is allowed to every function which may allocate memory. Most
users will want to use a plain ``GFP_KERNEL``.

.. kernel-doc:: include/linux/gfp.h
   :doc: Page mobility and placement hints

.. kernel-doc:: include/linux/gfp.h
   :doc: Watermark modifiers

.. kernel-doc:: include/linux/gfp.h
   :doc: Reclaim modifiers

.. kernel-doc:: include/linux/gfp.h
   :doc: Common combinations

The Slab Cache
==============

.. kernel-doc:: include/linux/slab.h
   :internal:

.. kernel-doc:: mm/slab.c
   :export:

.. kernel-doc:: mm/util.c
   :functions: kfree_const kvmalloc_node kvfree

More Memory Management Functions
================================

.. kernel-doc:: mm/readahead.c
   :export:

.. kernel-doc:: mm/filemap.c
   :export:

.. kernel-doc:: mm/memory.c
   :export:

.. kernel-doc:: mm/vmalloc.c
   :export:

.. kernel-doc:: mm/page_alloc.c
   :internal:

.. kernel-doc:: mm/mempool.c
   :export:

.. kernel-doc:: mm/dmapool.c
   :export:

.. kernel-doc:: mm/page-writeback.c
   :export:

.. kernel-doc:: mm/truncate.c
   :export:
