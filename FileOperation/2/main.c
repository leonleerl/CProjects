#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fileWrite()
{
    FILE *fp = fopen("file2.txt", "w");
    if (fp == NULL)
    {
        perror("Open Failed:");
        return;
    }
    char str[] = "Hello file22222";
    for (int i = 0; i < strlen(str); ++i)
    {
        char ch = fputc(str[i], fp);
        printf("%c", ch);
    }
}

int main()
{
    fileWrite();
    return 0;
}