/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pressure_SPI_BMP388.c
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

#include "Pressure_SPI_BMP388.h"
#include "rtwtypes.h"
#include "Pressure_SPI_BMP388_private.h"

lpspi_state_t lpspiMasterState0;
void lpspi_master_transfer_callback0(void *driverState, spi_event_t event, void *
  userData) __attribute__((weak));

/* Exported block states */
uint32_T pressure_digital;             /* '<Root>/Data Store Memory3' */
uint8_T pressure_digital1[3];          /* '<Root>/Data Store Memory1' */

/* Block signals (default storage) */
B_Pressure_SPI_BMP388_T Pressure_SPI_BMP388_B;

/* Real-time model */
static RT_MODEL_Pressure_SPI_BMP388_T Pressure_SPI_BMP388_M_;
RT_MODEL_Pressure_SPI_BMP388_T *const Pressure_SPI_BMP388_M =
  &Pressure_SPI_BMP388_M_;

/* Model step function */
void Pressure_SPI_BMP388_step(void)
{
  /* S-Function (lpspi_s32k_master_transfer): '<Root>/LPSPI_Master_Transfer1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  {
    /* Update the peripheral CS to select the slave you want to send data to */
    LPSPI_DRV_SetPcs(0, LPSPI_PCS0, LPSPI_ACTIVE_LOW);

    /* Send data */
    LPSPI_DRV_MasterTransfer(0, Pressure_SPI_BMP388_ConstP.pooled1,
      &Pressure_SPI_BMP388_B.LPSPI_Master_Transfer1[0], 3);
  }

  /* DataStoreWrite: '<Root>/Data Store Write' */
  pressure_digital1[0] = Pressure_SPI_BMP388_B.LPSPI_Master_Transfer1[0];
  pressure_digital1[1] = Pressure_SPI_BMP388_B.LPSPI_Master_Transfer1[1];
  pressure_digital1[2] = Pressure_SPI_BMP388_B.LPSPI_Master_Transfer1[2];
}

/* Model initialize function */
void Pressure_SPI_BMP388_initialize(void)
{
  /* Start for S-Function (lpspi_s32k_config): '<Root>/LPSPI_Config ' */
  {
    /* Enable LPSPI clock */
    PCC_SetPeripheralClockControl(PCC, LPSPI0_CLK, true, CLK_SRC_FIRC_DIV2,
      DIVIDE_BY_ONE, MULTIPLY_BY_ONE);

    /* Enable clock for PORTB */
    PCC_SetPeripheralClockControl(PCC, PORTB_CLK, true, CLK_SRC_OFF,
      DIVIDE_BY_ONE, MULTIPLY_BY_ONE);

    /* Enable clock for PORTB */
    PCC_SetPeripheralClockControl(PCC, PORTB_CLK, true, CLK_SRC_OFF,
      DIVIDE_BY_ONE, MULTIPLY_BY_ONE);

    /* Enable clock for PORTB */
    PCC_SetPeripheralClockControl(PCC, PORTB_CLK, true, CLK_SRC_OFF,
      DIVIDE_BY_ONE, MULTIPLY_BY_ONE);

    /* PCS0! Enable clock for PORTB */
    PCC_SetPeripheralClockControl(PCC, PORTB_CLK, true, CLK_SRC_OFF,
      DIVIDE_BY_ONE, MULTIPLY_BY_ONE);

    /* Setup SPI pins */
    pin_settings_config_t spi_pin_mux[4U]= {
      {
        /* SIN pin */
        .base = PORTB,
        .pinPortIdx = 3,
        .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
        .passiveFilter = false,
        .driveSelect = PORT_LOW_DRIVE_STRENGTH,
        .mux = PORT_MUX_ALT3,
        .pinLock = false,
        .intConfig = PORT_DMA_INT_DISABLED,
        .clearIntFlag = false,
      },

      {
        /* SOUT pin */
        .base = PORTB,
        .pinPortIdx = 4,
        .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
        .passiveFilter = false,
        .driveSelect = PORT_LOW_DRIVE_STRENGTH,
        .mux = PORT_MUX_ALT3,
        .pinLock = false,
        .intConfig = PORT_DMA_INT_DISABLED,
        .clearIntFlag = false,
      },

      {
        /* SCK pin */
        .base = PORTB,
        .pinPortIdx = 2,
        .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
        .passiveFilter = false,
        .driveSelect = PORT_LOW_DRIVE_STRENGTH,
        .mux = PORT_MUX_ALT3,
        .pinLock = false,
        .intConfig = PORT_DMA_INT_DISABLED,
        .clearIntFlag = false,
      },

      {
        /* PCS0 pin */
        .base = PORTB,
        .pinPortIdx = 5,
        .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
        .passiveFilter = false,
        .driveSelect = PORT_LOW_DRIVE_STRENGTH,
        .mux = PORT_MUX_ALT4,
        .pinLock = false,
        .intConfig = PORT_DMA_INT_DISABLED,
        .clearIntFlag = false,
      },
    };

    PINS_DRV_Init(4U, spi_pin_mux);
  }

  {
    /* Configure the SPI init structure. */
    lpspi_master_config_t spiConfig0 = {
      .bitsPerSec = 300000U,
      .whichPcs = LPSPI_PCS0,
      .pcsPolarity = LPSPI_ACTIVE_LOW,
      .isPcsContinuous = true,
      .bitcount = 8U,
      .clkPhase = LPSPI_CLOCK_PHASE_1ST_EDGE,
      .clkPolarity = LPSPI_SCK_ACTIVE_HIGH,
      .lsbFirst = false,
      .transferType = LPSPI_USING_INTERRUPTS,
      .callback = (spi_callback_t)lpspi_master_transfer_callback0,
    };

    /* Module source clock */
    uint32_t frequency;
    CLOCK_SYS_GetFreq(LPSPI0_CLK, &frequency);
    spiConfig0.lpspiSrcClk = frequency;

    /* Initializes a LPSPI instance for interrupt driven master mode operation */
    LPSPI_DRV_MasterInit(0, &lpspiMasterState0, &spiConfig0);
  }
}

/* Model terminate function */
void Pressure_SPI_BMP388_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
