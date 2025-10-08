/**
 * @file max24287_driver.c
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

//Switch to the appropriate trace level
#define TRACE_LEVEL NIC_TRACE_LEVEL

//Dependencies
#include "core/net.h"
#include "drivers/phy/max24287_driver.h"
#include "debug.h"


/**
 * @brief MAX24287 Ethernet PHY driver
 **/

const PhyDriver max24287PhyDriver =
{
   max24287Init,
   max24287Tick,
   max24287EnableIrq,
   max24287DisableIrq,
   max24287EventHandler
};


/**
 * @brief MAX24287 PHY transceiver initialization
 * @param[in] interface Underlying network interface
 * @return Error code
 **/

error_t max24287Init(NetInterface *interface)
{
   //Debug message
   TRACE_INFO("Initializing MAX24287...\r\n");

   //Undefined PHY address?
   if(interface->phyAddr >= 32)
   {
      //Use the default address
      interface->phyAddr = MAX24287_PHY_ADDR;
   }

   //Initialize serial management interface
   if(interface->smiDriver != NULL)
   {
      interface->smiDriver->init();
   }

   //Reset PHY transceiver
   max24287WritePhyReg(interface, MAX24287_BMCR, MAX24287_BMCR_DP_RST);

   //Wait for the reset to complete
   while(max24287ReadPhyReg(interface, MAX24287_BMCR) & MAX24287_BMCR_DP_RST)
   {
   }

   //Dump PHY registers for debugging purpose
   max24287DumpPhyReg(interface);

   //Perform custom configuration
   max24287InitHook(interface);

   //Force the TCP/IP stack to poll the link state at startup
   interface->phyEvent = TRUE;
   //Notify the TCP/IP stack of the event
   osSetEvent(&netEvent);

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief MAX24287 custom configuration
 * @param[in] interface Underlying network interface
 **/

__weak_func void max24287InitHook(NetInterface *interface)
{
}


/**
 * @brief MAX24287 timer handler
 * @param[in] interface Underlying network interface
 **/

void max24287Tick(NetInterface *interface)
{
   uint16_t value;
   bool_t linkState;

   //Read basic status register
   value = max24287ReadPhyReg(interface, MAX24287_BMSR);
   //Retrieve current link state
   linkState = (value & MAX24287_BMSR_LINK_ST) ? TRUE : FALSE;

   //Link up event?
   if(linkState && !interface->linkState)
   {
      //Set event flag
      interface->phyEvent = TRUE;
      //Notify the TCP/IP stack of the event
      osSetEvent(&netEvent);
   }
   //Link down event?
   else if(!linkState && interface->linkState)
   {
      //Set event flag
      interface->phyEvent = TRUE;
      //Notify the TCP/IP stack of the event
      osSetEvent(&netEvent);
   }
}


/**
 * @brief Enable interrupts
 * @param[in] interface Underlying network interface
 **/

void max24287EnableIrq(NetInterface *interface)
{
}


/**
 * @brief Disable interrupts
 * @param[in] interface Underlying network interface
 **/

void max24287DisableIrq(NetInterface *interface)
{
}


/**
 * @brief MAX24287 event handler
 * @param[in] interface Underlying network interface
 **/

void max24287EventHandler(NetInterface *interface)
{
   uint16_t status;

   //Read basic status register
   status = max24287ReadPhyReg(interface, MAX24287_BMSR);

   //Link is up?
   if((status & MAX24287_BMSR_LINK_ST) != 0)
   {
      //Check current speed
      if(...)
      {
         interface->linkSpeed = NIC_LINK_SPEED_10MBPS;
      }
      else if(...)
      {
         interface->linkSpeed = NIC_LINK_SPEED_100MBPS;
      }
      else if(...)
      {
         interface->linkSpeed = NIC_LINK_SPEED_1GBPS;
      }
      else
      {
         //Debug message
         TRACE_WARNING("Invalid speed\r\n");
      }

      //Check current duplex mode
      if(...)
      {
         interface->duplexMode = NIC_FULL_DUPLEX_MODE;
      }
      else
      {
         interface->duplexMode = NIC_HALF_DUPLEX_MODE;
      }

      //Update link state
      interface->linkState = TRUE;

      //Adjust MAC configuration parameters for proper operation
      interface->nicDriver->updateMacConfig(interface);
   }
   else
   {
      //Update link state
      interface->linkState = FALSE;
   }

   //Process link state change event
   nicNotifyLinkChange(interface);
}


/**
 * @brief Write PHY register
 * @param[in] interface Underlying network interface
 * @param[in] address PHY register address
 * @param[in] data Register value
 **/

void max24287WritePhyReg(NetInterface *interface, uint8_t address,
   uint16_t data)
{
   //Write the specified PHY register
   if(interface->smiDriver != NULL)
   {
      interface->smiDriver->writePhyReg(SMI_OPCODE_WRITE,
         interface->phyAddr, address, data);
   }
   else
   {
      interface->nicDriver->writePhyReg(SMI_OPCODE_WRITE,
         interface->phyAddr, address, data);
   }
}


/**
 * @brief Read PHY register
 * @param[in] interface Underlying network interface
 * @param[in] address PHY register address
 * @return Register value
 **/

uint16_t max24287ReadPhyReg(NetInterface *interface, uint8_t address)
{
   uint16_t data;

   //Read the specified PHY register
   if(interface->smiDriver != NULL)
   {
      data = interface->smiDriver->readPhyReg(SMI_OPCODE_READ,
         interface->phyAddr, address);
   }
   else
   {
      data = interface->nicDriver->readPhyReg(SMI_OPCODE_READ,
         interface->phyAddr, address);
   }

   //Return the value of the PHY register
   return data;
}


/**
 * @brief Dump PHY registers for debugging purpose
 * @param[in] interface Underlying network interface
 **/

void max24287DumpPhyReg(NetInterface *interface)
{
   uint8_t i;

   //Loop through PHY registers
   for(i = 0; i < 32; i++)
   {
      //Display current PHY register
      TRACE_DEBUG("%02" PRIu8 ": 0x%04" PRIX16 "\r\n", i,
         max24287ReadPhyReg(interface, i));
   }

   //Terminate with a line feed
   TRACE_DEBUG("\r\n");
}
