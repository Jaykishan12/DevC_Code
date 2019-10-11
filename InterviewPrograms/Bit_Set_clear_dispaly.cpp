#include <stdio.h>
#include <string.h>
#include <stdint.h>
bool TRUE = 1 , FALSE = !TRUE;
// Display Every bits in a int number 



// test a bit if it is zero or one 
int8_t testBit(int value,int whichBit)
{
    int mask = 1 << whichBit;
    if (value&mask)
    {
        return TRUE;
    }
    else return FALSE;
}
void displayBits(int data)
{
    int dataSize = 1<<sizeof(data);
    int count = 0;
    for (count = dataSize - 1;count >= 0; count--)
    {
        printf("%d",(testBit(data,count)));
    }
}


// Set a bit to one 
int8_t setBit(int8_t result, int whichBit)
{
    return (result |= (1<<whichBit));
}

// toggle a bit  
int8_t toggleBit(int8_t result, int whichBit)
{
    return (result ^= (1<<whichBit));
}

/* Clear a bit to zero */
int8_t clearBit(int8_t result, int whichBit)
{
    return (result &=~ (1<<whichBit));
}

int main(void)
{
	displayBits(0xfe);
	setBit(0xfe, 15);
	displayBits(0xfe);
}
