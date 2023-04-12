/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pressure_SPI.c
 *
 * Code generated for Simulink model 'Pressure_SPI'.
 *
 * Model version                  : 1.119
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Apr  5 11:08:09 2023
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Pressure_SPI.h"
#include "rtwtypes.h"
#include "Pressure_SPI_private.h"
#include <math.h>

lpspi_state_t lpspiMasterState0;
void lpspi_master_transfer_callback0(void *driverState, spi_event_t event, void *
  userData) __attribute__((weak));

/* Exported block states */
uint32_T pressure_analog;              /* '<Root>/Data Store Memory' */
uint16_T pressure_digital;             /* '<Root>/Data Store Memory3' */

/* Block signals (default storage) */
B_Pressure_SPI_T Pressure_SPI_B;

/* Real-time model */
static RT_MODEL_Pressure_SPI_T Pressure_SPI_M_;
RT_MODEL_Pressure_SPI_T *const Pressure_SPI_M = &Pressure_SPI_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void Pressure_SPI_step(void)
{
  real_T tmp;
  int32_T k;
  int32_T u_bin_mat_tmp;
  uint32_T qY;
  uint16_T y;
  uint8_T u_bin_mat[16];
  uint8_T intInput_idx_0;
  uint8_T intInput_idx_1;

  /* S-Function (adc_s32k_start): '<Root>/ADC_Start' */
  {
    adc_chan_config_t adc0_chan_cfg = {
      .interruptEnable = false,
      .channel = ADC_INPUTCHAN_EXT10
    };

    /* Initialize channel configuration of ADC0. */
    ADC_DRV_ConfigChan(0, 0, &adc0_chan_cfg);
    uint16_t result;

    /* Get conversion result of ADC0 */
    ADC_DRV_WaitConvDone(0);
    ADC_DRV_GetChanResult(0, 0, &result);
    Pressure_SPI_B.ADC_Start = result;
  }

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write'
   */
  tmp = rt_roundd_snf((real_T)Pressure_SPI_B.ADC_Start - 409.6);
  if (tmp >= 0.0) {
    qY = (uint32_T)tmp;
  } else {
    qY = 0U;
  }

  pressure_analog = (uint32_T)rt_roundd_snf((real_T)qY / 32.768);

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */

  /* S-Function (lpspi_s32k_master_transfer): '<Root>/LPSPI_Master_Transfer' incorporates:
   *  Constant: '<Root>/Constant'
   */
  {
    /* Update the peripheral CS to select the slave you want to send data to */
    LPSPI_DRV_SetPcs(0, LPSPI_PCS0, LPSPI_ACTIVE_LOW);

    /* Send data */
    LPSPI_DRV_MasterTransfer(0, Pressure_SPI_ConstP.Constant_Value,
      &Pressure_SPI_B.LPSPI_Master_Transfer[0], 2);
  }

  /* MATLAB Function: '<Root>/MATLAB Function' */
  intInput_idx_0 = Pressure_SPI_B.LPSPI_Master_Transfer[1];
  intInput_idx_1 = Pressure_SPI_B.LPSPI_Master_Transfer[0];
  for (k = 0; k < 8; k++) {
    u_bin_mat_tmp = (uint8_T)(1 << k);
    u_bin_mat[7 - k] = (uint8_T)((u_bin_mat_tmp & intInput_idx_0) != 0);
    u_bin_mat[15 - k] = (uint8_T)((u_bin_mat_tmp & intInput_idx_1) != 0);
  }

  for (k = 0; k < 15; k++) {
    if ((uint16_T)((uint16_T)-k + 14U) > 15) {
      y = MAX_uint16_T;
    } else {
      y = (uint16_T)(1 << (uint16_T)((uint16_T)-k + 14U));
    }

    qY = (uint32_T)u_bin_mat[k + 1] * y;
    if (qY > 65535U) {
      qY = 65535U;
    }

    Pressure_SPI_B.b_y[k] = (uint16_T)qY;
  }

  y = Pressure_SPI_B.b_y[0];
  for (k = 0; k < 14; k++) {
    qY = (uint32_T)Pressure_SPI_B.b_y[k + 1] + y;
    if (qY > 65535U) {
      qY = 65535U;
    }

    y = (uint16_T)qY;
  }

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write4'
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  qY = y - 3277U;
  if (y - 3277U > y) {
    qY = 0U;
  }

  pressure_digital = (uint16_T)rt_roundd_snf((real_T)(int32_T)qY / 262.14);

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */

  /* Gain: '<Root>/Gain' */
  Pressure_SPI_B.Gain = 0.000244140625F * (real32_T)Pressure_SPI_B.ADC_Start;

  /* S-Function (ftm_s32k_pwm_config): '<Root>/FTM_PWM_Config' */
  {
    uint16_t dutyA = FTM_MAX_DUTY_CYCLE * Pressure_SPI_B.Gain;
    FTM_DRV_UpdatePwmChannel(FTM_PWM0, 0U, FTM_PWM_UPDATE_IN_DUTY_CYCLE, dutyA,
      0, true);
  }
}

/* Model initialize function */
void Pressure_SPI_initialize(void)
{
  /* Start for S-Function (ftm_s32k_pwm_config): '<Root>/FTM_PWM_Config' */

  /* Enable clock for PORTD */
  PCC_SetClockMode (PCC, PCC_PORTD_CLOCK, true);

  /* Pin is configured for FTM function */
  PINS_SetMuxModeSel (PORTD, 15, PORT_MUX_ALT2);

  /* Set FTM_0 clock source */
  PCC_SetPeripheralClockControl (PCC, FTM0_CLK, true, CLK_SRC_SPLL, 0, 0);

  /* Enable clock for FTM_0 */
  PCC_SetClockMode (PCC, FTM0_CLK, true);

  /* PWM0 initialization */
  FTM_DRV_Init (FTM_PWM0, &flexTimer_pwm0_InitConfig, &ftmStateStruct0);
  FTM_DRV_InitPwm (FTM_PWM0, &flexTimer_pwm0_PwmConfig);
  FTM_DRV_SetChnTriggerCmd(FTM0, 1, false);

  /* Start for S-Function (adc_s32k_config): '<Root>/ADC_Config' */
  {
    const adc_converter_config_t adc0_cfg = {
      .clockDivide = ADC_CLK_DIVIDE_1,
      .sampleTime = 1.0,
      .resolution = ADC_RESOLUTION_12BIT,
      .inputClock = ADC_CLK_ALT_1,
      .trigger = ADC_TRIGGER_SOFTWARE,
      .pretriggerSel = ADC_PRETRIGGER_SEL_PDB,
      .triggerSel = ADC_TRIGGER_SEL_TRGMUX,
      .dmaEnable = false,
      .voltageRef = ADC_VOLTAGEREF_VREF,
      .continuousConvEnable = false,
      .supplyMonitoringEnable = false
    };

    const adc_compare_config_t adc0_cmp_cfg = {
      .compareEnable = false,
      .compareGreaterThanEnable = false,
      .compareRangeFuncEnable = false,
      .compVal1 = 0,
      .compVal2 = 0
    };

    const adc_average_config_t adc0_avrg_cfg = {
      .hwAvgEnable = false,
      .hwAverage = ADC_AVERAGE_4
    };

    /* Enable ADC0 clock */
    PCC_SetClockMode(PCC, PCC_ADC0_CLOCK, false);

    /* Set ADC0 clock source */
    PCC_SetPeripheralClockControl(PCC, PCC_ADC0_CLOCK, true, CLK_SRC_SPLL, 0, 0);

    /* Enable ADC0 clock */
    PCC_SetClockMode(PCC, PCC_ADC0_CLOCK, true);
    ADC_DRV_Reset(0);

    /* Configure ADC0 */
    ADC_DRV_ConfigConverter(0, &adc0_cfg);
    ADC_DRV_SetSwPretrigger(0,ADC_SW_PRETRIGGER_DISABLED);
    ADC_DRV_ConfigHwCompare(0, &adc0_cmp_cfg);
    ADC_DRV_ConfigHwAverage(0, &adc0_avrg_cfg);

    /* Do calibration before initialize the ADC0. */
    ADC_DRV_AutoCalibration(0);
  }

  /* Start for S-Function (fm_s32k_config): '<Root>/FreeMaster_Config' */

  /* Initialize FreeMaster. */
  freemaster_interface_init();
  FMSTR_Init();

  /* Start for S-Function (lpspi_s32k_config): '<Root>/LPSPI_Config ' */
  {
    /* Enable LPSPI clock */
    PCC_SetPeripheralClockControl(PCC, LPSPI0_CLK, true, CLK_SRC_FIRC_DIV2,
      DIVIDE_BY_ONE, MULTIPLY_BY_ONE);

    /* Enable clock for PORTB */
    PCC_SetPeripheralClockControl(PCC, PORTB_CLK, true, CLK_SRC_OFF,
      DIVIDE_BY_ONE, MULTIPLY_BY_ONE);

    /* Enable clock for PORTB */
    PCC_SetPeripheralClockControl(PCC, PORTB_CLK, true, CLK_SRC_OFF,
      DIVIDE_BY_ONE, MULTIPLY_BY_ONE);

    /* Enable clock for PORTB */
    PCC_SetPeripheralClockControl(PCC, PORTB_CLK, true, CLK_SRC_OFF,
      DIVIDE_BY_ONE, MULTIPLY_BY_ONE);

    /* PCS0! Enable clock for PORTB */
    PCC_SetPeripheralClockControl(PCC, PORTB_CLK, true, CLK_SRC_OFF,
      DIVIDE_BY_ONE, MULTIPLY_BY_ONE);

    /* Setup SPI pins */
    pin_settings_config_t spi_pin_mux[4U]= {
      {
        /* SIN pin */
        .base = PORTB,
        .pinPortIdx = 3,
        .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
        .passiveFilter = false,
        .driveSelect = PORT_LOW_DRIVE_STRENGTH,
        .mux = PORT_MUX_ALT3,
        .pinLock = false,
        .intConfig = PORT_DMA_INT_DISABLED,
        .clearIntFlag = false,
      },

      {
        /* SOUT pin */
        .base = PORTB,
        .pinPortIdx = 4,
        .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
        .passiveFilter = false,
        .driveSelect = PORT_LOW_DRIVE_STRENGTH,
        .mux = PORT_MUX_ALT3,
        .pinLock = false,
        .intConfig = PORT_DMA_INT_DISABLED,
        .clearIntFlag = false,
      },

      {
        /* SCK pin */
        .base = PORTB,
        .pinPortIdx = 2,
        .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
        .passiveFilter = false,
        .driveSelect = PORT_LOW_DRIVE_STRENGTH,
        .mux = PORT_MUX_ALT3,
        .pinLock = false,
        .intConfig = PORT_DMA_INT_DISABLED,
        .clearIntFlag = false,
      },

      {
        /* PCS0 pin */
        .base = PORTB,
        .pinPortIdx = 5,
        .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
        .passiveFilter = false,
        .driveSelect = PORT_LOW_DRIVE_STRENGTH,
        .mux = PORT_MUX_ALT4,
        .pinLock = false,
        .intConfig = PORT_DMA_INT_DISABLED,
        .clearIntFlag = false,
      },
    };

    PINS_DRV_Init(4U, spi_pin_mux);
  }

  {
    /* Configure the SPI init structure. */
    lpspi_master_config_t spiConfig0 = {
      .bitsPerSec = 300000U,
      .whichPcs = LPSPI_PCS0,
      .pcsPolarity = LPSPI_ACTIVE_LOW,
      .isPcsContinuous = true,
      .bitcount = 8U,
      .clkPhase = LPSPI_CLOCK_PHASE_1ST_EDGE,
      .clkPolarity = LPSPI_SCK_ACTIVE_HIGH,
      .lsbFirst = false,
      .transferType = LPSPI_USING_INTERRUPTS,
      .callback = (spi_callback_t)lpspi_master_transfer_callback0,
    };

    /* Module source clock */
    uint32_t frequency;
    CLOCK_SYS_GetFreq(LPSPI0_CLK, &frequency);
    spiConfig0.lpspiSrcClk = frequency;

    /* Initializes a LPSPI instance for interrupt driven master mode operation */
    LPSPI_DRV_MasterInit(0, &lpspiMasterState0, &spiConfig0);
  }
}

/* Model terminate function */
void Pressure_SPI_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
