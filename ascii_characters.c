/*

    This super simple program outputs the ASCII characters and their decimal and hexadecimal codes

*/

#include<stdio.h>

int main()
{
    unsigned char ch = 33;

    while(ch < 128)
    {
        printf("%x - %d - %c\n", ch, ch, ch);
        ch++;
    }


    return 0;
}