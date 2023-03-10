/*
 * arch/arm/mach-prima2/include/mach/sirfsoc_usp.h
 *
 * Copyright (c) 2011 Cambridge Silicon Radio Limited, a CSR plc group company.
 *
 * Licensed under GPLv2 or later.
 */

#ifndef _SIRF_USP_H
#define _SIRF_USP_H

/* USP Registers */
#define USP_MODE1		0x00
#define USP_MODE2		0x04
#define USP_TX_FRAME_CTRL	0x08
#define USP_RX_FRAME_CTRL	0x0C
#define USP_TX_RX_ENABLE	0x10
#define USP_INT_ENABLE		0x14
#define USP_INT_STATUS		0x18
#define USP_PIN_IO_DATA		0x1C
#define USP_RISC_DSP_MODE	0x20
#define USP_AYSNC_PARAM_REG	0x24
#define USP_IRDA_X_MODE_DIV	0x28
#define USP_SM_CFG		0x2C
#define USP_TX_DMA_IO_CTRL	0x100
#define USP_TX_DMA_IO_LEN	0x104
#define USP_TX_FIFO_CTRL	0x108
#define USP_TX_FIFO_LEVEL_CHK	0x10C
#define USP_TX_FIFO_OP		0x110
#define USP_TX_FIFO_STATUS	0x114
#define USP_TX_FIFO_DATA	0x118
#define USP_RX_DMA_IO_CTRL	0x120
#define USP_RX_DMA_IO_LEN	0x124
#define USP_RX_FIFO_CTRL	0x128
#define USP_RX_FIFO_LEVEL_CHK	0x12C
#define USP_RX_FIFO_OP		0x130
#define USP_RX_FIFO_STATUS	0x134
#define USP_RX_FIFO_DATA	0x138

/* USP MODE register-1 */
#define USP_SYNC_MODE			0x00000001
#define USP_CLOCK_MODE_SLAVE		0x00000002
#define USP_LOOP_BACK_EN		0x00000004
#define USP_HPSIR_EN			0x00000008
#define USP_ENDIAN_CTRL_LSBF		0x00000010
#define USP_EN				0x00000020
#define USP_RXD_ACT_EDGE_FALLING	0x00000040
#define USP_TXD_ACT_EDGE_FALLING	0x00000080
#define USP_RFS_ACT_LEVEL_LOGIC1	0x00000100
#define USP_TFS_ACT_LEVEL_LOGIC1	0x00000200
#define USP_SCLK_IDLE_MODE_TOGGLE	0x00000400
#define USP_SCLK_IDLE_LEVEL_LOGIC1	0x00000800
#define USP_SCLK_PIN_MODE_IO	0x00001000
#define USP_RFS_PIN_MODE_IO	0x00002000
#define USP_TFS_PIN_MODE_IO	0x00004000
#define USP_RXD_PIN_MODE_IO	0x00008000
#define USP_TXD_PIN_MODE_IO	0x00010000
#define USP_SCLK_IO_MODE_INPUT	0x00020000
#define USP_RFS_IO_MODE_INPUT	0x00040000
#define USP_TFS_IO_MODE_INPUT	0x00080000
#define USP_RXD_IO_MODE_INPUT	0x00100000
#define USP_TXD_IO_MODE_INPUT	0x00200000
#define USP_IRDA_WIDTH_DIV_MASK	0x3FC00000
#define USP_IRDA_WIDTH_DIV_OFFSET	0
#define USP_IRDA_IDLE_LEVEL_HIGH	0x40000000
#define USP_TX_UFLOW_REPEAT_ZERO	0x80000000
#define USP_TX_ENDIAN_MODE		0x00000020
#define USP_RX_ENDIAN_MODE		0x00000020

/* USP Mode Register-2 */
#define USP_RXD_DELAY_LEN_MASK		0x000000FF
#define USP_RXD_DELAY_LEN_OFFSET	0

#define USP_TXD_DELAY_LEN_MASK		0x0000FF00
#define USP_TXD_DELAY_LEN_OFFSET	8

#define USP_ENA_CTRL_MODE		0x00010000
#define USP_FRAME_CTRL_MODE		0x00020000
#define USP_TFS_SOURCE_MODE             0x00040000
#define USP_TFS_MS_MODE                 0x00080000
#define USP_CLK_DIVISOR_MASK		0x7FE00000
#define USP_CLK_DIVISOR_OFFSET		21

#define USP_TFS_CLK_SLAVE_MODE		(1<<20)
#define USP_RFS_CLK_SLAVE_MODE		(1<<19)

#define USP_IRDA_DATA_WIDTH		0x80000000

/* USP Transmit Frame Control Register */

#define USP_TXC_DATA_LEN_MASK		0x000000FF
#define USP_TXC_DATA_LEN_OFFSET		0

#define USP_TXC_SYNC_LEN_MASK		0x0000FF00
#define USP_TXC_SYNC_LEN_OFFSET		8

#define USP_TXC_FRAME_LEN_MASK		0x00FF0000
#define USP_TXC_FRAME_LEN_OFFSET	16

#define USP_TXC_SHIFTER_LEN_MASK	0x1F000000
#define USP_TXC_SHIFTER_LEN_OFFSET	24

#define USP_TXC_SLAVE_CLK_SAMPLE	0x20000000

#define USP_TXC_CLK_DIVISOR_MASK	0xC0000000
#define USP_TXC_CLK_DIVISOR_OFFSET	30

/* USP Receive Frame Control Register */

#define USP_RXC_DATA_LEN_MASK		0x000000FF
#define USP_RXC_DATA_LEN_OFFSET		0

#define USP_RXC_FRAME_LEN_MASK		0x0000FF00
#define USP_RXC_FRAME_LEN_OFFSET	8

#define USP_RXC_SHIFTER_LEN_MASK	0x001F0000
#define USP_RXC_SHIFTER_LEN_OFFSET	16

#define USP_START_EDGE_MODE	0x00800000
#define USP_I2S_SYNC_CHG	0x00200000

#define USP_RXC_CLK_DIVISOR_MASK	0x0F000000
#define USP_RXC_CLK_DIVISOR_OFFSET	24
#define USP_SINGLE_SYNC_MODE		0x00400000

/* Tx - RX Enable Register */

#define USP_RX_ENA		0x00000001
#define USP_TX_ENA		0x00000002

/* USP Interrupt Enable and status Register */
#define USP_RX_DONE_INT			0x00000001
#define USP_TX_DONE_INT			0x00000002
#define USP_RX_OFLOW_INT		0x00000004
#define USP_TX_UFLOW_INT		0x00000008
#define USP_RX_IO_DMA_INT		0x00000010
#define USP_TX_IO_DMA_INT		0x00000020
#define USP_RXFIFO_FULL_INT		0x00000040
#define USP_TXFIFO_EMPTY_INT		0x00000080
#define USP_RXFIFO_THD_INT		0x00000100
#define USP_TXFIFO_THD_INT		0x00000200
#define USP_UART_FRM_ERR_INT		0x00000400
#define USP_RX_TIMEOUT_INT		0x00000800
#define USP_TX_ALLOUT_INT		0x00001000
#define USP_RXD_BREAK_INT		0x00008000

/* All possible TX interruots */
#define USP_TX_INTERRUPT		(USP_TX_DONE_INT|USP_TX_UFLOW_INT|\
					USP_TX_IO_DMA_INT|\
					USP_TXFIFO_EMPTY_INT|\
					USP_TXFIFO_THD_INT)
/* All possible RX interruots */
#define USP_RX_INTERRUPT		(USP_RX_DONE_INT|USP_RX_OFLOW_INT|\
					USP_RX_IO_DMA_INT|\
					USP_RXFIFO_FULL_INT|\
					USP_RXFIFO_THD_INT|\
					USP_RX_TIMEOUT_INT)

#define USP_INT_ALL        0x1FFF

/* USP Pin I/O Data Register */

#define USP_RFS_PIN_VALUE_MASK	0x00000001
#define USP_TFS_PIN_VALUE_MASK	0x00000002
#define USP_RXD_PIN_VALUE_MASK	0x00000004
#define USP_TXD_PIN_VALUE_MASK	0x00000008
#define USP_SCLK_PIN_VALUE_MASK	0x00000010

/* USP RISC/DSP Mode Register */
#define USP_RISC_DSP_SEL	0x00000001

/* USP ASYNC PARAMETER Register*/

#define USP_ASYNC_TIMEOUT_MASK	0x0000FFFF
#define USP_ASYNC_TIMEOUT_OFFSET	0
#define USP_ASYNC_TIMEOUT(x)	(((x)&USP_ASYNC_TIMEOUT_MASK) \
				<<USP_ASYNC_TIMEOUT_OFFSET)

#define USP_ASYNC_DIV2_MASK		0x003F0000
#define USP_ASYNC_DIV2_OFFSET		16

/* USP TX DMA I/O MODE Register */
#define USP_TX_MODE_IO			0x00000001

/* USP TX DMA I/O Length Register */
#define USP_TX_DATA_LEN_MASK		0xFFFFFFFF
#define USP_TX_DATA_LEN_OFFSET		0

/* USP TX FIFO Control Register */
#define USP_TX_FIFO_WIDTH_MASK		0x00000003
#define USP_TX_FIFO_WIDTH_OFFSET	0

#define USP_TX_FIFO_THD_MASK		0x000001FC
#define USP_TX_FIFO_THD_OFFSET		2

/* USP TX FIFO Level Check Register */
#define USP_TX_FIFO_LEVEL_CHECK_MASK	0x1F
#define USP_TX_FIFO_SC_OFFSET	0
#define USP_TX_FIFO_LC_OFFSET	10
#define USP_TX_FIFO_HC_OFFSET	20

#define TX_FIFO_SC(x)		(((x) & USP_TX_FIFO_LEVEL_CHECK_MASK) \
				<< USP_TX_FIFO_SC_OFFSET)
#define TX_FIFO_LC(x)		(((x) & USP_TX_FIFO_LEVEL_CHECK_MASK) \
				<< USP_TX_FIFO_LC_OFFSET)
#define TX_FIFO_HC(x)		(((x) & USP_TX_FIFO_LEVEL_CHECK_MASK) \
				<< USP_TX_FIFO_HC_OFFSET)

/* USP TX FIFO Operation Register */
#define USP_TX_FIFO_RESET		0x00000001
#define USP_TX_FIFO_START		0x00000002

/* USP TX FIFO Status Register */
#define USP_TX_FIFO_LEVEL_MASK		0x0000007F
#define USP_TX_FIFO_LEVEL_OFFSET	0

#define USP_TX_FIFO_FULL		0x00000080
#define USP_TX_FIFO_EMPTY		0x00000100

/* USP TX FIFO Data Register */
#define USP_TX_FIFO_DATA_MASK		0xFFFFFFFF
#define USP_TX_FIFO_DATA_OFFSET		0

/* USP RX DMA I/O MODE Register */
#define USP_RX_MODE_IO			0x00000001
#define USP_RX_DMA_FLUSH		0x00000004

/* USP RX DMA I/O Length Register */
#define USP_RX_DATA_LEN_MASK		0xFFFFFFFF
#define USP_RX_DATA_LEN_OFFSET		0

/* USP RX FIFO Control Register */
#define USP_RX_FIFO_WIDTH_MASK		0x00000003
#define USP_RX_FIFO_WIDTH_OFFSET	0

#define USP_RX_FIFO_THD_MASK		0x000001FC
#define USP_RX_FIFO_THD_OFFSET		2

/* USP RX FIFO Level Check Register */

#define USP_RX_FIFO_LEVEL_CHECK_MASK	0x1F
#define USP_RX_FIFO_SC_OFFSET	0
#define USP_RX_FIFO_LC_OFFSET	10
#define USP_RX_FIFO_HC_OFFSET	20

#define RX_FIFO_SC(x)		(((x) & USP_RX_FIFO_LEVEL_CHECK_MASK) \
				<< USP_RX_FIFO_SC_OFFSET)
#define RX_FIFO_LC(x)		(((x) & USP_RX_FIFO_LEVEL_CHECK_MASK) \
				<< USP_RX_FIFO_LC_OFFSET)
#define RX_FIFO_HC(x)		(((x) & USP_RX_FIFO_LEVEL_CHECK_MASK) \
				<< USP_RX_FIFO_HC_OFFSET)

/* USP RX FIFO Operation Register */
#define USP_RX_FIFO_RESET		0x00000001
#define USP_RX_FIFO_START		0x00000002

/* USP RX FIFO Status Register */

#define USP_RX_FIFO_LEVEL_MASK		0x0000007F
#define USP_RX_FIFO_LEVEL_OFFSET	0

#define USP_RX_FIFO_FULL		0x00000080
#define USP_RX_FIFO_EMPTY		0x00000100

/* USP RX FIFO Data Register */

#define USP_RX_FIFO_DATA_MASK		0xFFFFFFFF
#define USP_RX_FIFO_DATA_OFFSET		0

/*
 * When rx thd irq occur, sender just disable tx empty irq,
 * Remaining data in tx fifo wil also be sent out.
 */
#define USP_FIFO_SIZE			128
#define USP_TX_FIFO_THRESHOLD		(USP_FIFO_SIZE/2)
#define USP_RX_FIFO_THRESHOLD		(USP_FIFO_SIZE/2)

/* FIFO_WIDTH for the USP_TX_FIFO_CTRL and USP_RX_FIFO_CTRL registers */
#define USP_FIFO_WIDTH_BYTE  0x00
#define USP_FIFO_WIDTH_WORD  0x01
#define USP_FIFO_WIDTH_DWORD 0x02

#define USP_ASYNC_DIV2          16

#define USP_PLUGOUT_RETRY_CNT	2

#define USP_TX_RX_FIFO_WIDTH_DWORD    2

#define SIRF_USP_DIV_MCLK	0

#define SIRF_USP_I2S_TFS_SYNC	0
#define SIRF_USP_I2S_RFS_SYNC	1
#endif
