/* 
==OVERVIEW==
main file for the operation of the Nios Board with the integrated SCCharts code that was pre-generated
This file deals with the integration and mapping the signals to hardware

==MODE DESCRIPTION==

--MODE 1--
This mode will use KEY1 and KEY0 to simulate atrial and ventricular events respectively from the heart 
to the pacemaker, and output AP or VP signals to the green LEDs.

--MODE 2--
Here, the pacemaker will communicate with a virtual heart running on a PC over UART. This heart will 
beat as a normal heart would, with the ability to exhibit several disease states at the press of a 
button. For communication, bi-directional UART communication will be used where the characters 
AP and VP from the heart to the pacemaker mean AS and VS respectively. Similarly, the 
characters A and �V� from the pacemaker to the heart mean �AP� and �VP� respectively

*/


//INCLUDING HEADERS//

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <system.h>
#include <sys/alt_alarm.h>
#include <sys/alt_irq.h>
#include <altera_avalon_pio_regs.h>
#include <io.h>

#include "SCChart.h"

//DEFINING MACROES//

//timer values are in milliseconds//
#define AVI_VALUE 300
#define AEI_VALUE 800
#define PVARP_VALUE 50
#define VRP_VALUE 150
#define LRI_VALUE 950
#define URI_VALUE 900

//defining the uart for mode 2//
#define UART_NAME "/dev/uart"
#define UART_TYPE "altera_avalon_uart"
#define UART_BASE 0x00512000
#define UART_SPAN 32
#define UART_IRQ 8 //Would this change?? 
#define UART_BAUD 115200\

//INTERRUPT SERVICE ROUTINES//

/* commented out as not sure how to operate timers yet
alt_u32 timerISR(void* context){
	int* timeCount = (int*) context;
	(*timeCount)++;
	return 200; // next time out is 200ms
}
 */ 

void buttonISR(void* context, alt_u32 id){
	int* temp = (void*) context;
	(*temp)++;
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE, 0);

}

//UART needs to be interrupt enabled it is non-blocking the rrdy status register bit being 1 should trigger this//

string uartISR(void* context){
  //Q: Within here is the objective to see what the value received was and act convert to AS or VS

  int* temp = (void*) context;
  switch(temp){
    case "AP":
      return "AS" //Q:Where does/can this go
    case "VP":
      return "VS"
  }
}

int main()
{
  printf("Group-7 Pacemaker!\n");

  // Button init
  int button = 0;
  void* buttonContext = (void*) &button;
  IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE, 0);
  IOWR_ALTERA_AVALON_PIO_IRQ_MASK(BUTTONS_BASE, 0x02);
  alt_irq_register(BUTTONS_IRQ,buttonContext, buttonISR);

  //UART init
  int uart = 0
  void* uartContext = (void*) &button;
  IOWR_ALTERA_AVALON_PIO_EDGE_CAP(UART_BASE, 0);
  IOWR_ALTERA_AVALON_PIO_IRQ_MASK(UART_BASE, 0x01); //Q: Unsure about what the Mask Value would be
  alt_irq_register(UART_IRQ,uartContext, uartISR); //Q: is this correct use of this function for the UART
  
  // SC Chart Init
  TickData data;
  reset(&data);
  tick(&data); // init tick
  
  // Reset LED
  IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0x00);

  // Reset LED
  IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, 0x00);


   




