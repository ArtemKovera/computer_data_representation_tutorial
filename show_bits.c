
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
    char * p0 = &v0;
    printf("char 16:      ");
    showBits(p0, sizeof(char));

    signed char v1 = -16;
    signed char * p1 = &v1;
    printf("char -16:     ");
    showBits(p1, sizeof(signed char));
    
    short v2 = 2;
    short * p2 = &v2;
    printf("short 2:      ");
    showBits(p2, sizeof(short));

    short v3 = -2;
    short * p3 = &v3;
    printf("short -2:     ");
    showBits(p3, sizeof(short));    

    int v4 = 256;
    int * p4 = &v4;
    printf("int 256:      ");
    showBits(p4, sizeof(int));
    
    float v5 = 256.0;
    float * p5 = &v5;
    printf("float 256.0:  ");
    showBits(p5, sizeof(float));

    float v6 = 0.20;
    float * p6 = &v6;
    printf("float 0.20:   ");
    showBits(p6, sizeof(float));

    float v7 = -0.20;
    float * p7 = &v7;
    printf("float -0.20:  ");
    showBits(p7, sizeof(float));

    long double v8 = 0.50;
    long double * p8 = &v8;
    printf("long double 0.50:\n");
    showBits(p8, sizeof(long double));

    long double ** p9 = &p8;
    printf("a pointer:\n");
    showBits(p9, sizeof(p8));
     
  
    return 0;
}