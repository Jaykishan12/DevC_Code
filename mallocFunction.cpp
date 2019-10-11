#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
#include "stdint.h"
#include "conio.h"

 typedef struct controllerID{
	 uint32_t result[4];
 }CONTROLLERID;
 
int main()
{
	CONTROLLERID Controller_ID;
	char Buffer[(sizeof(CONTROLLERID) * 2) + 1];
	Controller_ID.result[0] = 1234;
	Controller_ID.result[1] = 123;
	Controller_ID.result[2] = 12345;
	Controller_ID.result[3] = 12346;
	
//	memset(Buffer, 0x00 ,sizeof(Buffer));
sprintf(Buffer,"%04x%04x%04x%04x",Controller_ID.result[0],Controller_ID.result[1],Controller_ID.result[2],Controller_ID.result[3]);
	printf(Buffer);
        /*printf("%p\n",(int *) malloc(0));
        printf("%p\n", realloc(malloc(0), 0));*/
        return 0;
}
