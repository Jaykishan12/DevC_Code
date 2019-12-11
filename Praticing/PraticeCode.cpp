#include <stdio.h>
#include <stdlib.h>
int main(){
	int a[5] = {1, 2, 3, 4, 5};
	int i = 0, No_of_Elements = 0, int_size = 0, pointer_address_int, pointer_address_char, pointer_address_double;
	double Temp = 0;
	const char *char_Temp = "kishan";
	char *const char_Temp_const_point = "Kishan";
	char Character = 'A';
	int c = 10;
	int b = 20;
	int const *Int_IPC = &c;
	int *const Int_PCI = &b;
	char *Temp_char = NULL;
	
	Temp_char = (char *)calloc(10,sizeof(char));
	Temp_char = "crash";
	char *const Temp_const_point = Temp_char;
//	Temp_const_point = (char *)malloc(10);
	char_Temp = "vishal";
	char_Temp = "VishaL";
//	char_Temp[0] = 'J';   This cannot be done since const char * is used i.e pointer to a constant charcter is used
//	char_Temp_const_point[1] = 'J';
	No_of_Elements = ((char *)(a + 5) - (char *)a) ; 
	int_size = sizeof(int);
	pointer_address_int = sizeof(int *);
	pointer_address_char = sizeof(char *);
	pointer_address_double = sizeof(double *);
	printf("No_of_elements = %d\n sizeofint = %d\n", No_of_Elements, int_size);
	printf("Printing Out of array index = %d\n", a[5]);
	printf("Pointer Address = %d %d %d\n", pointer_address_int, pointer_address_char, pointer_address_double);
	printf("String Printing %c %s %s %s %s\n",char_Temp_const_point[4],char_Temp, char_Temp_const_point,Temp_const_point,Temp_char);  //
	printf("Integer Values For Const Pointer = %d %d", *Int_IPC, *Int_PCI); 
	
//	*Int_IPC = 30;    Gives Compilation Error read-only location

	//for(i = 0, i < )
}
