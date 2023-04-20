/*
 * Copyright (c) 2015 - 2016 , Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "clockMan1.h"
#include "pin_mux.h"
#include "Send.h"
#include "Receive.h"
#include "adConv1.h"
#include "PWM.h"
#include "osif1.h"
#include "dmaController1.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
#define BUFFER_SIZE 4U
#define TIMEOUT 100U

#define PTB2  2         /* Port PTD0, bit 0: FRDM EVB output to blue LED */
#define PTB3  3         /* Port PTD0, bit 0: FRDM EVB output to blue LED */
#define PTB4  4         /* Port PTD0, bit 0: FRDM EVB output to blue LED */
#define PTB5  5         /* Port PTD0, bit 0: FRDM EVB output to blue LED */

volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */

#include <stdint.h>
#include <stdbool.h>

uint8_t masterDataReceive[BUFFER_SIZE];
lpspi_state_t masterState;
status_t sts;

// Pressure measured by the HDIB002AUY8P5 sensor through I2C communication in milibars.
	float pressure_hdi_spi;

	  // Number of counts read by the sensor
	  	uint16_t counts_hdtm;
	  	uint16_t counts_hdtm_aux;


void WDOG_disable (void){
	  	  WDOG->CNT=0xD928C520;     /*Unlock watchdog*/
	  	  WDOG->TOVAL=0x0000FFFF;   /*Maximum timeout value*/
	  	  WDOG->CS = 0x00002100;    /*Disable watchdog*/
}

void PORT_init_GPIO (void) {
  PCC->PCCn[PCC_PORTB_INDEX ]|=PCC_PCCn_CGC_MASK; /* Enable clock for PORTB */

  PTB->PDDR |= 1<<PTB2;        /* Port B2: Data Direction= output */
  PORTB->PCR[2] = 0x00000100;  /* Port B2: MUX = GPIO */

  PTB->PDDR |= 1<<PTB3;        /* Port B2: Data Direction= output */
  PORTB->PCR[3] = 0x00000100;  /* Port B2: MUX = GPIO */

  PTB->PDDR |= 1<<PTB4;        /* Port B2: Data Direction= output */
  PORTB->PCR[4] = 0x00000100;  /* Port B2: MUX = GPIO */

  PTB->PDDR |= 1<<PTB5;        /* Port B2: Data Direction= output */
  PORTB->PCR[5] = 0x00000100;  /* Port B2: MUX = GPIO */

}

void PORT_init_SPI (void) {
  PCC->PCCn[PCC_PORTB_INDEX ]|=PCC_PCCn_CGC_MASK; /* Enable clock for PORTB */
  PORTB->PCR[2]|=PORT_PCR_MUX(3); /* Port B14: MUX = ALT3, LPSPI1_SCK */
  PORTB->PCR[3]|=PORT_PCR_MUX(3); /* Port B15: MUX = ALT3, LPSPI1_SIN */
  PORTB->PCR[4]|=PORT_PCR_MUX(3); /* Port B16: MUX = ALT3, LPSPI1_SOUT */
 // PORTB->PCR[5]|=PORT_PCR_MUX(3); /* Port B17: MUX = ALT3, LPSPI1_PCS3 */
}



void delay(volatile int cycles)
{
    /* Delay function - do nothing for a number of cycles */
    while(cycles--);
}

float pressure_calc (volatile int sensor, uint16_t counts)
{
	//Pressure range
	uint64_t Pmax; //mbar
	uint64_t Pmin;

	//Digital range
	uint64_t Out_max_d;
	uint64_t Out_min_d;

	switch (sensor)
	{
	// Parameters to compute the actual pressure based on the number of counts
	case 1: // HDI

	  //Pressure range
	  Pmax = 2000; //mbar
	  Pmin = 0;

	  //Digital range
	  Out_max_d = 29490;
	  Out_min_d = 3277;

	  break;

	case 2: // htd
		  //Pressure range
		  Pmax = 100; //mbar
		  Pmin = 0;

		  //Digital range
		  Out_max_d = 29491;
		  Out_min_d = 3277;

	break;

	}
	float S;
	float P;
	S = (Out_max_d - Out_min_d)/(Pmax-Pmin);
	P = (counts - Out_min_d)/S + Pmin;
	return P;
}


/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - __start (startup asm routine)
 * - __init_hardware()
 * - main()
 *   - PE_low_level_init()
 *     - Common_Init()
 *     - Peripherals_Init()
*/
int main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                 /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

    ftm_state_t ftmStateStruct;
    uint8_t masterDataSend[BUFFER_SIZE];


    WDOG_disable();

  /* Initialize pins
   *    -   See PinSettings component for more info
   */


    /* Initialize and configure clocks
     *     -   see clock manager component for details
     */
     CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
                           g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
     CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

     LPSPI_DRV_MasterDeinit(0U);

     delay(500000);

  //  PORT_init_GPIO();

     bool status = 1;

   //  PINS_DRV_WritePin(PTB,PTB2,status);
    // PINS_DRV_WritePin(PTB,PTB3,status);
  //   PINS_DRV_WritePin(PTB,PTB4,status);

     PTB->PDDR |= 1<<PTB5;        /* Port B2: Data Direction= output */
     PORTB->PCR[5] = 0x00000100;  /* Port B2: MUX = GPIO */

PINS_DRV_WritePin(PTB,PTB5,status);



  /* Initialize LPSPI0 (Send)*/

  //LPSPI0->CR = 0x00000000; /* Disable module for configuration */


  delay(5000000);


  lpspi_master_config_t MasterConfigSPI = {
 .bitsPerSec = 100000U,
 .whichPcs = LPSPI_PCS0,
 .pcsPolarity = LPSPI_ACTIVE_LOW,
 .isPcsContinuous = true,
 .bitcount = 8U,
 .lpspiSrcClk = 8000000U, //48000000U,
 .clkPhase = LPSPI_CLOCK_PHASE_1ST_EDGE,
 .clkPolarity = LPSPI_SCK_ACTIVE_HIGH,
 .lsbFirst = false,
 .transferType = LPSPI_USING_INTERRUPTS,
  };



  PORT_init_SPI();


  /* Initialize LPSPI0 (Send)*/
  LPSPI_DRV_MasterInit(0U, &masterState, &MasterConfigSPI);

//LPSPI_DRV_MasterSetDelay (0U,2,2,2); // for 4 bytes
 // LPSPI_DRV_MasterSetDelay (0U,3,2,3);
  // status_t LPSPI_DRV_MasterSetDelay ( uint32_t instance, uint32_t delayBetwenTransfers, uint32_t delaySCKtoPCS,
 //  uint32_t delayPCStoSCK
// LPSPI_DRV_MasterSetDelay(0U, 10U, 1U, 1U);

  /* Variable used for the loop that initializes the data buffer */
  uint16_t i;

  for (i = 0u; i < BUFFER_SIZE; i++)
  {
	  masterDataSend[i] = 0u;
	  masterDataReceive[i] = 0u;
  }



  while(1)
  {
          /* Store the channel result into a local variable slaveDataSend*/
	 PINS_DRV_WritePin(PTB,PTB5,0);
     sts=  LPSPI_DRV_MasterTransferBlocking(0U, &masterDataSend, &masterDataReceive, BUFFER_SIZE, TIMEOUT);
	  //LPSPI_DRV_MasterTransfer(0U, &masterDataSend, &masterDataReceive, BUFFER_SIZE);
    // LPSPI_DRV_MasterTransferBlocking(0U, &masterDataSend, &masterDataReceive, BUFFER_SIZE, TIMEOUT);
     PINS_DRV_WritePin(PTB,PTB5,1);
	  delay(50000);



          // Compute the pressure based on the number of counts read
         // masterDataReceive[1] = (masterDataReceive[1] & 0x01111111);
          counts_hdtm = (masterDataReceive[1] <<8)|masterDataReceive[0];
          counts_hdtm_aux = (counts_hdtm & 0x7FFF);

          pressure_hdi_spi = pressure_calc (2, counts_hdtm_aux);

          for (i = 0u; i < BUFFER_SIZE; i++)
        	  {
        		  masterDataReceive[i] = 0u;
        	  }


  }
  /* Write your code here */
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;) {
    if(exit_code != 0) {
      break;
    }
  }
  return exit_code;
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.1 [05.21]
**     for the Freescale S32K series of microcontrollers.
**
** ###################################################################
*/
