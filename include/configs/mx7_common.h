/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2015 Freescale Semiconductor, Inc.
 *
 * Configuration settings for the Freescale i.MX7.
 */

#ifndef __MX7_COMMON_H
#define __MX7_COMMON_H

#include <linux/sizes.h>
#include <linux/stringify.h>
#include <asm/arch/imx-regs.h>
#include <asm/mach-imx/gpio.h>

#ifndef CONFIG_MX7
#define CONFIG_MX7
#endif

/* Timer settings */
#define CONFIG_MXC_GPT_HCLK
#define CONFIG_SC_TIMER_CLK 8000000 /* 8Mhz */
#define COUNTER_FREQUENCY CONFIG_SC_TIMER_CLK
#define CONFIG_SYS_FSL_CLK

#define CONFIG_SYS_BOOTM_LEN	0x1000000

/* Enable iomux-lpsr support */
#define CONFIG_IOMUX_LPSR

/* Miscellaneous configurable options */
#define CONFIG_SYS_CBSIZE		512
#define CONFIG_SYS_MAXARGS		32

/* UART */

/* MMC */

#define CONFIG_ARMV7_SECURE_BASE	0x00900000

/*
 * If we have defined the OPTEE ram size and not OPTEE it means that we were
 * launched by OPTEE, because of that we shall skip all the low level
 * initialization since it was already done by ATF or OPTEE
 */

#endif
