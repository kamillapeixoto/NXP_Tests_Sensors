/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pressure_Analog_PWM.h
 *
 * Code generated for Simulink model 'Pressure_Analog_PWM'.
 *
 * Model version                  : 1.37
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Mar 22 12:29:08 2023
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Pressure_Analog_PWM_h_
#define RTW_HEADER_Pressure_Analog_PWM_h_
#ifndef Pressure_Analog_PWM_COMMON_INCLUDES_
#define Pressure_Analog_PWM_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "adc_driver.h"
#include "ftm_pwm_driver.h"
#include "clock_manager.h"
#include "pcc_hw_access.h"
#include "pins_port_hw_access.h"
#include "ftm_hw_access.h"
#include "ftm0_pwm_params.h"
#include "device_registers.h"
#include "freemaster.h"
#include "freemaster_interface_init.h"
#endif                                /* Pressure_Analog_PWM_COMMON_INCLUDES_ */

#include <stddef.h>
#include "Pressure_Analog_PWM_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint32_T ADC_Start;                  /* '<Root>/ADC_Start' */
  real32_T Gain;                       /* '<Root>/Gain' */
} B_Pressure_Analog_PWM_T;

/* Real-time Model Data Structure */
struct tag_RTM_Pressure_Analog_PWM_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Pressure_Analog_PWM_T Pressure_Analog_PWM_B;

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern uint32_T analog_read;           /* '<Root>/Data Store Memory' */

/* Model entry point functions */
extern void Pressure_Analog_PWM_initialize(void);
extern void Pressure_Analog_PWM_step(void);
extern void Pressure_Analog_PWM_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Pressure_Analog_PWM_T *const Pressure_Analog_PWM_M;

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
 * '<Root>' : 'Pressure_Analog_PWM'
 */
#endif                                 /* RTW_HEADER_Pressure_Analog_PWM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
