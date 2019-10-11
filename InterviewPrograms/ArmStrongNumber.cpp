
/* Armstrong number is sum of cubes of its digits */

#include "stdio.h"

int main(){
	int number, armstrongSum = 0, temp = 0, digits = 0;
	printf("Enter a number :\n");
	scanf("%d", &number);
	temp = number;
	while(temp > 0){
		digits = temp % 10;
		armstrongSum += digits * digits * digits;
		temp = temp / 10;
	}
	if(armstrongSum == number){
		printf("Number is armstrong");
	}else{
		printf("Number is not armstrong");
	}
}
