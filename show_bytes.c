/*
    This program demonstrates using a function that
    shows the hexadecimal byte values of an arbitrary object type
*/
#include<stdio.h>

//this function takes a void pointer and the size of the object in bytes
//the least significant byte is printed first
void showBytes (const void * pointer, const size_t size)
{
    unsigned char * charPointer = (unsigned char*) pointer;
    
    for(size_t i = 0; i < size; i++)
    {
        printf("%.2x ", *charPointer);
        charPointer++;
    }

    printf("\n");    
}

struct IntStruct
{
    int a;
    int b;
};

struct DifferentTypes
{
    char c1;
    int in;
    char c2;
};

struct DifferentTypes2
{
    int in;
    char c1;
    char c2;
};

struct DifferentTypes3
{
    char c1;
    char c2;
    int in;
};


int main ()
{
    
    printf("\nIn these examples, the least significant byte comes first\n\n");
    
    const int var = 1024;
    printf("Showing bytes for int 1024: \n");
    showBytes(&var, sizeof(int));
    printf("\n");
    
    short sh1 = 2;
    printf("Showing bytes for short 2: \n");
    showBytes(&sh1, sizeof(sh1));
    printf("\n");    

    
    short sh2 = -2;
    printf("Showing bytes for short -2: \n");
    showBytes(&sh2, sizeof(sh2));
    printf("\n");


    int int1 = 124;
    printf("Showing bytes for int 124: \n");
    showBytes(&int1, sizeof(int1));
    printf("\n");


    double doub1 = 0.4789;
    printf("Showing bytes for double 0.4789: \n");
    showBytes(&doub1, sizeof(doub1));
    printf("\n");
    

    long double ldoub1 = 0.5;
    printf("Showing bytes for long double 0.5: \n");
    showBytes(&ldoub1, sizeof(ldoub1));
    printf("\n");


    struct IntStruct mystr1;
    mystr1.a = 1;
    mystr1.b = 3;
    printf("Showing bytes for a struct {int 1  int 3}: \n");
    showBytes(&mystr1, sizeof(mystr1));
    printf("\n");


    struct DifferentTypes mystr2;
    mystr2.c1 = 1;
    mystr2.in = 2;
    mystr2.c2 = 3;
    printf("Showing bytes for a struct {char 1  int 2  char 3}: \n");
    showBytes(&mystr2, sizeof(mystr2));
    printf("\n");

    
    struct DifferentTypes2 mystr3;
    mystr3.c1 = 1;
    mystr3.in = 2;
    mystr3.c2 = 3;
    printf("Showing bytes for a struct {int 2  char 1  char 2}: \n");
    showBytes(&mystr3, sizeof(mystr3));
    printf("\n");


    struct DifferentTypes3 mystr4;
    mystr4.c1 = 1;
    mystr4.in = 2;
    mystr4.c2 = 3;
    printf("Showing bytes for a struct {char 1  char 3  int 2}: \n");
    showBytes(&mystr4, sizeof(mystr4));   
    printf("\n");

    
    return 0;
}