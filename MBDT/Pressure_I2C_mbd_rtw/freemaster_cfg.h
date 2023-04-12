/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: freemaster_cfg.h
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

#ifndef RTW_HEADER_freemaster_cfg_h_
#define RTW_HEADER_freemaster_cfg_h_

/***************************************************************************/
/*!
 *
 * @file   freemaster_cfg.h
 *
 * @brief  FreeMASTER Serial Communication Driver configuration file
 *
 *******************************************************************************/

/******************************************************************************
 * Select interrupt or poll-driven serial communication
 ******************************************************************************/
#define FMSTR_LONG_INTR                0                         /* complete message processing in interrupt */
#define FMSTR_SHORT_INTR               0                         /* SCI FIFO-queuing done in interrupt */
#define FMSTR_POLL_DRIVEN              1                         /* no interrupt needed, polling only */

/*****************************************************************************
 * Select communication interface (SCI, CAN, USB CDC or Packet Driven BDM)
 ******************************************************************************/
#define FMSTR_DISABLE                  0                         /* To disable all FreeMASTER functionalities */
#define FMSTR_USE_SCI                  1                         /* To select SCI communication interface */
#define FMSTR_SCI_BASE                 0x4006B000
#define FMSTR_USE_MSCAN                0
#define FMSTR_USE_FLEXCAN              0                         /* To select FlexCAN communication interface */
#define FMSTR_USE_FLEXCAN32            0
#define FMSTR_CAN_BASE                 0x40024000
#define FMSTR_USE_SFIO                 0                         /* SFIO Toolbox has been used */
#define FMSTR_USE_USB_CDC              0                         /* To select USB CDC communication interface */
#define FMSTR_USE_PDBDM                0                         /* To select Packet Driven BDM communication interface (optional) */

/* select RX and TX FlexCAN Message buffers */
#define FMSTR_FLEXCAN_TXMB             0
#define FMSTR_FLEXCAN_RXMB             1

/******************************************************************************
 * Input/output communication buffer size
 ******************************************************************************/
#define FMSTR_COMM_BUFFER_SIZE         0                         /* set to 0 for "automatic" */

/******************************************************************************
 * Receive FIFO queue size (use with FMSTR_SHORT_INTR only)
 ******************************************************************************/
#define FMSTR_COMM_RQUEUE_SIZE         0                         /* set to 0 for "default" */

/*****************************************************************************
 * Support for Application Commands
 ******************************************************************************/
#define FMSTR_USE_APPCMD               0                         /* enable/disable App.Commands support */
#define FMSTR_APPCMD_BUFF_SIZE         0                         /* App.Command data buffer size */
#define FMSTR_MAX_APPCMD_CALLS         1                         /* how many app.cmd callbacks? (0=disable) */

/*****************************************************************************
 * Oscilloscope support
 ******************************************************************************/
#define FMSTR_USE_SCOPE                1                         /* enable/disable scope support */
#define FMSTR_MAX_SCOPE_VARS           8                         /* max. number of scope variables (2..8) */

/*****************************************************************************
 * Recorder support
 ******************************************************************************/
#define FMSTR_USE_RECORDER             1                         /* enable/disable recorder support */
#define FMSTR_MAX_REC_VARS             8                         /* max. number of recorder variables (2..8) */
#define FMSTR_REC_OWNBUFF              0                         /* use user-allocated rec. buffer (1=yes) */

/* built-in recorder buffer (use when FMSTR_REC_OWNBUFF is 0) */
#define FMSTR_REC_BUFF_SIZE            1024                      /* built-in buffer size */

/* recorder time base, specifies how often the recorder is called in the user app. */
#define FMSTR_REC_TIMEBASE             FMSTR_REC_BASE_SECONDS(0) /* 0 = "unknown" */

/*****************************************************************************
 * Target-side address translation (TSA)
 ******************************************************************************/
#define FMSTR_USE_TSA                  0                         /* enable TSA functionality */
#define FMSTR_USE_TSA_SAFETY           0                         /* enable access to TSA variables only */
#define FMSTR_USE_TSA_INROM            0                         /* TSA tables declared as const (put to ROM) */

/*****************************************************************************
 * Enable/Disable read/write memory commands
 ******************************************************************************/
#define FMSTR_USE_READMEM              1                         /* enable read memory commands */
#define FMSTR_USE_WRITEMEM             1                         /* enable write memory commands */
#define FMSTR_USE_WRITEMEMMASK         1                         /* enable write memory bits commands */

/*****************************************************************************
 * Enable/Disable read/write variable commands (a bit faster than Read Mem)
 ******************************************************************************/
#define FMSTR_USE_READVAR              1                         /* enable read variable fast commands */
#define FMSTR_USE_WRITEVAR             1                         /* enable write variable fast commands */
#define FMSTR_USE_WRITEVARMASK         1                         /* enable write variable bits fast commands */
#endif                                 /* RTW_HEADER_freemaster_cfg_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
