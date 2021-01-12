/*

    This program explores the properties of single
    and double-precision floating-point numbers

*/
#include<stdio.h>

//this function expects to accept the void pointer to float
//it prints the bits' values of the single-precision floating-point number
//the sign bit goes on the left, then goes the exponent, the mantissa (fraction) appears on the right
void showBitsInFloat (void * pointer);

//this function expects to accept the void pointer to double
//it prints the bits' values of the double-precision floating-point number
//the sign bit goes on the left, then goes the exponent, the mantissa (fraction) appears on the right
void showBitsInDouble (void * pointer);

int main()
{
    //adding a small value to a latge value can be dangerous
    float var1 = 1000000;
    float var2 = 1000000;
    printf("\nvar1 befor looping   %f\n", var1); 
    printf("var2 befor looping   %f\n\n", var2);        

    for (int i = 0; i < 1000000; i++)
    {
        var1 += 1;
        var2 += 0.01;
    }

    printf("var1 after looping  %f\n", var1); 
    printf("var2 after looping  %f\n\n", var2); 
    printf("--------------------------------------------------\n\n");

    //comparing floating-point numbers can be dangerous
    float var3 = 0.1;
    double var4 = 0.1;
    
    printf("double var4 = %f | float var3 = %f \n", var4, var3);

    if (var3 == var4)
    {
        printf("var3 and var4 are equal \n");
    }
    else if (var4 > var3)
    {
        printf("var4 is greater than var3 \n");
    }
    else if (var3 > var4)
    {
        printf("var3 is greater than var4 \n");
    }
    
    printf("\n");
    void * p3 = &var3;
    void * p4 = &var4;
    printf("va3 in binary: ");
    showBitsInFloat(p3);
    printf("var4 in binary: ");
    showBitsInDouble(p4);

    /////////////////////////////////////////////
    printf("---------\n");
    float var5 = 0.2;
    double var6 = 0.2;
    
    printf("double var6 = %f | float var5 = %f \n", var6, var5);

    if (var6 == var5)
    {
        printf("var6 and var5 are equal \n");
    }
    else if (var6 > var5)
    {
        printf("var6 is greater than var5 \n");
    }
    else if (var5 > var6)
    {
        printf("var5 is greater than var6 \n");
    }

    printf("\n");
    void * p5 = &var5;
    void * p6 = &var6;
    printf("va5 in binary: ");
    showBitsInFloat(p5);
    printf("var6 in binary: ");
    showBitsInDouble(p6);

    //////////////////////////////////////
    printf("---------\n");

    float var7 = 0.5;
    double var8 = 0.5;
    
    printf("double var8 = %f | float var7 = %f \n", var8, var7);

    if (var7 == var8)
    {
        printf("var7 and var8 are equal \n");
    }
    else if (var8 > var7)
    {
        printf("var8 is greater than var7 \n");
    }
    else if (var7 > var8)
    {
        printf("var7 is greater than var8 \n");
    }

    printf("\n");
    void * p7 = &var7;
    void * p8 = &var8;
    printf("var7 in binary: ");
    showBitsInFloat(p7);
    printf("var8 in binary: ");
    showBitsInDouble(p8);

    printf("--------------------------------------------------\n\n");

    //distributive rule does not necessarily apply
    double y = 0.11;
    double x = 0.22;
    double z = 0.33;
    double r1 = y * x + y * z;
    double r2 = y * (x + z);
    void * pr1 = &r1;
    void * pr2 = &r2;
     
    printf("r1 = y * x + y * z =  %f\n", r1);
    printf("r2 = y * (x + z)   =  %f\n\n", r2);

    if (r1 != r2)
        printf("r1 and r2 are NOT equal\n\n");
    
    printf("r1 in binary:  ");
    showBitsInDouble(pr1);
    printf("r2 in binary:  ");
    showBitsInDouble(pr2);

    printf("--------------------------------------------------\n\n");

    //associative rule does not necessarily apply
    double a = 0.1111;
    double b = 0.2222;
    double c = 0.3333;
    double res1 = (a + b) + c;
    double res2 = a + (b + c);
    void * pres1 = &res1;
    void * pres2 = &res2;
     
    printf("res1 = (a + b) + c  =  %f\n", res1);
    printf("res2 = (c + a) + b  =  %f\n\n", res2);

    if (res1 != res2)
        printf("res1 and res2 are NOT equal\n\n");
    
    printf("res1 in binary:  ");
    showBitsInDouble(pres1);
    printf("res2 in binary:  ");
    showBitsInDouble(pres2);



    return 0;
}

void showBitsInFloat (void * pointer)
{
    unsigned int * intPoint  = (unsigned int *) pointer;
    unsigned int bitPosition = 0x80000000;
    unsigned char iteration  = 0;
    

    while(iteration<32)
    {
        if(bitPosition & *intPoint)
            printf("1");
        else
            printf("0"); 
        
        if(iteration == 0 || iteration == 8)
            printf(" ");

        bitPosition >>= 1;
        iteration++;             
    }

    printf("\n\n");    
} 

void showBitsInDouble (void * pointer)
{
    unsigned long int * longIntPoint = (unsigned long int *) pointer;
    unsigned long int bitPosition    = 0x8000000000000000;
    unsigned char iteration          = 0;

    while(iteration<64)
    {
        if(bitPosition & *longIntPoint)
            printf("1");
        else
            printf("0"); 
        
        if(iteration == 0 || iteration == 11)
            printf(" ");

        bitPosition >>= 1;
        iteration++;             
    }

    printf("\n\n"); 
}

