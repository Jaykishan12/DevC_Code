#include <stdio.h>
int main()
{
    int i, space, rows, k=0;
       for( i = 1; i <= 3; i++){
    	printf("%d ",i);
	}
	 i= 0;
	while( ++i < 3){
		printf("%d",i);
	}
	i = 0;
    printf("Enter number of rows: ");
    scanf("%d",&rows);
    for(i=1; i<=rows; ++i, k=0)                                                // 5  i = 2
    {
        for(space=1; space<=rows-i; ++space)                                  // space <= 4
        {
            printf("  ");
        }
        while(k != 2*i-1)                                                    // 2 * 1 - 1  = 1 
        {
            printf("* ");
            ++k;
        }
        printf("\n");
    }
    
    return 0;
}
