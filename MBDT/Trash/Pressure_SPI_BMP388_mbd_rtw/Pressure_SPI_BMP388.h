/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pressure_SPI_BMP388.h
 *
 * Code generated for Simulink model 'Pressure_SPI_BMP388'.
 *
 * Model version                  : 1.156
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Mar 31 12:42:38 2023
 *
 * Target selection: mbd_s32k.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Pressure_SPI_BMP388_h_
#define RTW_HEADER_Pressure_SPI_BMP388_h_
#ifndef Pressure_SPI_BMP388_COMMON_INCLUDES_
#define Pressure_SPI_BMP388_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "lpspi_master_driver.h"
#include "clock_manager.h"
#include "lpspi_slave_driver.h"
#include "pcc_hw_access.h"
#include "pins_port_hw_access.h"
#include "interrupt_manager.h"
#endif                                /* Pressure_SPI_BMP388_COMMON_INCLUDES_ */

#include <stddef.h>
#include "Pressure_SPI_BMP388_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T LPSPI_Master_Transfer1[3];   /* '<Root>/LPSPI_Master_Transfer1' */
} B_Pressure_SPI_BMP388_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/Data Store Memory1'
   *   '<Root>/Constant1'
   */
  uint8_T pooled1[3];
} ConstP_Pressure_SPI_BMP388_T;

/* Real-time Model Data Structure */
struct tag_RTM_Pressure_SPI_BMP388_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Pressure_SPI_BMP388_T Pressure_SPI_BMP388_B;

/* Constant parameters (default storage) */
extern const ConstP_Pressure_SPI_BMP388_T Pressure_SPI_BMP388_ConstP;

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern uint32_T pressure_digital;      /* '<Root>/Data Store Memory3' */
extern uint8_T pressure_digital1[3];   /* '<Root>/Data Store Memory1' */

/* Model entry point functions */
extern void Pressure_SPI_BMP388_initialize(void);
extern void Pressure_SPI_BMP388_step(void);
extern void Pressure_SPI_BMP388_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Pressure_SPI_BMP388_T *const Pressure_SPI_BMP388_M;

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
 * '<Root>' : 'Pressure_SPI_BMP388'
 */
#endif                                 /* RTW_HEADER_Pressure_SPI_BMP388_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
