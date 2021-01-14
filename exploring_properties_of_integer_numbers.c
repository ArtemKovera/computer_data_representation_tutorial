/*
  
    Program demonstrating properties of integer numbers
  
*/
#include<stdio.h>

//this function prints the bit's values of an arbitrary object
//the least significant bit is printed first
void showBits(void * pointer, size_t size)
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

int main()
{
   printf("\n");
   printf("In these examples the least significant bits come first\n\n");

   unsigned char v1 = 128;
   unsigned char v2 = 128;
   unsigned char v3 = v1 + v2;
   void * p3 = &v3;
   printf("unsigned char 128 + 128 = %u:    ", v3);
   showBits(p3, sizeof(char));

   unsigned char v4 = v1 * v2;
   void * p4 = &v4;
   printf("unsigned char 128 * 128 = %u:    ", v4);
   showBits(p4, sizeof(char));


   signed char v5 = -127;
   signed char v6 = -2;
   signed char v7 = v5 + v6;
   void * p7 = &v7;
   printf("signed char    -127 - 2 = %d:  ", v7);
   showBits(p7, sizeof(char));

   signed char v8 = 127;
   signed char v9 = 127;
   signed char v10 = v8 + v9;
   void * p10 = &v10;
   printf("signed char 127 + 127   =  %d:  ", v10);
   showBits(p10, sizeof(char));

   signed char v11 = 126;
   signed char v12 = 126;
   signed char v13 = v11 + v12;
   void * p13 = &v13;
   printf("signed char 126 + 126   =  %d:  ", v13);
   showBits(p13, sizeof(char)); 

   unsigned int v14 = 0x80000000;
   unsigned int v15 = 0x80000000;
   unsigned int v16 = v14 + v15;
   void * p16 = &v16;
   printf("unsigned int %u + %u = %u: ", v14, v15, v16);
   showBits(p16, sizeof(int));



    return 0;
}