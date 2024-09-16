#include <stdio.h>
#include <string.h>

int main()
{
    char str1[10] = "abc";
    char str2[4] = "DEF";
    // strcat(str1, str2);
    printf("%s\n", str1);
    printf("%s\n", str2);
    strcpy(str1, str2);
    printf("%s\n", str1);
    printf("%s\n", str2);

    return 0;
}