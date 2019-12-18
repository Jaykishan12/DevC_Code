#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum {
	BubbleSort, SelectionSort
}SortingTechnique;

typedef enum {
	AscendingOrder, DescendingOrder
}SortingOrder;

void SortingTechniques(int a[],int size, SortingTechnique type, SortingOrder Order);
void swap(int *a, int *b);
void printarray(int a[], int len);

int main(){
	int size = 0;
	int a[] = { 5, 6 , 10 , 9 , 8};
	size = sizeof(a) / sizeof(a[0]);
	SortingTechniques(a,size,BubbleSort, AscendingOrder);
	printarray(a,size);
	int b[] = { 1, 6 , 10 , 9 , 2};
	printf("Descending Order\n");
	SortingTechniques(b,size,BubbleSort,DescendingOrder);
	printarray(b,size);
}


void SortingTechniques(int a[],int size, SortingTechnique type, SortingOrder Order){
	int i, j, index;
	
	switch(Order){
		case AscendingOrder :
			 	if(type == SelectionSort)
				{
					for(i = 0; i < size - 1; i++){                          //         5, 9, 13, 17 and 21 are arranged in ascending order.
						index = i;
						for(j = i + 1; j < size; j++){
							if(a[j] < a[index]){
								index = j;
							}
						}
						swap(&a[i],&a[index]);	
					}
				}else if(type == BubbleSort){
					for(i = 0; i < size; i++){
						for(j = 0; j < size - 1 - i; j++){
							if(a[j] > a[j + 1]){
								swap(&a[j],&a[j + 1]);
							}
						}
					}
				}
			break;
		case DescendingOrder:                           
				if(type == SelectionSort){
					for(i = 0;  i < size - 1; i++){
						index = i;
						for(j = i + 1; j < size; j++){
							if(a[j] > a[index]){														//          21, 17, 13, 9 and 3 are arranged in ascending order.
								index = j;
							}
						}
						swap(&a[index], &a[i]);
					}
				}else if(type == BubbleSort){
					for(i = 0; i < size; i++){
						for(j = 0; j < (size - 1 - i); j++){
							if(a[j] < a[j + 1]){
								swap(&a[j],&a[j + 1]);
							}
						}
					}
				}
			break;
		default : break;
	}
}

void swap(int *a, int *b){
	int temp;
	
//	*a = *a + *b;
//	*b = *a - *b;
//	*a = *a - *b;
	temp = *a;
	*a = *b;
	*b = temp;
}

void printarray(int a[], int len){
	int i = 0;
	for( i = 0; i < len; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n");
}
