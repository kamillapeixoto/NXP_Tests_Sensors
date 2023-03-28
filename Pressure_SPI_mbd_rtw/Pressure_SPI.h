/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pressure_SPI.h
 *
 * Code generated for Simulink model 'Pressure_SPI'.
 *
 * Model version                  : 1.118
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Mar 28 14:10:32 2023
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Pressure_SPI_h_
#define RTW_HEADER_Pressure_SPI_h_
#ifndef Pressure_SPI_COMMON_INCLUDES_
#define Pressure_SPI_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "adc_driver.h"
#include "lpspi_master_driver.h"
#include "ftm_pwm_driver.h"
#include "clock_manager.h"
#include "pcc_hw_access.h"
#include "pins_port_hw_access.h"
#include "ftm_hw_access.h"
#include "ftm0_pwm_params.h"
#include "device_registers.h"
#include "freemaster.h"
#include "freemaster_interface_init.h"
#include "lpspi_slave_driver.h"
#include "interrupt_manager.h"
#endif                                 /* Pressure_SPI_COMMON_INCLUDES_ */

#include <stddef.h>
#include "Pressure_SPI_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint16_T b_y[15];
  uint32_T ADC_Start;                  /* '<Root>/ADC_Start' */
  real32_T Gain;                       /* '<Root>/Gain' */
  uint8_T LPSPI_Master_Transfer[2];    /* '<Root>/LPSPI_Master_Transfer' */
} B_Pressure_SPI_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Constant_Value
   * Referenced by: '<Root>/Constant'
   */
  uint8_T Constant_Value[2];
} ConstP_Pressure_SPI_T;

/* Real-time Model Data Structure */
struct tag_RTM_Pressure_SPI_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Pressure_SPI_T Pressure_SPI_B;

/* Constant parameters (default storage) */
extern const ConstP_Pressure_SPI_T Pressure_SPI_ConstP;

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern uint32_T pressure_analog;       /* '<Root>/Data Store Memory' */
extern uint16_T pressure_digital;      /* '<Root>/Data Store Memory3' */

/* Model entry point functions */
extern void Pressure_SPI_initialize(void);
extern void Pressure_SPI_step(void);
extern void Pressure_SPI_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Pressure_SPI_T *const Pressure_SPI_M;

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
 * '<Root>' : 'Pressure_SPI'
 * '<S1>'   : 'Pressure_SPI/MATLAB Function'
 * '<S2>'   : 'Pressure_SPI/MATLAB Function1'
 * '<S3>'   : 'Pressure_SPI/MATLAB Function2'
 */
#endif                                 /* RTW_HEADER_Pressure_SPI_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
