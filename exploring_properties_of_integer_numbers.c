/*
  
    Program demonstrating properties of integer numbers
  
*/
#include<stdio.h>

//this function takes a pointer to an arbitrary object and the of this object in bytes
//this function prints the bit's values of an arbitrary object
//the least significant bit is printed first
void showBits(const void * pointer, size_t size)
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

   printf("Wraparound behaviour and overflow\n\n");

   unsigned char v1 = 128;
   unsigned char v2 = 128;
   unsigned char v3 = v1 + v2;
   printf("unsigned char 128 + 128 = %u:    ", v3);
   showBits(&v3, sizeof(char));

   unsigned char v4 = v1 * v2;
   printf("unsigned char 128 * 128 = %u:    ", v4);
   showBits(&v4, sizeof(char));


   signed char v5 = -127;
   signed char v6 = -2;
   signed char v7 = v5 + v6;                              //undefined behaviour
   printf("signed char    -127 - 2 = %d:  ", v7);   
   showBits(&v7, sizeof(char));

   signed char v8 = 127;
   signed char v9 = 127;
   signed char v10 = v8 + v9;                             //undefined behaviour
   printf("signed char 127 + 127   =  %d:  ", v10);
   showBits(&v10, sizeof(char));

   signed char v11 = 126;
   signed char v12 = 126;
   signed char v13 = v11 + v12;                           //undefined behaviour
   printf("signed char 126 + 126   =  %d:  ", v13);
   showBits(&v13, sizeof(char)); 

   unsigned int v14 = 0x80000000;
   unsigned int v15 = 0x80000000;
   unsigned int v16 = v14 + v15;
   printf("unsigned int %u + %u = %u: ", v14, v15, v16);
   showBits(&v16, sizeof(int));

   printf("------------------------------------\n\n");

   printf("Integer casts examples\n\n");

   signed short v17 = 4;
   signed int   v18 = (signed int) v17;
   printf("(signed int) signed short %d:  ", v18);
   showBits(&v18, sizeof(int));

   signed short v19 = -4;
   signed int   v20 = (signed int) v19;
   printf("(signed int) signed short %d: ", v20);
   showBits(&v20, sizeof(int)); 

    return 0;
}