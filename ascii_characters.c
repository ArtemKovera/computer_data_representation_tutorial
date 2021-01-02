/*

    This super simple program outputs the ASCII characters and their decimal and hexadecimal codes

*/

#include<stdio.h>

int main()
{
    char ch = 33;

    while(ch < 127)
    {
        printf("%x - %d - %c\n", ch, ch, ch);
        ch++;
    }

    return 0;
}