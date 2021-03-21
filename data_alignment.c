#include<stdio.h>

// #pragma pack(1)

typedef struct
{
    int i;
    char x;
    char e;

}str1;

typedef struct 
{
    char a;
    int f;
    char d;

}str2;




int main()
{
    /*
    int var = 123;
    int * p = &var;
    
    printf("address - %p\n", p);
    */
    
    
    printf ("str1 occupies %ld bytes\n", sizeof(str1));
    printf ("str2 occupies %ld bytes\n", sizeof(str2));
    

    return 0; 
}