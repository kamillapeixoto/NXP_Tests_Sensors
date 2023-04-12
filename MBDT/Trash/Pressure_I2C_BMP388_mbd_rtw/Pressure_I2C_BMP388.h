/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pressure_I2C_BMP388.h
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

#ifndef RTW_HEADER_Pressure_I2C_BMP388_h_
#define RTW_HEADER_Pressure_I2C_BMP388_h_
#ifndef Pressure_I2C_BMP388_COMMON_INCLUDES_
#define Pressure_I2C_BMP388_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "clock_manager.h"
#include "pcc_hw_access.h"
#include "pins_driver.h"
#include "lpi2c_driver.h"
#include "lpi2c_irq.h"
#include "lpi2c_hw_access.h"
#endif                                /* Pressure_I2C_BMP388_COMMON_INCLUDES_ */

#include <stddef.h>
#include "Pressure_I2C_BMP388_types.h"

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
  uint8_T y;                           /* '<Root>/MATLAB Function2' */
} B_Pressure_I2C_BMP388_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T Count_reg_DSTATE;            /* '<S1>/Count_reg' */
  uint8_T recv;                        /* '<Root>/Data Store Memory1' */
  uint8_T recv2;                       /* '<Root>/Data Store Memory2' */
} DW_Pressure_I2C_BMP388_T;

/* Real-time Model Data Structure */
struct tag_RTM_Pressure_I2C_BMP388_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Pressure_I2C_BMP388_T Pressure_I2C_BMP388_B;

/* Block states (default storage) */
extern DW_Pressure_I2C_BMP388_T Pressure_I2C_BMP388_DW;

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
extern void Pressure_I2C_BMP388_initialize(void);
extern void Pressure_I2C_BMP388_step(void);
extern void Pressure_I2C_BMP388_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Pressure_I2C_BMP388_T *const Pressure_I2C_BMP388_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Compare' : Unused code path elimination
 * Block '<S6>/Constant' : Unused code path elimination
 * Block '<S7>/Compare' : Unused code path elimination
 * Block '<S7>/Constant' : Unused code path elimination
 * Block '<S1>/DT_convert' : Eliminate redundant data type conversion
 * Block '<S1>/DT_convert1' : Eliminate redundant data type conversion
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S1>/Free_running_or_modulo' : Unused code path elimination
 * Block '<S1>/From_value' : Unused code path elimination
 * Block '<S1>/Init_value' : Unused code path elimination
 * Block '<S1>/Relational Operator' : Unused code path elimination
 * Block '<S1>/Switch_max' : Unused code path elimination
 * Block '<S1>/const_enb' : Unused code path elimination
 * Block '<S1>/const_load' : Unused code path elimination
 * Block '<S1>/const_load_val' : Unused code path elimination
 * Block '<S1>/const_rst' : Unused code path elimination
 */

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
 * '<Root>' : 'Pressure_I2C_BMP388'
 * '<S1>'   : 'Pressure_I2C_BMP388/HDL Counter'
 * '<S2>'   : 'Pressure_I2C_BMP388/MATLAB Function2'
 * '<S3>'   : 'Pressure_I2C_BMP388/HDL Counter/Add_wrap'
 * '<S4>'   : 'Pressure_I2C_BMP388/HDL Counter/Dir_logic'
 * '<S5>'   : 'Pressure_I2C_BMP388/HDL Counter/Sub_wrap'
 * '<S6>'   : 'Pressure_I2C_BMP388/HDL Counter/Add_wrap/Compare To Constant'
 * '<S7>'   : 'Pressure_I2C_BMP388/HDL Counter/Sub_wrap/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_Pressure_I2C_BMP388_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
