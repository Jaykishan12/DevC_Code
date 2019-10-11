#include<stdio.h>
#include <conio.h>
#include <stdint.h>

typedef struct __HEARDER {
  char Text[50];
  uint8_t Font;
  uint8_t Width;
  uint8_t Height;
  uint8_t Alingment;
}  __attribute__((__packed__))  HEARDERDATA;

typedef struct __CONFIG {
	HEARDERDATA Header[10];
	HEARDERDATA Footer[10];
	uint32_t CheckSum;
	uint32_t CheckSumHF;
	uint32_t CheckSumLogo;
	uint32_t CheckSumPassword;
 } __attribute__((__packed__))   CONFIGURATIONDATA;

int main(){
	CONFIGURATIONDATA *HFData = 0x00;
	uint32_t AddressValue = 0;
	AddressValue =(uint32_t) (&HFData->CheckSum);
	printf("%p\n",AddressValue);
		printf("%p\n",&(HFData->CheckSumHF));
		printf("%d\r\n",&(HFData->CheckSumHF));
	//		printf("%d",HFData->&CheckSum);	
}
