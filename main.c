/*
File    : main.c

*/

#include "main.h"
/******************************functions**********************************/
//delay function on for-cycle (~1/4sec)
void delay_for(uint16_t tim_delay){
  uint32_t cycles_count = 0;
  for(cycles_count=0;cycles_count<tim_delay*CYCLES_DELAY;cycles_count++){

  }
}
/*********************************main************************************/
int main(void) {
  //Values initial
  uint8_t counter = 0;

  SystemInit();
  // Clock BUS
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;

  //GPIO Initial
  GPIOE->MODER |= GPIO_MODER_MODE13_0|GPIO_MODER_MODE14_0|GPIO_MODER_MODE15_0;
  GPIOE->BSRR |= GPIO_BSRR_BS13|GPIO_BSRR_BS14|GPIO_BSRR_BS15;

  while(1){
    for(counter=0;counter<3;counter++){
      GPIOE->BSRR |= GPIO_BSRR_BR13;
      delay_for(1);
      GPIOE->BSRR |= GPIO_BSRR_BS13;
      GPIOE->BSRR |= GPIO_BSRR_BR14;
      delay_for(1);
      GPIOE->BSRR |= GPIO_BSRR_BS14;
      GPIOE->BSRR |= GPIO_BSRR_BR15;
      delay_for(1);
      GPIOE->BSRR |= GPIO_BSRR_BS15;
    }
    
    for(counter=0;counter<5;counter++){
      GPIOE->BSRR |= GPIO_BSRR_BR13;
      delay_for(4);
      GPIOE->BSRR |= GPIO_BSRR_BR14;
      delay_for(4);
      GPIOE->BSRR |= GPIO_BSRR_BR15;
      delay_for(4);
      GPIOE->BSRR |= GPIO_BSRR_BS15;
      delay_for(4);
      GPIOE->BSRR |= GPIO_BSRR_BS14;
    }
    
    for(counter=0;counter<10;counter++){
      GPIOE->BSRR |= GPIO_BSRR_BR13|GPIO_BSRR_BR14|GPIO_BSRR_BR15;
      delay_for(1);
      GPIOE->BSRR |= GPIO_BSRR_BS13|GPIO_BSRR_BS14|GPIO_BSRR_BS15;
      delay_for(1);
    }
    
    for(counter=0;counter<4;counter++){
      GPIOE->BSRR |= GPIO_BSRR_BR14;
      delay_for(1);
      GPIOE->BSRR |= GPIO_BSRR_BS14;
      GPIOE->BSRR |= GPIO_BSRR_BR13|GPIO_BSRR_BR15;
      delay_for(2);
      GPIOE->BSRR |= GPIO_BSRR_BS13|GPIO_BSRR_BS15;
      delay_for(3);
    }
    
    delay_for(5);
    
  }
}

/*************************** End of file ****************************/
