/*
 * Copyright (C) 2006-2017 Oracle Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __HGSMI_DEFS_H__
#define __HGSMI_DEFS_H__

/* Buffer sequence type mask. */
#define HGSMI_BUFFER_HEADER_F_SEQ_MASK     0x03
/* Single buffer, not a part of a sequence. */
#define HGSMI_BUFFER_HEADER_F_SEQ_SINGLE   0x00
/* The first buffer in a sequence. */
#define HGSMI_BUFFER_HEADER_F_SEQ_START    0x01
/* A middle buffer in a sequence. */
#define HGSMI_BUFFER_HEADER_F_SEQ_CONTINUE 0x02
/* The last buffer in a sequence. */
#define HGSMI_BUFFER_HEADER_F_SEQ_END      0x03

/* 16 bytes buffer header. */
struct hgsmi_buffer_header {
	u32 data_size;		/* Size of data that follows the header. */
	u8 flags;		/* HGSMI_BUFFER_HEADER_F_* */
	u8 channel;		/* The channel the data must be routed to. */
	u16 channel_info;	/* Opaque to the HGSMI, used by the channel. */

	union {
		/* Opaque placeholder to make the union 8 bytes. */
		u8 header_data[8];

		/* HGSMI_BUFFER_HEADER_F_SEQ_SINGLE */
		struct {
			u32 reserved1;	/* A reserved field, initialize to 0. */
			u32 reserved2;	/* A reserved field, initialize to 0. */
		} buffer;

		/* HGSMI_BUFFER_HEADER_F_SEQ_START */
		struct {
			/* Must be the same for all buffers in the sequence. */
			u32 sequence_number;
			/* The total size of the sequence. */
			u32 sequence_size;
		} sequence_start;

		/*
		 * HGSMI_BUFFER_HEADER_F_SEQ_CONTINUE and
		 * HGSMI_BUFFER_HEADER_F_SEQ_END
		 */
		struct {
			/* Must be the same for all buffers in the sequence. */
			u32 sequence_number;
			/* Data offset in the entire sequence. */
			u32 sequence_offset;
		} sequence_continue;
	} u;
} __packed;

/* 8 bytes buffer tail. */
struct hgsmi_buffer_tail {
	/* Reserved, must be initialized to 0. */
	u32 reserved;
	/*
	 * One-at-a-Time Hash: http://www.burtleburtle.net/bob/hash/doobs.html
	 * Over the header, offset and for first 4 bytes of the tail.
	 */
	u32 checksum;
} __packed;

/*
 * The size of the array of channels. Array indexes are u8.
 * Note: the value must not be changed.
 */
#define HGSMI_NUMBER_OF_CHANNELS 0x100

#endif
