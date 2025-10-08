/**
 * @file max24287_driver.h
 * @brief MAX24287 Gigabit Ethernet PHY driver
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2025 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneTCP Open.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 2.5.0
 **/

#ifndef _MAX24287_DRIVER_H
#define _MAX24287_DRIVER_H

//Dependencies
#include "core/nic.h"

//PHY address
#ifndef MAX24287_PHY_ADDR
   #define MAX24287_PHY_ADDR 0
#elif (MAX24287_PHY_ADDR < 0 || MAX24287_PHY_ADDR > 31)
   #error MAX24287_PHY_ADDR parameter is not valid
#endif

//MAX24287 PHY registers
#define MAX24287_BMCR                                   0x00
#define MAX24287_BMSR                                   0x01
#define MAX24287_ID1                                    0x02
#define MAX24287_ID2                                    0x03
#define MAX24287_AN_ADV                                 0x04
#define MAX24287_AN_RX                                  0x05
#define MAX24287_AN_EXP                                 0x06
#define MAX24287_EXT_STAT                               0x0F
#define MAX24287_PAGESEL                                0x1F

//MAX24287 PHY registers (page 0)
#define MAX24287_JIT_DIAG                               0x10
#define MAX24287_PCSCR                                  0x11
#define MAX24287_GMIICR                                 0x12
#define MAX24287_CR                                     0x13
#define MAX24287_IR                                     0x14

//MAX24287 PHY registers (page 1)
#define MAX24287_ID                                     0x10
#define MAX24287_GPIOCR1                                0x11
#define MAX24287_GPIOCR2                                0x12
#define MAX24287_GPIOSR                                 0x13

//MAX24287 PHY registers (page 2)
#define MAX24287_PTPCR1                                 0x10

//Basic Mode Control register
#define MAX24287_BMCR_DP_RST                            0x8000
#define MAX24287_BMCR_DLB                               0x4000
#define MAX24287_BMCR_AN_EN                             0x1000
#define MAX24287_BMCR_AN_START                          0x0200
#define MAX24287_BMCR_COL_TEST                          0x0080

//Basic Mode Status register
#define MAX24287_BMSR_SPD100FD                          0x4000
#define MAX24287_BMSR_SPD100HD                          0x2000
#define MAX24287_BMSR_SPD10FD                           0x1000
#define MAX24287_BMSR_SPD10HD                           0x0800
#define MAX24287_BMSR_EXT_STAT                          0x0100
#define MAX24287_BMSR_MF_PRE                            0x0040
#define MAX24287_BMSR_AN_COMP                           0x0020
#define MAX24287_BMSR_RFAULT                            0x0010
#define MAX24287_BMSR_AN_ABIL                           0x0008
#define MAX24287_BMSR_LINK_ST                           0x0004
#define MAX24287_BMSR_EXT_CAP                           0x0001

//Device ID 1 register
#define MAX24287_ID1_OUI_HI                             0xFFFF

//Device ID 2 register
#define MAX24287_ID2_OUI_LI                             0xFC00
#define MAX24287_ID2_MODEL                              0x03F0
#define MAX24287_ID2_REV                                0x000F

//Auto-Negotiation Advertisement register (1000BASE-X)
#define MAX24287_AN_ADV_1000BTX_NP                      0x8000
#define MAX24287_AN_ADV_1000BTX_RF                      0x3000
#define MAX24287_AN_ADV_1000BTX_ZERO1                   0x0E00
#define MAX24287_AN_ADV_1000BTX_PS                      0x0180
#define MAX24287_AN_ADV_1000BTX_HD                      0x0040
#define MAX24287_AN_ADV_1000BTX_FD                      0x0020
#define MAX24287_AN_ADV_1000BTX_ZERO2                   0x001F

//Auto-Negotiation Advertisement register (SGMI)
#define MAX24287_AN_ADV_SGMI_LK                         0x8000
#define MAX24287_AN_ADV_SGMI_ZERO1                      0x2000
#define MAX24287_AN_ADV_SGMI_DPLX                       0x1000
#define MAX24287_AN_ADV_SGMI_SPD                        0x0C00
#define MAX24287_AN_ADV_SGMI_SPD_10MBPS                 0x0000
#define MAX24287_AN_ADV_SGMI_SPD_100MBPS                0x0400
#define MAX24287_AN_ADV_SGMI_SPD_1000MBPS               0x0800
#define MAX24287_AN_ADV_SGMI_ZERO2                      0x03FE
#define MAX24287_AN_ADV_SGMI_ONE                        0x0001

//Auto-Negotiation Link Partner Ability Receive register (1000BASE-X)
#define MAX24287_AN_RX_1000BTX_NP                       0x8000
#define MAX24287_AN_RX_1000BTX_ACK                      0x4000
#define MAX24287_AN_RX_1000BTX_RF                       0x3000
#define MAX24287_AN_RX_1000BTX_PS                       0x0180
#define MAX24287_AN_RX_1000BTX_HD                       0x0040
#define MAX24287_AN_RX_1000BTX_FD                       0x0020

//Auto-Negotiation Link Partner Ability Receive register (SGMI)
#define MAX24287_AN_RX_SGMI_LK                          0x8000
#define MAX24287_AN_RX_SGMI_DPLX                        0x1000
#define MAX24287_AN_RX_SGMI_SPD                         0x0C00
#define MAX24287_AN_RX_SGMI_SPD_10MBPS                  0x0000
#define MAX24287_AN_RX_SGMI_SPD_100MBPS                 0x0400
#define MAX24287_AN_RX_SGMI_SPD_1000MBPS                0x0800

//Auto-negotiation Extended Status register
#define MAX24287_AN_EXP_NP                              0x0004
#define MAX24287_AN_EXP_PAGE                            0x0002

//Extended Status register
#define MAX24287_EXT_STAT_1000X_FDX                     0x8000
#define MAX24287_EXT_STAT_1000X_HDX                     0x4000

//Page register
#define MAX24287_PAGESEL_TEST                           0x8000
#define MAX24287_PAGESEL_IR                             0x2000
#define MAX24287_PAGESEL_PAGE                           0x0003
#define MAX24287_PAGESEL_PAGE_0                         0x0000
#define MAX24287_PAGESEL_PAGE_1                         0x0001
#define MAX24287_PAGESEL_PAGE_2                         0x0002
#define MAX24287_PAGESEL_PAGE_3                         0x0003

//Jitter Diagnostics register
#define MAX24287_JIT_DIAG_JIT_EN                        0x8000
#define MAX24287_JIT_DIAG_JIT_PAT                       0x7000
#define MAX24287_JIT_DIAG_JIT_PAT_CUSTOM                0x0000
#define MAX24287_JIT_DIAG_JIT_PAT_HIGH_FREQ             0x1000
#define MAX24287_JIT_DIAG_JIT_PAT_MIXED_FREQ            0x2000
#define MAX24287_JIT_DIAG_JIT_PAT_LOW_FREQ              0x3000
#define MAX24287_JIT_DIAG_JIT_PAT_RANDOM                0x4000
#define MAX24287_JIT_DIAG_CUST_PAT                      0x03FF

//PCS Control register
#define MAX24287_PCSCR_TIM_SHRT                         0x4000
#define MAX24287_PCSCR_DYRX_DIS                         0x2000
#define MAX24287_PCSCR_DYTX_DIS                         0x1000
#define MAX24287_PCSCR_WD_DIS                           0x0040
#define MAX24287_PCSCR_BASEX                            0x0010
#define MAX24287_PCSCR_TLB                              0x0002
#define MAX24287_PCSCR_EN_CDET                          0x0001

//GMII Interface Control register
#define MAX24287_GMIICR_SPD                             0xC000
#define MAX24287_GMIICR_SPD_10MBPS                      0x0000
#define MAX24287_GMIICR_SPD_100MBPS                     0x4000
#define MAX24287_GMIICR_SPD_1000MBPS_GMII               0x8000
#define MAX24287_GMIICR_SPD_1000MBPS_TBI                0xC000
#define MAX24287_GMIICR_TBI_RATE                        0x2000
#define MAX24287_GMIICR_DTE_DCE                         0x1000
#define MAX24287_GMIICR_DDR                             0x0800
#define MAX24287_GMIICR_TXCLK_EN                        0x0400
#define MAX24287_GMIICR_REF_INV                         0x0008
#define MAX24287_GMIICR_RLB                             0x0001

//Control register
#define MAX24287_CR_DLBDO                               0x1000
#define MAX24287_CR_RLBDO                               0x0800
#define MAX24287_CR_TLBDO                               0x0400
#define MAX24287_CR_RCFREQ                              0x0200
#define MAX24287_CR_RCSQL                               0x0100
#define MAX24287_CR_TCLK_EN                             0x0020

//Interrupt register
#define MAX24287_IR_RFAULT_IE                           0x2000
#define MAX24287_IR_LINK_ST_IE                          0x1000
#define MAX24287_IR_ALOS_IE                             0x0800
#define MAX24287_IR_PAGE_IE                             0x0400
#define MAX24287_IR_RLOL_IE                             0x0200
#define MAX24287_IR_RLOS_IE                             0x0100
#define MAX24287_IR_RFAULT                              0x0020
#define MAX24287_IR_LINK_ST                             0x0010
#define MAX24287_IR_ALOS                                0x0008
#define MAX24287_IR_PAGE                                0x0004
#define MAX24287_IR_RLOL                                0x0002
#define MAX24287_IR_RLOS                                0x0001

//Device ID register
#define MAX24287_ID_REV                                 0xF000
#define MAX24287_ID_DEVICE                              0x0FFF

//GPIO Control 1 register
#define MAX24287_GPIOCR1_RST                            0x8000
#define MAX24287_GPIOCR1_GPO1_SEL                       0x7000
#define MAX24287_GPIOCR1_GPO1_SEL_HI_Z                  0x0000
#define MAX24287_GPIOCR1_GPO1_SEL_DRIVE_LOGIC_0         0x1000
#define MAX24287_GPIOCR1_GPO1_SEL_DRIVE_LOGIC_1         0x2000
#define MAX24287_GPIOCR1_GPO1_SEL_INT_OUT               0x3000
#define MAX24287_GPIOCR1_GPO1_SEL_OUT_125MHZ_TX_PLL     0x4000
#define MAX24287_GPIOCR1_GPO1_SEL_OUT_25_125MHZ_RX_PLL  0x5000
#define MAX24287_GPIOCR1_GPO1_SEL_OUT_LINK_STATUS       0x6000
#define MAX24287_GPIOCR1_GPO2_SEL                       0x0E00
#define MAX24287_GPIOCR1_GPO2_SEL_HI_Z                  0x0000
#define MAX24287_GPIOCR1_GPO2_SEL_DRIVE_LOGIC_0         0x0200
#define MAX24287_GPIOCR1_GPO2_SEL_DRIVE_LOGIC_1         0x0400
#define MAX24287_GPIOCR1_GPO2_SEL_OUT_125MHZ_TX_PLL     0x0800
#define MAX24287_GPIOCR1_GPO2_SEL_OUT_25_125MHZ_RX_PLL  0x0A00
#define MAX24287_GPIOCR1_GPO2_SEL_OUT_CRS               0x0C00
#define MAX24287_GPIOCR1_GPIO1_SEL                      0x01C0
#define MAX24287_GPIOCR1_GPIO1_SEL_HI_Z                 0x0000
#define MAX24287_GPIOCR1_GPIO1_SEL_DRIVE_LOGIC_0        0x0040
#define MAX24287_GPIOCR1_GPIO1_SEL_DRIVE_LOGIC_1        0x0080
#define MAX24287_GPIOCR1_GPIO1_SEL_INT_OUT              0x00C0
#define MAX24287_GPIOCR1_GPIO1_SEL_OUT_125MHZ_TX_PLL    0x0100
#define MAX24287_GPIOCR1_GPIO1_SEL_OUT_25_125MHZ_RX_PLL 0x0140
#define MAX24287_GPIOCR1_GPIO1_SEL_LINK_STATUS          0x0180
#define MAX24287_GPIOCR1_GPIO2_SEL                      0x0038
#define MAX24287_GPIOCR1_GPIO2_SEL_HI_Z                 0x0000
#define MAX24287_GPIOCR1_GPIO2_SEL_DRIVE_LOGIC_0        0x0008
#define MAX24287_GPIOCR1_GPIO2_SEL_DRIVE_LOGIC_1        0x0010
#define MAX24287_GPIOCR1_GPIO2_SEL_OUT_125MHZ_TX_PLL    0x0020
#define MAX24287_GPIOCR1_GPIO2_SEL_OUT_25_125MHZ_RX_PLL 0x0028
#define MAX24287_GPIOCR1_GPIO2_SEL_OUT_CRS              0x0030
#define MAX24287_GPIOCR1_GPIO3_SEL                      0x0007
#define MAX24287_GPIOCR1_GPIO3_SEL_HI_Z                 0x0000
#define MAX24287_GPIOCR1_GPIO3_SEL_DRIVE_LOGIC_0        0x0001
#define MAX24287_GPIOCR1_GPIO3_SEL_DRIVE_LOGIC_1        0x0002
#define MAX24287_GPIOCR1_GPIO3_SEL_INT_OUT              0x0003
#define MAX24287_GPIOCR1_GPIO3_SEL_OUT_125MHZ_TX_PLL    0x0004
#define MAX24287_GPIOCR1_GPIO3_SEL_OUT_25_125MHZ_RX_PLL 0x0005
#define MAX24287_GPIOCR1_GPIO3_SEL_LINK_STATUS          0x0006

//GPIO Control 2 register
#define MAX24287_GPIOCR2_GPIO47_LSC                     0x2000
#define MAX24287_GPIOCR2_GPIO13_LSC                     0x1000
#define MAX24287_GPIOCR2_GPIO7_SEL                      0x0E00
#define MAX24287_GPIOCR2_GPIO7_SEL_HI_Z                 0x0000
#define MAX24287_GPIOCR2_GPIO7_SEL_DRIVE_LOGIC_0        0x0200
#define MAX24287_GPIOCR2_GPIO7_SEL_DRIVE_LOGIC_1        0x0400
#define MAX24287_GPIOCR2_GPIO7_SEL_OUT_125MHZ_TX_PLL    0x0800
#define MAX24287_GPIOCR2_GPIO7_SEL_OUT_25_125MHZ_RX_PLL 0x0A00
#define MAX24287_GPIOCR2_GPIO6_SEL                      0x01C0
#define MAX24287_GPIOCR2_GPIO6_SEL_HI_Z                 0x0000
#define MAX24287_GPIOCR2_GPIO6_SEL_DRIVE_LOGIC_0        0x0040
#define MAX24287_GPIOCR2_GPIO6_SEL_DRIVE_LOGIC_1        0x0080
#define MAX24287_GPIOCR2_GPIO6_SEL_OUT_125MHZ_TX_PLL    0x0100
#define MAX24287_GPIOCR2_GPIO6_SEL_OUT_25_125MHZ_RX_PLL 0x0140
#define MAX24287_GPIOCR2_GPIO5_SEL                      0x0038
#define MAX24287_GPIOCR2_GPIO5_SEL_HI_Z                 0x0000
#define MAX24287_GPIOCR2_GPIO5_SEL_DRIVE_LOGIC_0        0x0008
#define MAX24287_GPIOCR2_GPIO5_SEL_DRIVE_LOGIC_1        0x0010
#define MAX24287_GPIOCR2_GPIO5_SEL_OUT_125MHZ_TX_PLL    0x0020
#define MAX24287_GPIOCR2_GPIO5_SEL_OUT_25_125MHZ_RX_PLL 0x0028
#define MAX24287_GPIOCR2_GPIO4_SEL                      0x0007
#define MAX24287_GPIOCR2_GPIO4_SEL_HI_Z                 0x0000
#define MAX24287_GPIOCR2_GPIO4_SEL_DRIVE_LOGIC_0        0x0001
#define MAX24287_GPIOCR2_GPIO4_SEL_DRIVE_LOGIC_1        0x0002
#define MAX24287_GPIOCR2_GPIO4_SEL_OUT_125MHZ_TX_PLL    0x0004
#define MAX24287_GPIOCR2_GPIO4_SEL_OUT_25_125MHZ_RX_PLL 0x0005

//GPIO Status register
#define MAX24287_GPIOSR_GPIO7L                          0x4000
#define MAX24287_GPIOSR_GPIO6L                          0x2000
#define MAX24287_GPIOSR_GPIO5L                          0x1000
#define MAX24287_GPIOSR_GPIO4L                          0x0800
#define MAX24287_GPIOSR_GPIO3L                          0x0400
#define MAX24287_GPIOSR_GPIO2L                          0x0200
#define MAX24287_GPIOSR_GPIO1L                          0x0100
#define MAX24287_GPIOSR_GPIO7                           0x0040
#define MAX24287_GPIOSR_GPIO6                           0x0020
#define MAX24287_GPIOSR_GPIO5                           0x0010
#define MAX24287_GPIOSR_GPIO4                           0x0008
#define MAX24287_GPIOSR_GPIO3                           0x0004
#define MAX24287_GPIOSR_GPIO2                           0x0002
#define MAX24287_GPIOSR_GPIO1                           0x0001

//PTP Control register
#define MAX24287_PTPCR1_PLL_PWDN                        0x0020
#define MAX24287_PTPCR1_TX_PWDN                         0x0008
#define MAX24287_PTPCR1_RX_PWDN                         0x0004

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//MAX24287 Ethernet PHY driver
extern const PhyDriver max24287PhyDriver;

//MAX24287 related functions
error_t max24287Init(NetInterface *interface);
void max24287InitHook(NetInterface *interface);

void max24287Tick(NetInterface *interface);

void max24287EnableIrq(NetInterface *interface);
void max24287DisableIrq(NetInterface *interface);

void max24287EventHandler(NetInterface *interface);

void max24287WritePhyReg(NetInterface *interface, uint8_t address,
   uint16_t data);

uint16_t max24287ReadPhyReg(NetInterface *interface, uint8_t address);

void max24287DumpPhyReg(NetInterface *interface);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
