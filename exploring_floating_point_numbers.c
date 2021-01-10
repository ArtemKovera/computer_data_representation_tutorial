
/*

    This program explores single
    and double-precision floating-point numbers

*/
#include<stdio.h>
#include<math.h>

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
    printf("\n *****Exloring single-precision numbers (float)***** \n\n");

    float val0 = 0.0;
    void * p0 = &val0;
    printf("0.0:                ");
    showBitsInFloat(p0);

    float val = -0.5;
    void * p = &val;
    printf("-0.5:               ");
    showBitsInFloat(p);

    float val1 = 0.5;
    void * p1 = &val1;
    printf("0.5:                ");
    showBitsInFloat(p1);

    float val2 = 0.25;
    void * p2 = &val2;
    printf("0.25:               ");
    showBitsInFloat(p2);

    float val3 = 0.125;
    void * p3 = &val3;
    printf("0.125:              ");
    showBitsInFloat(p3);

    float val33 = 0.0625;
    void * p33 = &val33;
    printf("0.0625:             ");
    showBitsInFloat(p33);

    float val4 = 16780000;
    void * p4 = &val4;
    printf("16780000:           ");
    showBitsInFloat(p4);

    float val5 = 16780001;
    void * p5 = &val5;
    printf("16780001:           ");
    showBitsInFloat(p5);

    float val6 = 16780002;
    void * p6 = &val6;     
    printf("16780002:           ");
    showBitsInFloat(p6); 

    float val7 = 64000000;
    void * p7 = &val7;     
    printf("64000000:           ");
    showBitsInFloat(p7);   

    float val8 = 64000001;
    void * p8 = &val8;     
    printf("64000001:           ");
    showBitsInFloat(p8);  

    float val9 = 64000002;
    void * p9 = &val9;     
    printf("64000002:           ");
    showBitsInFloat(p9);  

    float val10 = 64000003;
    void * p10 = &val10;     
    printf("64000003:           ");
    showBitsInFloat(p10); 

    float val11 = 64000004;
    void * p11 = &val11;     
    printf("64000004:           ");
    showBitsInFloat(p11);

    float val12 = 64000005;
    void * p12 = &val12;     
    printf("64000005:           ");
    showBitsInFloat(p12);     

    float val13 = 64000006;
    void * p13 = &val13;     
    printf("64000006:           ");
    showBitsInFloat(p13);  

    float val14 = NAN; //the macro for nan from math.h (the same value can be obtained as 0.0/0.0)
    void * p14 = &val14;
    printf("Nan:                ");
    showBitsInFloat(p14);  

    float val15 = 1 / 0.0;
    void * p15 = &val15;
    printf("Positive infinity:  ");
    showBitsInFloat(p15);  

    float val16 = -1 / 0.0;
    void * p16 = &val16;
    printf("Negative infinity:  ");
    showBitsInFloat(p16);                                                                                       

    printf("------------------------------------------\n");  
    printf("\n *****Exploring double-precision numbers (double)***** \n\n");

    double dval = 0.0;
    void * dp = &dval;
    printf("0.0:                ");
    showBitsInDouble(dp);

    double dval2 = 1.0;
    void * dp2 = &dval2;
    printf("1.0:                ");
    showBitsInDouble(dp2);   

    double dval3 = -1.0;
    void * dp3 = &dval3;
    printf("-1.0:               ");
    showBitsInDouble(dp3);

    double dval4 = 10000000000000000;
    void * dp4 = &dval4;
    printf("10000000000000000:  ");
    showBitsInDouble(dp4); 

    double dval5 = 10000000000000001;
    void * dp5 = &dval5;
    printf("10000000000000001:  ");
    showBitsInDouble(dp5);

    double dval6 = 10000000000000002;
    void * dp6 = &dval6;
    printf("10000000000000002:  ");
    showBitsInDouble(dp6);     

    double dval7 = NAN; //the macro for nan from math.h (the same value can be obtained as 0.0/0.0)
    void * dp7 = &dval7;
    printf("Nan:                ");
    showBitsInDouble(dp7); 

    double dval8 = 1 / 0.0;
    void * dp8 = &dval8;
    printf("Positive infinity:  ");
    showBitsInDouble(dp8);  

    double dval9 = -1 / 0.0;
    void * dp9 = &dval9;
    printf("Negative infinity:  ");
    showBitsInDouble(dp9);      

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
