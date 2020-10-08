
/**************************************************

file: demo_rx.c
purpose: simple demo that receives characters from
the serial port and print them on the screen,
exit the program by pressing Ctrl-C

compile with the command: gcc demo_rx.c rs232.c -Wall -Wextra -o2 -o test_rx

**************************************************/

include <stdlib.h>
include <stdio.h>

ifdef _WIN32
include <Windows.h>
else
include <unistd.h>
endif

include "rs232.h"



int main()
{
  int i, n,
      cport_nr=16,        /* /dev/ttyS0 (COM1 on windows) */
      bdrate=9600;       /* 9600 baud */

  unsigned char buf[4096];

  char mode[]={'8','N','1',0};


  if(RS232_OpenComport(cport_nr, bdrate, mode, 0))
  {
    printf("Não foi possivel iniciar a comunicação serial\n");
    return(0);
  }

  while(1)
  {
    n = RS232_PollComport(cport_nr, buf, 4095);
  
      printf(" %s\n",(char *)buf);
    }

    usleep(100000);  // sleep for 100 milliSeconds 
  }

  return(0);
}

