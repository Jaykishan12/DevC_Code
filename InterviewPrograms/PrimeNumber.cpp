#include "stdio.h"

int main(){
	int number,validation = 1, n =0;
	printf("Enter Number :\n");
	scanf("%d",&number);
	do{
		for(n = 2;n <= (number / 2); n++){
			validation = number % n;
			if(validation == 0)
			{
				break;
			}
		}
	}while(0);
	if(validation == 0){
		printf("Not a Prime Number");
	}else{
		printf("Prime Number");
	}
}
