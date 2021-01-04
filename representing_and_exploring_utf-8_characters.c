#include <stdio.h>

int main()
{
    // "myfirststring"    in ASCII is "6d 79 66 69 72 73 74 73 74 72 69 6e 67"
    // "mysecondstring"   in ASCII is "6d 79 73 65 63 6f 6e 64 73 74 72 69 6e 67"
    // "mythirdstring"    in ASCII is "6d 79 74 68 69 72 64 73 74 72 69 6e 67"

    const char * str1 = "myfirststringДДДДДmyfirststring";

    const char * str2 = "mysecondstringЇЇЇЇЇmysecondstring";

    const char * str3 = "mythirdstringЙЙЙЙЙmythirdstring";

    printf("%s \n", str1);
    printf("%s \n", str2);
    printf("%s \n", str3);
    

    return 0;

}

//gcc representing_and_exploring_utf-8_characters.c
//bless a.out