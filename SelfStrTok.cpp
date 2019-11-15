#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	int i = 0;
	char Buffer[]= "Hello how are You";
	char *Token[5];
	char *rest = Buffer;
	for(i = 0; i < 5; i++){
		Token[0] = (char *) malloc(10 * sizeof(char));
	}
	Token[0] = strtok(Buffer," ");
	while(Token != NULL){
		printf("%s",Token[i]);
		i++;
	    Token[i] = strtok(NULL," ");
	}
}
