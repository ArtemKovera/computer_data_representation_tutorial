
/*

    This program explores single
    and double-precision floating-point numbers

*/
#include<stdio.h>
#include<math.h>

//this function expects to accept the void pointer to float
//it prints the bits' values of the single-precision floating-point number
//the sign bit goes on the left, then goes the exponent, the mantissa (fraction) appears on the right
void showBitsInFloat (const void * pointer);

//this function expects to accept the void pointer to double
//it prints the bits' values of the double-precision floating-point number
//the sign bit goes on the left, then goes the exponent, the mantissa (fraction) appears on the right
void showBitsInDouble (const void * pointer);

int main()
{
    printf("\n *****Exloring single-precision numbers (float)***** \n\n");

    float val0 = 0.0;
    printf("0.0:                ");
    showBitsInFloat(&val0);

    float val00 = 0.1;                   //this value cannot be exectly represented in binary
    printf("0.1:                ");
    showBitsInFloat(&val00);

    float val01 = 0.2;                   //this value cannot be exectly represented in binary
    printf("0.2:                ");
    showBitsInFloat(&val01);    

    float val = -0.5;
    printf("-0.5:               ");
    showBitsInFloat(&val);

    float val1 = 0.5;
    printf("0.5:                ");
    showBitsInFloat(&val1);

    float val2 = 0.25;
    printf("0.25:               ");
    showBitsInFloat(&val2);

    float val3 = 0.125;
    printf("0.125:              ");
    showBitsInFloat(&val3);

    float val33 = 0.0625;
    printf("0.0625:             ");
    showBitsInFloat(&val33);

    float val4 = 16780000;
    printf("16780000:           ");
    showBitsInFloat(&val4);

    float val5 = 16780001;
    printf("16780001:           ");
    showBitsInFloat(&val5);

    float val6 = 16780002;   
    printf("16780002:           ");
    showBitsInFloat(&val6); 

    float val7 = 64000000;   
    printf("64000000:           ");
    showBitsInFloat(&val7);   

    float val8 = 64000001;
    printf("64000001:           ");
    showBitsInFloat(&val8);  

    float val9 = 64000002;     
    printf("64000002:           ");
    showBitsInFloat(&val9);  

    float val10 = 64000003;   
    printf("64000003:           ");
    showBitsInFloat(&val10); 

    float val11 = 64000004;     
    printf("64000004:           ");
    showBitsInFloat(&val11);

    float val12 = 64000005;  
    printf("64000005:           ");
    showBitsInFloat(&val12);     

    float val13 = 64000006;    
    printf("64000006:           ");
    showBitsInFloat(&val13);  

    float val14 = NAN; //the macro for nan from math.h (the same value can be obtained as 0.0/0.0)
    printf("Nan:                ");
    showBitsInFloat(&val14);  

    float val15 = 1 / 0.0;
    printf("Positive infinity:  ");
    showBitsInFloat(&val15);  

    float val16 = -1 / 0.0;
    printf("Negative infinity:  ");
    showBitsInFloat(&val16); 

    float val17 = 0.0001 / pow(10, 35);           //Example of a number in a denormalized form
    printf("Denormalized form:  ");   
    showBitsInFloat(&val17);                                                                                              

    printf("------------------------------------------\n");  
    printf("\n *****Exploring double-precision numbers (double)***** \n\n");

    double dval = 0.0;
    printf("0.0:                ");
    showBitsInDouble(&dval);

    double dval2 = 1.0;
    printf("1.0:                ");
    showBitsInDouble(&dval2);   

    double dval3 = -1.0;
    printf("-1.0:               ");
    showBitsInDouble(&dval3);

    double dval4 = 10000000000000000;
    printf("10000000000000000:  ");
    showBitsInDouble(&dval4); 

    double dval5 = 10000000000000001;
    printf("10000000000000001:  ");
    showBitsInDouble(&dval5);

    double dval6 = 10000000000000002;
    printf("10000000000000002:  ");
    showBitsInDouble(&dval6);     

    double dval7 = NAN; //the macro for nan from math.h (the same value can be obtained as 0.0/0.0)
    printf("Nan:                ");
    showBitsInDouble(&dval7); 

    double dval8 = 1 / 0.0;
    printf("Positive infinity:  ");
    showBitsInDouble(&dval8);  

    double dval9 = -1 / 0.0;
    printf("Negative infinity:  ");
    showBitsInDouble(&dval9); 

    double dval10 = 10e-310;           //Example of a number in a denormalized form
    printf("Denormalized form:  ");   
    showBitsInDouble(&dval10); 

    double dval11 = 10e-340;
    printf("Underflow:          ");    //Example of double underflow
    showBitsInDouble(&dval11);

    float fl1 = 10e-47;
    printf("Underflow:          ");    //Example of float underflow
    showBitsInFloat(&fl1);



    return 0;
}

void showBitsInFloat (const void * pointer)
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

void showBitsInDouble (const void * pointer)
{
    unsigned long long int * longIntPoint = (unsigned long long int *) pointer;
    unsigned long long int bitPosition    = 0x8000000000000000;
    unsigned char iteration               = 0;

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
