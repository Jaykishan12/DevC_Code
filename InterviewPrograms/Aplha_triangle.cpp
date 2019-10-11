#include <stdio.h>
#include <conio.h>

int main(){
	char alphabet;
	int triangle_height = 0 , i = 0, j = 0;
	printf("Enter Start Alphabet:\n");
	scanf("%c",&alphabet);
	printf("Enter Height:\n");
	scanf("%d",&triangle_height);
	for( i = 0; i < triangle_height; i++){
		printf("\n");
		for(j = 0; j < i; j++){
			printf("%c",alphabet);
			alphabet++;
		}	
	}
	return alphabet;
}
