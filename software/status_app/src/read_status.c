#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xgpio.h"
#include "xparameters.h"
#include "unistd.h"


int main(void)
{
    //init_platform();
    XGpio dip, push;
    int psb_check, dip_check;

    xil_printf("--Start of the Program--\r\n");
    XGpio_Initialize(&dip,XPAR_GPIO_0_DEVICE_ID);
    XGpio_SetDataDirection(&dip,1,0xffffffff);

    XGpio_Initialize(&push,XPAR_GPIO_1_DEVICE_ID);
    XGpio_SetDataDirection(&push,1,0xffffffff);
    while (1)
    {
    	psb_check = XGpio_DiscreteRead(&push,1);
    	xil_printf("Push Buttons Status %x\r\n", psb_check);

    	dip_check = XGpio_DiscreteRead(&dip,1);
    	xil_printf("DIP Switch Status %x\r\n", dip_check);
    	sleep(1);
    }
   // cleanup_platform();
}
