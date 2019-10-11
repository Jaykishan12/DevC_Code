#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
	int row1, col1, row2,col2, *ptr1, *ptr2, *ptr3, i = 0, j = 0;
	printf("enter Row 1:\n");
	scanf("%d", &row1);
	printf("enter column1 :\n");
	scanf("%d", &col1);
	ptr1 = (int *) malloc(row1 * col1  * sizeof(int));
	printf("enter Row 2:\n");
	scanf("%d", &row2);
	printf("enter column 2 :\n");
	scanf("%d", &col2);
	ptr2 = (int *) malloc(row2 * col2  * sizeof(int));
	if(col1 != row2){
		printf("Invalid Multiplication");
		return 0;
	}
	printf("Enter Matrix 1:\n");
	for(i = 0;i < row1; i++){
		for(j = 0; j < col1; j++){
			scanf("%d",(ptr1 + i + j));
		}
	}
	for(i = 0;i < row1; i++){
		printf("\n");
		for(j = 0; j < col1; j++){
			printf("%d\t", *(ptr1 + i + j));
		}
	}
	
	printf("Enter Matrix 2:\n");
	for(i = 0;i < row2; i++){
		for(j = 0; j < col2; j++){
			scanf("%d",(ptr2 + i + j));
			printf("%d", *(ptr2 + i + j));
		}
	}
	for(i = 0;i < row2; i++){
		printf("\n");
		for(j = 0; j < col2; j++){
			printf("%d\t", *(ptr2 + i + j));
		}
	}
}
