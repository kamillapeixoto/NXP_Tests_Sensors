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
#define BUFFER_SIZE 1U
#define TIMEOUT 10U
volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */

#include <stdint.h>
#include <stdbool.h>

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
    uint8_t masterDataSend;
    uint8_t masterDataReceive;
    lpspi_state_t masterState;
    uint8_t slaveDataReceive;
    uint16_t adcRead;
    uint8_t slaveDataSend;
    lpspi_state_t slaveState;
 /* Initialize and configure clocks
  *     -   see clock manager component for details
  */
  CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
                        g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
  CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

  /* Initialize pins
   *    -   See PinSettings component for more info
   */

  /* Example Description
   * Potentiometer voltage is read using ADC0- channel 12. The value is send to
   * LPSPI1 from LPSPI0. The read value represent duty for PWM (FTM0-channel 0).
   * SPI wiring:
   * B0-D3
   * B2-D0
   * E1-D2
   * B4-D1
   */
  PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);
  /* Initialize LPSPI0 (Send)*/
  LPSPI_DRV_MasterInit(SEND, &masterState, &Send_MasterConfig0);
  /* Initialize LPSPI1 (Receive)*/
  LPSPI_DRV_SlaveInit(RECEIVE, &slaveState, &Receive_SlaveConfig0);
  /* Initialize ADC */
  ADC_DRV_ConfigConverter(INST_ADCONV1, &adConv1_ConvConfig0);
  /* Initialize FTM */
  FTM_DRV_Init(INST_PWM, &PWM_InitConfig, &ftmStateStruct);
  FTM_DRV_InitPwm(INST_PWM, &PWM_PwmConfig);

  while(1)
  {
          ADC_DRV_ConfigChan(INST_ADCONV1, 0U, &adConv1_ChnConfig0);
          ADC_DRV_WaitConvDone(INST_ADCONV1);
          /* Store the channel result into a local variable slaveDataSend*/
          ADC_DRV_GetChanResult(INST_ADCONV1, 0U, &adcRead);
          slaveDataSend = (uint8_t)adcRead;
          LPSPI_DRV_SlaveTransfer(RECEIVE, &slaveDataSend, &slaveDataReceive, BUFFER_SIZE);
          LPSPI_DRV_MasterTransferBlocking(SEND, &masterDataSend, &masterDataReceive, BUFFER_SIZE, TIMEOUT);
          FTM_DRV_UpdatePwmChannel(INST_PWM, 0U, FTM_PWM_UPDATE_IN_DUTY_CYCLE, masterDataReceive<<8, 0U, true);

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