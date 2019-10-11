#define Recursive
#ifndef Recursive 
#include "stdio.h"

int main(){
	int number, fact = 1, i = 0;
	printf("Enter a number: \n");
	scanf("%d",&number);
	for(i = 2; i <= number;i++){
		fact *= i; 
	}
	printf("Factorial of %d is %d \n", number, fact);
	
}
#else 
#include "stdio.h"

int factorial(int n);

int main(){
	int number, fact = 1, i = 0;
	printf("Enter a number: \n");
	scanf("%d",&number);
	for(i = 2; i <= number;i++){
		fact *= i; 
	}
	printf("Factorial of %d is %d \n", number, factorial(number));
	
}

int factorial(int n){
	if(n == 0){
		return 1;
	}
	return (n * factorial(n - 1));
}
#endif

