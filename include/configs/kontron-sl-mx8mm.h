/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2019 Kontron Electronics GmbH
 *
 * Configuration settings for the Kontron SL/BL i.MX8M-Mini boards and modules (N81xx).
 */
#ifndef __KONTRON_MX8MM_CONFIG_H
#define __KONTRON_MX8MM_CONFIG_H

#include <asm/arch/imx-regs.h>
#include <linux/sizes.h>

#ifdef CONFIG_SPL_BUILD
#include <config.h>
#endif

/* RAM */
#define PHYS_SDRAM			DDR_CSD1_BASE_ADDR
#define PHYS_SDRAM_SIZE			(SZ_4G)
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM

#define CONFIG_SYS_INIT_RAM_ADDR	0x40000000
#define CONFIG_SYS_INIT_RAM_SIZE	0x200000

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

/* Board and environment settings */
#define CONFIG_MXC_UART_BASE		UART3_BASE_ADDR
#define CONFIG_HOSTNAME			"kontron-mx8mm"

#ifdef CONFIG_USB_EHCI_HCD
#define CONFIG_EHCI_HCD_INIT_AFTER_RESET
#define CONFIG_MXC_USB_PORTSC		(PORT_PTS_UTMI | PORT_PTS_PTW)
#define CONFIG_MXC_USB_FLAGS		0
#define CONFIG_USB_MAX_CONTROLLER_COUNT	2
#endif

#ifndef CONFIG_SPL_BUILD
#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 1) \
	func(MMC, mmc, 0) \
	func(USB, usb, 0) \
	func(PXE, pxe, na)
#include <config_distro_bootcmd.h>
/* Do not try to probe USB net adapters for net boot */
#undef BOOTENV_RUN_NET_USB_START
#define BOOTENV_RUN_NET_USB_START
#else
#define BOOTENV
#endif

#define CONFIG_SYS_BOOTM_LEN		SZ_64M
#define CONFIG_SPL_MAX_SIZE		(148 * SZ_1K)
#define CONFIG_FSL_USDHC

#ifdef CONFIG_SPL_BUILD
#define CONFIG_SPL_STACK		0x91fff0
#define CONFIG_SPL_BSS_START_ADDR	0x910000
#define CONFIG_SPL_BSS_MAX_SIZE		SZ_8K
#define CONFIG_SYS_SPL_MALLOC_START	0x42200000
#define CONFIG_SYS_SPL_MALLOC_SIZE	SZ_512K
/* malloc f used before GD_FLG_FULL_MALLOC_INIT set */
#define CONFIG_MALLOC_F_ADDR		0x930000
#endif

#define FEC_QUIRK_ENET_MAC

#define CONFIG_EXTRA_ENV_SETTINGS \
	"kernel_addr_r=0x42000000\0" \
	"fdt_addr_r=0x44000000\0" \
	"ramdisk_addr_r=0x46400000\0" \
	"pxefile_addr_r=0x46000000\0" \
	"scriptaddr=0x46000000\0" \
	"dfu_alt_info=sf 0:0=flash-bin raw 0x400 0x1f0000\0" \
	"bootdelay=3\0" \
	"hostname=" CONFIG_HOSTNAME "\0" \
	BOOTENV

#endif /* __KONTRON_MX8MM_CONFIG_H */
