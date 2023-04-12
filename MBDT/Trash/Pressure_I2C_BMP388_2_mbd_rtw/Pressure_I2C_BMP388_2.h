/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pressure_I2C_BMP388_2.h
 *
 * Code generated for Simulink model 'Pressure_I2C_BMP388_2'.
 *
 * Model version                  : 1.183
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Apr  3 12:42:45 2023
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Pressure_I2C_BMP388_2_h_
#define RTW_HEADER_Pressure_I2C_BMP388_2_h_
#ifndef Pressure_I2C_BMP388_2_COMMON_INCLUDES_
#define Pressure_I2C_BMP388_2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "clock_manager.h"
#include "pcc_hw_access.h"
#include "pins_driver.h"
#include "lpi2c_driver.h"
#include "lpi2c_irq.h"
#include "lpi2c_hw_access.h"
#endif                              /* Pressure_I2C_BMP388_2_COMMON_INCLUDES_ */

#include <stddef.h>
#include "Pressure_I2C_BMP388_2_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T LPI2C_Master_Multi_Transfer[7];
                                      /* '<Root>/LPI2C_Master_Multi_Transfer' */
} B_Pressure_I2C_BMP388_2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T recv;                        /* '<Root>/Data Store Memory1' */
  uint8_T recv2;                       /* '<Root>/Data Store Memory2' */
} DW_Pressure_I2C_BMP388_2_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0x1B 0x13]
   * Referenced by: '<Root>/Constant'
   */
  uint8_T Constant_Value[2];

  /* Expression: 0x04
   * Referenced by: '<Root>/Constant1'
   */
  uint8_T Constant1_Value;
} ConstP_Pressure_I2C_BMP388_2_T;

/* Real-time Model Data Structure */
struct tag_RTM_Pressure_I2C_BMP388_2_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Pressure_I2C_BMP388_2_T Pressure_I2C_BMP388_2_B;

/* Block states (default storage) */
extern DW_Pressure_I2C_BMP388_2_T Pressure_I2C_BMP388_2_DW;

/* External data declarations for dependent source files */
extern const uint8_T Pressure_I2C_BMP388_2_U8GND;/* uint8_T ground */

/* Constant parameters (default storage) */
extern const ConstP_Pressure_I2C_BMP388_2_T Pressure_I2C_BMP388_2_ConstP;

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern uint8_T pressure_digital[7];    /* '<Root>/Data Store Memory3' */

/* Model entry point functions */
extern void Pressure_I2C_BMP388_2_initialize(void);
extern void Pressure_I2C_BMP388_2_step(void);
extern void Pressure_I2C_BMP388_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Pressure_I2C_BMP388__T *const Pressure_I2C_BMP388_2_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Pressure_I2C_BMP388_2'
 */
#endif                                 /* RTW_HEADER_Pressure_I2C_BMP388_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
