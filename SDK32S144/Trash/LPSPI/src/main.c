/*
 * main.c                       (c) NXP 2016
 * Description: Simple LPSPI transfer.  A frame is transmitted and results read.
 * May 31 2016 S. Mihalik - Initial version.
 * Sep 23 2016 S. Mihalik - Added SBC commands for SPI transfer
 * Oct 31 2016 SM - Clocks adjusted for SPLL at 160 MHz,
 *                  tx, rx variables made global
 * Jul 03 2017 SM - removed code for MC33903 on obsolete EVB
 */

#include "S32K144.h"           /* include peripheral declarations S32K144 */
#include "LPSPI.h"
#include "clocks_and_modes.h"

  uint16_t tx_16bits = 0xFD00;  /* SBC UJA1169: read Dev ID Reg @ 0x7E (expect non-zero)*/
                                /* Note: Obsolete EVB with MC33903 example used 0c2580 */
                                /*       to read SAFE reg flags (expect nonzero result).*/
  uint16_t LPSPI1_16bits_read;  /* Returned data in to SPI */

void WDOG_disable (void){
  WDOG->CNT=0xD928C520;     /*Unlock watchdog*/
  WDOG->TOVAL=0x0000FFFF;   /*Maximum timeout value*/
  WDOG->CS = 0x00002100;    /*Disable watchdog*/
}

void PORT_init (void) {
  PCC->PCCn[PCC_PORTB_INDEX ]|=PCC_PCCn_CGC_MASK; /* Enable clock for PORTB */
  PORTB->PCR[2]|=PORT_PCR_MUX(3); /* Port B14: MUX = ALT3, LPSPI1_SCK */
  PORTB->PCR[3]|=PORT_PCR_MUX(3); /* Port B15: MUX = ALT3, LPSPI1_SIN */
  PORTB->PCR[4]|=PORT_PCR_MUX(3); /* Port B16: MUX = ALT3, LPSPI1_SOUT */
  PORTB->PCR[5]|=PORT_PCR_MUX(3); /* Port B17: MUX = ALT3, LPSPI1_PCS3 */
}

int main(void) {
   uint32_t counter = 0;



  WDOG_disable();
  SOSC_init_8MHz();        /* Initialize system oscillator for 8 MHz xtal */
  SPLL_init_160MHz();      /* Initialize SPLL to 160 MHz with 8 MHz SOSC */
  NormalRUNmode_80MHz();   /* Init clocks: 80 MHz sysclk & core, 40 MHz bus, 20 MHz flash */
  LPSPI1_init_master();    /* Initialize LPSPI 1 as master */
  PORT_init();             /* Configure ports */
  for(;;) {
    LPSPI1_transmit_16bits(tx_16bits);       /* Transmit half word (16 bits) on LPSPI1 */
    LPSPI1_16bits_read = LPSPI1_receive_16bits(); /* Receive half word on LSPI1 */
    counter++;
  }
}
