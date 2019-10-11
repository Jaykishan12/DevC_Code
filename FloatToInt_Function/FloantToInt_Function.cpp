#include <stdio.h>
#include "conio.h"
#include "math.h"
#include <string.h>
#include <ctype.h>
	
float str2float (const char * str) {
  unsigned char abc;
  float ret = 0, fac = 1;
  for (abc = 9; abc & 1; str++) {
    abc  =  *str == '-' ?
              (abc & 6 ? abc & 14 : (abc & 47) | 36)
            : *str == '+' ?
              (abc & 6 ? abc & 14 : (abc & 15) | 4)
            : *str > 47 && *str < 58 ?
              abc | 18
            : (abc & 8) && *str == '.' ?
              (abc & 39) | 2
            : !(abc & 2) && (*str == ' ' || *str == '\t') ?
              (abc & 47) | 1
            :
              abc & 46;
    if (abc & 16) {
      ret = abc & 8 ? *str - 48 + ret * 10 : (*str - 48) / (fac *= 10) + ret;
    }
  }
  return abc & 32 ? -ret : ret;
}

/* simple one */
double Myatof1(char str[]){

	int len=0, n=0,i=0;
	float f=1.0,val=0.0;
	
	while(str[len])len++;

	if(!len)return 0;
	
	while(i<len && str[i]!='.')
	    n=10*n +(str[i++]-'0');
	
	if(i==len) return n;
	i++;
	while(i<len)
	{
	    f*=0.1;
	    val+=f*(str[i++]-'0');
	}
	    return(val+n);
}

double myatof(char *str)
{
    int i=0;int len1,len2,j;
    float num=0.0;float num1=0.0; float num2=0.0;

    do
    {
        if((str[i++]=='.'))
        {
            len1=i-1;len2=-((strlen(str)-1)-(i-1));

            for(int p=0,q=(len1-1);p<len1,q>=0;p++,q--)
            {
                num1+=((str[p]-'0')*pow(10,q));
            }
            for(int r=len1+1,s=-1;r<strlen(str),s>=len2;r++,s--)
            {
                num2+=((str[r]-'0')*pow(10,s));
            }
        }
    }while(str[i]!='\0');

    num=num1+num2;
    printf("%f\t",num1);
    printf("%f\t",num2);
    return num;
}

/* atof: convert string s to double */
double user_atof(char s[])
{
    double val, power;
    int i, sign;
for (i = 0; isspace(s[i]); i++)
    ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}

int main(){
	char Buffer[] = "233.0035479999";
	double Amount = 0;
	Amount = user_atof(Buffer);
	printf("Amount Value = %lf",Amount);
}
