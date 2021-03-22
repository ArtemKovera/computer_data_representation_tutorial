
/*
    This program demonstrates using a function that
    shows the bits' values of any type of an object    
*/
#include<stdio.h>

//this function prints bits' values of any object.
//the least significant bit is printed on the left 
void showBits(const void * pointer, const size_t size)
{
    unsigned char * charPointer = (unsigned char *) pointer;
    unsigned char bitPosition;
    unsigned char bitCount;

    for(size_t i = 0; i < size; i++)
    {
        unsigned char byte = *charPointer;
        bitPosition = 1; 

        for(bitCount = 0; bitCount < 8; bitCount++)
        {
            if(bitPosition & byte)
                printf("1");
            else
                printf("0");

            bitPosition <<= 1;
        }
         
        if(i==7)
           printf("\n");  
        else
           printf(" ");


        charPointer++;
    }  
        printf("\n\n");
}

int main ()
{
    printf("\n");

    char v0 = 16;
    printf("char 16:      ");
    showBits(&v0, sizeof(char));

    signed char v1 = -16;
    printf("char -16:     ");
    showBits(&v1, sizeof(signed char));
    
    short v2 = 2;
    printf("short 2:      ");
    showBits(&v2, sizeof(short));

    short v3 = -2;
    printf("short -2:     ");
    showBits(&v3, sizeof(short));    

    int v4 = 256;
    printf("int 256:      ");
    showBits(&v4, sizeof(int));
    
    float v5 = 256.0;
    printf("float 256.0:  ");
    showBits(&v5, sizeof(float));

    float v6 = 0.20;
    printf("float 0.20:   ");
    showBits(&v6, sizeof(float));

    float v7 = -0.20;
    printf("float -0.20:  ");
    showBits(&v7, sizeof(float));

    long double v8 = 0.50;
    long double * p8 = &v8;
    printf("long double 0.50:\n");
    showBits(&v8, sizeof(long double));

    long double ** p9 = &p8;
    printf("a pointer:\n");
    showBits(p9, sizeof(p8));
     
  
    return 0;
}