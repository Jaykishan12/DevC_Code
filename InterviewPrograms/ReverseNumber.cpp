#include "stdio.h"

int main(){
	int number = 0, temp = 0, digit = 0, ReversedNumber = 0, n = 0;
	
	printf("Enter a number :\n");
	scanf("%d", &number);
	temp = number;
	while(temp > 0){
	   digit = temp % 10;  
	   ReversedNumber = (ReversedNumber * 10 ) + digit;
	   temp = temp / 10;	
	}
	printf("REVERSED NUMBER %d", ReversedNumber);
}
