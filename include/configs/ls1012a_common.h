/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright 2016 Freescale Semiconductor
 */

#ifndef __LS1012A_COMMON_H
#define __LS1012A_COMMON_H

#include <asm/arch/config.h>
#include <asm/arch/stream_id_lsch2.h>
#include <linux/sizes.h>

#define CONFIG_SYS_CLK_FREQ		125000000

#ifdef CONFIG_TFABOOT
#define CONFIG_SYS_INIT_SP_ADDR                CONFIG_SYS_TEXT_BASE
#else
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_FSL_OCRAM_BASE + 0xfff0)
#endif

#define CONFIG_SYS_DDR_SDRAM_BASE	0x80000000
#define CONFIG_SYS_FSL_DDR_SDRAM_BASE_PHY	0
#define CONFIG_SYS_SDRAM_BASE		CONFIG_SYS_DDR_SDRAM_BASE
#define CONFIG_SYS_DDR_BLOCK2_BASE     0x880000000ULL

/* Generic Timer Definitions */
#define COUNTER_FREQUENCY		25000000	/* 25MHz */

/* CSU */
#define CONFIG_LAYERSCAPE_NS_ACCESS

/* PFE */
#define CONFIG_SYS_FMAN_FW_ADDR		0x400d0000
#define CONFIG_SYS_QE_FMAN_FW_LENGTH	0x300000

/*SPI device */
#define CONFIG_SYS_FSL_QSPI_BASE	0x40000000

/* SATA */
#define CONFIG_SCSI_AHCI_PLAT

#define CONFIG_SYS_SATA				AHCI_BASE_ADDR

#define CONFIG_SYS_SCSI_MAX_SCSI_ID		1
#define CONFIG_SYS_SCSI_MAX_LUN			1
#define CONFIG_SYS_SCSI_MAX_DEVICE		(CONFIG_SYS_SCSI_MAX_SCSI_ID * \
						CONFIG_SYS_SCSI_MAX_LUN)

/* I2C */

/* GPIO */
#ifdef CONFIG_DM_GPIO
#ifndef CONFIG_MPC8XXX_GPIO
#define CONFIG_MPC8XXX_GPIO
#endif
#endif

#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE     1
#define CONFIG_SYS_NS16550_CLK          (get_serial_clock())

#define CONFIG_HWCONFIG
#define HWCONFIG_BUFFER_SIZE		128

#ifndef CONFIG_SPL_BUILD
#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 0) \
	func(USB, usb, 0) \
	func(SCSI, scsi, 0) \
	func(DHCP, dhcp, na)
#include <config_distro_bootcmd.h>
#endif

/* Initial environment variables */
#define CONFIG_EXTRA_ENV_SETTINGS		\
	"verify=no\0"				\
	"loadaddr=0x80100000\0"			\
	"kernel_addr=0x100000\0"		\
	"initrd_high=0xffffffffffffffff\0"	\
	"kernel_start=0x1000000\0"		\
	"kernel_load=0xa0000000\0"		\
	"kernel_size=0x2800000\0"		\
	"bootm_size=0x10000000\0"		\

#undef CONFIG_BOOTCOMMAND
#ifdef CONFIG_TFABOOT
#define QSPI_NOR_BOOTCOMMAND	"sf probe 0:0; sf read $kernel_load "\
				"$kernel_start $kernel_size && "\
				"bootm $kernel_load"
#else
#define CONFIG_BOOTCOMMAND	"sf probe 0:0; sf read $kernel_load "\
				"$kernel_start $kernel_size && "\
				"bootm $kernel_load"
#endif

/* Monitor Command Prompt */
#define CONFIG_SYS_CBSIZE		512	/* Console I/O Buffer Size */
#define CONFIG_SYS_MAXARGS		64	/* max command args */

#define CONFIG_SYS_BOOTM_LEN   (64 << 20)      /* Increase max gunzip size */

#include <asm/arch/soc.h>

#endif /* __LS1012A_COMMON_H */
