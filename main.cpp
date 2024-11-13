#include "LPC1768_Includes.h"
 #include "UART.h"
 #include <stdio.h>
 }
 
 void RTC_init(void)
 {
 CIIR = 0x00;   
CCR = 0x11; 
}
 void RTC_SetTime(int hours, int mins, int sec)
 {
 SEC  = sec;  
MIN  = mins; 
HOUR = hours; 
CCR =  0x11; 
}
 void RTC_GetTime(int *hour, int *min, int *sec)
 {
 *sec = SEC;
 *min = MIN;
 *hour = HOUR;
 }
 void delay(unsigned int time)
 {
 unsigned int i,j;
 for(i=0;i<time;i++)
 for(j=0;j<10000;j++);
 // no interrupt
 // program the secs
 // program the mins
 // program the hours
 // start the clock
int main()
 {
 int hours, min, sec;
 UartInit(9600);
 RTC_init();
 RTC_SetTime(0x03, 0x10, 0x01);
 printf("RTC Program\r\n");
 while(1)
 {
               RTC_GetTime(&hours, &min, &sec);
               printf("Time: %02x:%02x:%02x\r\n",hours, min, sec);
               delay(600); 
 }
 }
