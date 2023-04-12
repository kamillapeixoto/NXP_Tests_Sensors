/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pressure_I2C_BMP388_3.c
 *
 * Code generated for Simulink model 'Pressure_I2C_BMP388_3'.
 *
 * Model version                  : 1.191
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Apr  3 14:52:42 2023
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Pressure_I2C_BMP388_3.h"
#include "rtwtypes.h"
#include "Pressure_I2C_BMP388_3_private.h"

lpi2c_master_state_t lpi2cMasterState0;
void lpi2c_MasterCallback(i2c_master_event_t masterEvent, void *userData)
  __attribute__((weak));

/* Exported block states */
uint32_T recv;                         /* '<Root>/Data Store Memory1' */
uint8_T pressure_digital[4];           /* '<Root>/Data Store Memory3' */

/* Block signals (default storage) */
B_Pressure_I2C_BMP388_3_T Pressure_I2C_BMP388_3_B;

/* Block states (default storage) */
DW_Pressure_I2C_BMP388_3_T Pressure_I2C_BMP388_3_DW;

/* Real-time model */
static RT_MODEL_Pressure_I2C_BMP388__T Pressure_I2C_BMP388_3_M_;
RT_MODEL_Pressure_I2C_BMP388__T *const Pressure_I2C_BMP388_3_M =
  &Pressure_I2C_BMP388_3_M_;
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

void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T in0Hi;
  uint32_T in0Lo;
  uint32_T in1Hi;
  uint32_T in1Lo;
  uint32_T outBitsLo;
  uint32_T productHiLo;
  uint32_T productLoHi;
  in0Hi = in0 >> 16U;
  in0Lo = in0 & 65535U;
  in1Hi = in1 >> 16U;
  in1Lo = in1 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = in0Lo * in1Hi;
  in0Lo *= in1Lo;
  in1Lo = 0U;
  outBitsLo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ in0Lo;
  if (outBitsLo < in0Lo) {
    in1Lo = 1U;
  }

  in0Lo = outBitsLo;
  outBitsLo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (outBitsLo < in0Lo) {
    in1Lo++;
  }

  *ptrOutBitsHi = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi)
    + in1Lo;
  *ptrOutBitsLo = outBitsLo;
}

uint32_T mul_u32_sat(uint32_T a, uint32_T b)
{
  uint32_T result;
  uint32_T u32_chi;
  mul_wide_u32(a, b, &u32_chi, &result);
  if (u32_chi) {
    result = MAX_uint32_T;
  }

  return result;
}

/* Model step function */
void Pressure_I2C_BMP388_3_step(void)
{
  int32_T k;
  int32_T u_bin_mat_tmp;
  uint32_T qY;
  uint8_T u_bin_mat[24];
  uint8_T intInput_idx_0;
  uint8_T intInput_idx_1;
  uint8_T intInput_idx_2;

  /* S-Function (lpi2c_s32k_master_transmit): '<Root>/LPI2C_Master_Transmit' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   */
  {
    bool is10bitAddr = false;

    /* Set slave address and then send data to that slave */
    LPI2C_DRV_MasterSetSlaveAddr(0U, ((uint16_T)119U), is10bitAddr);
    LPI2C_DRV_MasterSendDataBlocking(0U,
      Pressure_I2C_BMP388_3_ConstP.Constant_Value, 2, true, 50U);
  }

  /* S-Function (lpi2c_s32k_master_transmit): '<Root>/LPI2C_Master_Transmit1' incorporates:
   *  Constant: '<Root>/Constant11'
   *  Constant: '<Root>/Constant12'
   *  Constant: '<Root>/Constant7'
   */
  {
    bool is10bitAddr = false;

    /* Set slave address and then send data to that slave */
    LPI2C_DRV_MasterSetSlaveAddr(0U, ((uint16_T)119U), is10bitAddr);
    LPI2C_DRV_MasterSendDataBlocking(0U,
      &Pressure_I2C_BMP388_3_ConstP.Constant7_Value, 1, true, 50U);
  }

  /* S-Function (lpi2c_s32k_master_receive): '<Root>/LPI2C_Master_Receive' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   */
  {
    bool is10bitAddr = false;

    /* Set slave address and then request data from that slave */
    LPI2C_DRV_MasterSetSlaveAddr(0U, ((uint16_T)119U), is10bitAddr);
    LPI2C_DRV_MasterReceiveDataBlocking(0U,
      &Pressure_I2C_BMP388_3_B.LPI2C_Master_Receive[0], 4U, true, 50U);
  }

  /* DataStoreWrite: '<Root>/Data Store Write1' */
  pressure_digital[0] = Pressure_I2C_BMP388_3_B.LPI2C_Master_Receive[0];
  pressure_digital[1] = Pressure_I2C_BMP388_3_B.LPI2C_Master_Receive[1];
  pressure_digital[2] = Pressure_I2C_BMP388_3_B.LPI2C_Master_Receive[2];
  pressure_digital[3] = Pressure_I2C_BMP388_3_B.LPI2C_Master_Receive[3];

  /* MATLAB Function: '<Root>/MATLAB Function3' */
  intInput_idx_0 = Pressure_I2C_BMP388_3_B.LPI2C_Master_Receive[0];
  intInput_idx_1 = Pressure_I2C_BMP388_3_B.LPI2C_Master_Receive[1];
  intInput_idx_2 = Pressure_I2C_BMP388_3_B.LPI2C_Master_Receive[2];
  for (k = 0; k < 8; k++) {
    u_bin_mat_tmp = (uint8_T)(1 << k);
    u_bin_mat[7 - k] = (uint8_T)((u_bin_mat_tmp & intInput_idx_0) != 0);
    u_bin_mat[15 - k] = (uint8_T)((u_bin_mat_tmp & intInput_idx_1) != 0);
    u_bin_mat[23 - k] = (uint8_T)((u_bin_mat_tmp & intInput_idx_2) != 0);
  }

  for (k = 0; k < 24; k++) {
    Pressure_I2C_BMP388_3_B.b_y[k] = mul_u32_sat(u_bin_mat[k], 1U << (23U -
      (uint32_T)k));
  }

  recv = Pressure_I2C_BMP388_3_B.b_y[0];
  for (k = 0; k < 23; k++) {
    qY = Pressure_I2C_BMP388_3_B.b_y[k + 1] + /*MW:OvSatOk*/ recv;
    if (qY < recv) {
      qY = MAX_uint32_T;
    }

    recv = qY;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function3' */
}

/* Model initialize function */
void Pressure_I2C_BMP388_3_initialize(void)
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
void Pressure_I2C_BMP388_3_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
