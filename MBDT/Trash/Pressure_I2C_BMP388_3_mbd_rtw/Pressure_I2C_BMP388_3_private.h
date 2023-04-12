/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pressure_I2C_BMP388_3_private.h
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

#ifndef RTW_HEADER_Pressure_I2C_BMP388_3_private_h_
#define RTW_HEADER_Pressure_I2C_BMP388_3_private_h_
#include "rtwtypes.h"
#include "Pressure_I2C_BMP388_3_types.h"
#include "Pressure_I2C_BMP388_3.h"
#if defined(__MWERKS__)

double fmod (double x, double y);
double fabs (double);

#endif

extern void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern uint32_T mul_u32_sat(uint32_T a, uint32_T b);

#endif                         /* RTW_HEADER_Pressure_I2C_BMP388_3_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
