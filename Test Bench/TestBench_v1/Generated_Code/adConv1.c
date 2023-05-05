/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : adConv1.c
**     Project     : TestBench_v1
**     Processor   : S32K144_100
**     Component   : adc
**     Version     : Component SDK_S32K14x_07, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K14x_07
**     Compiler    : GNU C Compiler
**     Date/Time   : 2023-05-04, 14:54, # CodeGen: 2
**
**     Copyright 1997 - 2015 Freescale Semiconductor, Inc.
**     Copyright 2016-2017 NXP
**     All Rights Reserved.
**     
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file adConv1.c
** @version 01.00
*/
/*!
**  @addtogroup adConv1_module adConv1 module documentation
**  @{
*/

/* MODULE adConv1. */

#include "adConv1.h"

/*! adConv1 configuration structure */
const adc_converter_config_t adConv1_ConvConfig1 = {
  .clockDivide = ADC_CLK_DIVIDE_1,
  .sampleTime = 12U,
  .resolution = ADC_RESOLUTION_8BIT,
  .inputClock = ADC_CLK_ALT_1,
  .trigger = ADC_TRIGGER_SOFTWARE,
  .pretriggerSel = ADC_PRETRIGGER_SEL_PDB,
  .triggerSel = ADC_TRIGGER_SEL_PDB,
  .dmaEnable = false,
  .voltageRef = ADC_VOLTAGEREF_VREF,
  .continuousConvEnable = false,
};

adc_chan_config_t adConv1_ChnConfig0 = {
  .interruptEnable = false,
  .channel = ADC_INPUTCHAN_EXT12,
};

adc_chan_config_t adConv1_ChnConfig1 = {
  .interruptEnable = false,
  .channel = ADC_INPUTCHAN_VREFSL,
};

const adc_compare_config_t adConv1_HwCompConfig0 = {
  .compareEnable = false,
  .compareGreaterThanEnable = false,
  .compareRangeFuncEnable = false,
  .compVal1 = 0U,
  .compVal2 = 0U,
};

const adc_average_config_t adConv1_HwAvgConfig0 = {
  .hwAvgEnable = false,
  .hwAverage = ADC_AVERAGE_4,
};


/* END adConv1. */
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

