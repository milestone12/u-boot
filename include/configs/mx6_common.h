/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2013, NVIDIA CORPORATION.  All rights reserved.
 */

#ifndef __MX6_COMMON_H
#define __MX6_COMMON_H

#include <linux/stringify.h>

#if (defined(CONFIG_MX6UL) || defined(CONFIG_MX6ULL))
#define CONFIG_SC_TIMER_CLK 8000000 /* 8Mhz */
#define COUNTER_FREQUENCY CONFIG_SC_TIMER_CLK
#else
#ifndef CONFIG_SYS_L2CACHE_OFF
#define CONFIG_SYS_L2_PL310
#define CONFIG_SYS_PL310_BASE	L2_PL310_BASE
#endif

#endif
#define CONFIG_BOARD_POSTCLK_INIT
#define CONFIG_MXC_GPT_HCLK

#define CONFIG_SYS_BOOTM_LEN	0x1000000

#include <linux/sizes.h>
#include <asm/arch/imx-regs.h>
#include <asm/mach-imx/gpio.h>

#ifndef CONFIG_MX6
#define CONFIG_MX6
#endif

#define CONFIG_SYS_FSL_CLK

/* Miscellaneous configurable options */
#define CONFIG_SYS_CBSIZE	512
#define CONFIG_SYS_MAXARGS	32

/* MMC */

#endif
