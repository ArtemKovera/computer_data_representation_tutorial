#include <stdio.h>

int main()
{
    
    // "myfirststring"    in ASCII or in UTF-8 is  "6d 79 66 69 72 73 74 73 74 72 69 6e 67"
    // "mysecondstring"   in ASCII or in UTF-8 is  "6d 79 73 65 63 6f 6e 64 73 74 72 69 6e 67"
    // "mythirdstring"    in ASCII or in UTF-8 is  "6d 79 74 68 69 72 64 73 74 72 69 6e 67"
    // "myfourthstring"   in ASCII or in UTF-8 is  "6d 79 66 6f 75 72 74 68 73 74 72 69 6e 67"
    // "myfifthstring"    in ASCII or in UTF-8 is  "6d 79 66 69 66 74 68 73 74 72 69 6e 67"

    // UTF-8 code for Д is "D0 94"
    // UTF-8 code for Ї is "D0 87"
    // UTF-8 code for Й is "D0 99"
    // UTF-8 code for α is "CE B1"
    // UTF-8 code for अ is "E0 A4 85"

    const char * str1 = "myfirststringДДДДДmyfirststring";

    const char * str2 = "mysecondstringЇЇЇЇЇmysecondstring";

    const char * str3 = "mythirdstringЙЙЙЙЙmythirdstring";

    const char * str4 = "myfourthstringαααααmyfourthstring";

    const char * str5 = "myfifthstringअअअअअmyfifthstring";

    printf("%s \n", str1);
    printf("%s \n", str2);
    printf("%s \n", str3);
    printf("%s \n", str4);
    printf("%s \n", str5);

    return 0;

}

//gcc representing_and_exploring_utf-8_characters.c
//bless a.out  (other hex editor may be used)

//it is possible to lookup utf-8 codes at https://www.fileformat.info/info/unicode/index.htm