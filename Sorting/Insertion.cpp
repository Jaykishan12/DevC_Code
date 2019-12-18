#include <stdio.h>

int main(){
	int a[5] = { 2,5,6,3,4};
	int value , i = 0,index, no_of_elements;
	
	no_of_elements = sizeof(a) / sizeof(a[0]);
	for(i = 1; i < (no_of_elements); i++){
		value = a[i];
		index  = i;
		while((index > 0) && (a[index - 1] > value))                        // Ascending Order
		{
			a[index] = a[index - 1];
			index = index - 1;
		}
		a[index] = value;
	}
	printf("Sorted Array is\n");
	for(i = 0; i < no_of_elements; i++){
		printf("%d", a[i]);
	}
	
}
