#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length(char s[])
{
    int count = 0;
    while (s[count] != '\0')
    {
        count++;
    }
    return count;
}

int main(int argc, char *argv[])
{
    char s[] = "hello";
    int res = length(s);
    printf("%d\n", res);
    return 0;
}
