/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pressure_I2C_BMP388.c
 *
 * Code generated for Simulink model 'Pressure_I2C_BMP388'.
 *
 * Model version                  : 1.178
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Apr  3 11:37:47 2023
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Pressure_I2C_BMP388.h"
#include "rtwtypes.h"
#include "Pressure_I2C_BMP388_private.h"

lpi2c_master_state_t lpi2cMasterState0;
void lpi2c_MasterCallback(i2c_master_event_t masterEvent, void *userData)
  __attribute__((weak));

/* Exported block states */
uint8_T pressure_digital[7];           /* '<Root>/Data Store Memory3' */

/* Block signals (default storage) */
B_Pressure_I2C_BMP388_T Pressure_I2C_BMP388_B;

/* Block states (default storage) */
DW_Pressure_I2C_BMP388_T Pressure_I2C_BMP388_DW;

/* Real-time model */
static RT_MODEL_Pressure_I2C_BMP388_T Pressure_I2C_BMP388_M_;
RT_MODEL_Pressure_I2C_BMP388_T *const Pressure_I2C_BMP388_M =
  &Pressure_I2C_BMP388_M_;
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

/* Model step function */
void Pressure_I2C_BMP388_step(void)
{
  int32_T i;

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  UnitDelay: '<S1>/Count_reg'
   */
  Pressure_I2C_BMP388_B.y = 27U;
  if (Pressure_I2C_BMP388_DW.Count_reg_DSTATE > 1) {
    Pressure_I2C_BMP388_B.y = 3U;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */

  /* S-Function (lpi2c_s32k_master_multi_transfer): '<Root>/LPI2C_Master_Multi_Transfer' incorporates:
   *  Constant: '<Root>/Constant10'
   *  Constant: '<Root>/Constant8'
   *  Constant: '<Root>/Constant9'
   */
  {
    bool is10bitAddr = false;

    /* Set slave address and then send data (register address / command to that slave */
    LPI2C_DRV_MasterSetSlaveAddr(0U, ((uint16_T)119U), is10bitAddr);
    LPI2C_DRV_MasterSendDataBlocking(0U, &Pressure_I2C_BMP388_B.y, 1, true, 50U);

    /* Insert delay for slave to get data ready */
    OSIF_TimeDelay(50U);

    /* Read data from slave */
    LPI2C_DRV_MasterReceiveDataBlocking(0U,
      &Pressure_I2C_BMP388_B.LPI2C_Master_Multi_Transfer[0], 7, true, 50U);
  }

  /* DataStoreWrite: '<Root>/Data Store Write4' */
  for (i = 0; i < 7; i++) {
    pressure_digital[i] = Pressure_I2C_BMP388_B.LPI2C_Master_Multi_Transfer[i];
  }

  /* End of DataStoreWrite: '<Root>/Data Store Write4' */

  /* Switch: '<S3>/Switch_wrap' incorporates:
   *  Constant: '<S1>/Step_value'
   *  Sum: '<S3>/Add'
   *  Switch: '<S1>/Switch_dir'
   *  UnitDelay: '<S1>/Count_reg'
   */
  if ((uint16_T)(Pressure_I2C_BMP388_DW.Count_reg_DSTATE + 1U) > 255) {
    /* Switch: '<S1>/Switch_reset' */
    Pressure_I2C_BMP388_DW.Count_reg_DSTATE = 0U;
  } else {
    /* Switch: '<S1>/Switch_reset' */
    Pressure_I2C_BMP388_DW.Count_reg_DSTATE++;
  }

  /* End of Switch: '<S3>/Switch_wrap' */
}

/* Model initialize function */
void Pressure_I2C_BMP388_initialize(void)
{
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
      .baudRate = 400000U,
      .transferType = LPI2C_USING_INTERRUPTS,
      .masterCallback = (i2c_master_callback_t)lpi2c_MasterCallback,
      .callbackParam = NULL
    };

    /* Initialize LPI2C instance with the config above */
    LPI2C_DRV_MasterInit(0, &lpi2c_MasterConfig0, &lpi2cMasterState0);
  }
}

/* Model terminate function */
void Pressure_I2C_BMP388_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */