/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pressure_I2C.c
 *
 * Code generated for Simulink model 'Pressure_I2C'.
 *
 * Model version                  : 1.146
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Mar 29 16:28:58 2023
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Pressure_I2C.h"
#include "rtwtypes.h"
#include "Pressure_I2C_private.h"
#include <math.h>

lpi2c_master_state_t lpi2cMasterState0;
void lpi2c_MasterCallback(i2c_master_event_t masterEvent, void *userData)
  __attribute__((weak));

/* Exported block states */
uint32_T pressure_analog;              /* '<Root>/Data Store Memory' */
uint16_T pressure_digital;             /* '<Root>/Data Store Memory3' */

/* Block signals (default storage) */
B_Pressure_I2C_T Pressure_I2C_B;

/* Real-time model */
static RT_MODEL_Pressure_I2C_T Pressure_I2C_M_;
RT_MODEL_Pressure_I2C_T *const Pressure_I2C_M = &Pressure_I2C_M_;
void LPI2C_DRV_SetSlaveAddr(uint16_t addr, bool is10BitAddr)
{
  LPI2C_Type *baseAddr = LPI2C0;
  LPI2C_Set_SlaveAddr0(baseAddr, addr);
  if (is10BitAddr) {
    LPI2C_Set_SlaveAddrConfig(baseAddr, LPI2C_SLAVE_ADDR_MATCH_0_10BIT);
  } else {
    LPI2C_Set_SlaveAddrConfig(baseAddr, LPI2C_SLAVE_ADDR_MATCH_0_7BIT);
  }
}

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
void Pressure_I2C_step(void)
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
      .channel = ADC_INPUTCHAN_EXT9
    };

    /* Initialize channel configuration of ADC0. */
    ADC_DRV_ConfigChan(0, 0, &adc0_chan_cfg);
    uint16_t result;

    /* Get conversion result of ADC0 */
    ADC_DRV_WaitConvDone(0);
    ADC_DRV_GetChanResult(0, 0, &result);
    Pressure_I2C_B.ADC_Start = result;
  }

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write'
   */
  tmp = rt_roundd_snf((real_T)Pressure_I2C_B.ADC_Start - 409.6);
  if (tmp >= 0.0) {
    qY = (uint32_T)tmp;
  } else {
    qY = 0U;
  }

  pressure_analog = (uint32_T)rt_roundd_snf((real_T)qY / 1.6384);

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */

  /* S-Function (lpi2c_s32k_master_receive): '<Root>/LPI2C_Master_Receive1' incorporates:
   *  Constant: '<Root>/Constant10'
   *  Constant: '<Root>/Constant8'
   *  Constant: '<Root>/Constant9'
   */
  {
    bool is10bitAddr = false;

    /* Set slave address and then request data from that slave */
    LPI2C_DRV_MasterSetSlaveAddr(0U, ((uint16_T)120U), is10bitAddr);
    LPI2C_DRV_MasterReceiveDataBlocking(0U,
      &Pressure_I2C_B.LPI2C_Master_Receive1[0], 2U, true, 50U);
  }

  /* MATLAB Function: '<Root>/MATLAB Function' */
  intInput_idx_0 = Pressure_I2C_B.LPI2C_Master_Receive1[0];
  intInput_idx_1 = Pressure_I2C_B.LPI2C_Master_Receive1[1];
  for (k = 0; k < 8; k++) {
    u_bin_mat_tmp = (uint8_T)(1 << k);
    u_bin_mat[7 - k] = (uint8_T)((u_bin_mat_tmp & intInput_idx_0) != 0);
    u_bin_mat[15 - k] = (uint8_T)((u_bin_mat_tmp & intInput_idx_1) != 0);
  }

  for (k = 0; k < 16; k++) {
    if ((uint16_T)((uint16_T)-k + 15U) > 15) {
      y = MAX_uint16_T;
    } else {
      y = (uint16_T)(1 << (uint16_T)((uint16_T)-k + 15U));
    }

    qY = (uint32_T)u_bin_mat[k] * y;
    if (qY > 65535U) {
      qY = 65535U;
    }

    Pressure_I2C_B.b_y[k] = (uint16_T)qY;
  }

  y = Pressure_I2C_B.b_y[0];
  for (k = 0; k < 15; k++) {
    qY = (uint32_T)Pressure_I2C_B.b_y[k + 1] + y;
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

  pressure_digital = (uint16_T)rt_roundd_snf((real_T)(int32_T)qY / 13.1065);

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */

  /* Gain: '<Root>/Gain' */
  Pressure_I2C_B.Gain = 0.000244140625F * (real32_T)Pressure_I2C_B.ADC_Start;

  /* S-Function (ftm_s32k_pwm_config): '<Root>/FTM_PWM_Config' */
  {
    uint16_t dutyA = FTM_MAX_DUTY_CYCLE * Pressure_I2C_B.Gain;
    FTM_DRV_UpdatePwmChannel(FTM_PWM0, 0U, FTM_PWM_UPDATE_IN_DUTY_CYCLE, dutyA,
      0, true);
  }
}

/* Model initialize function */
void Pressure_I2C_initialize(void)
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

  /* Start for S-Function (lpi2c_s32k_config): '<Root>/LPI2C_Config' */
  {
    /* Enable clock for LPI2C and GPIO (SDA, SCL pins) */
    PCC_SetPeripheralClockControl(PCC, LPI2C0_CLK, true, CLK_SRC_SPLL,
      DIVIDE_BY_ONE, MULTIPLY_BY_ONE);
    PCC_SetClockMode(PCC, PORTA_CLK, true);
    PCC_SetClockMode(PCC, PORTA_CLK, true);

    /* Setup i2c instance0 pins */
    pin_settings_config_t i2c0_pins[2]= {
      {
        .base = PORTA,
        .pinPortIdx = 2,
        .pullConfig = PORT_INTERNAL_PULL_UP_ENABLED,
        .passiveFilter = false,
        .driveSelect = PORT_LOW_DRIVE_STRENGTH,
        .mux = PORT_MUX_ALT3,
        .pinLock = false,
        .intConfig = PORT_DMA_INT_DISABLED,
        .clearIntFlag = false,
      },

      {
        .base = PORTA,
        .pinPortIdx = 3,
        .pullConfig = PORT_INTERNAL_PULL_UP_ENABLED,
        .passiveFilter = false,
        .driveSelect = PORT_LOW_DRIVE_STRENGTH,
        .mux = PORT_MUX_ALT3,
        .pinLock = false,
        .intConfig = PORT_DMA_INT_DISABLED,
        .clearIntFlag = false,
      } };

    PINS_DRV_Init(2, i2c0_pins);
    static lpi2c_master_user_config_t lpi2c_MasterConfig0 = {
      .slaveAddress = 1U,     /* default value, will be changed upon transfer */
      .is10bitAddr = false,
      .operatingMode = LPI2C_STANDARD_MODE,
                    /* on S32K144 only Standard mode supported (up to 100kbps)*/
      .baudRate = 200000U,
      .transferType = LPI2C_USING_INTERRUPTS,
      .masterCallback = (i2c_master_callback_t)lpi2c_MasterCallback,
      .callbackParam = NULL
    };

    /* Initialize LPI2C instance with the config above */
    LPI2C_DRV_MasterInit(0, &lpi2c_MasterConfig0, &lpi2cMasterState0);
  }
}

/* Model terminate function */
void Pressure_I2C_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */