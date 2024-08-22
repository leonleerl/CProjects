#include <stdio.h>
#include <stdlib.h>

void fileRead()
{
    FILE *fp = fopen("./file.txt", "r");
    if (fp == NULL)
    {
        perror("open file failed:");
    }
    while (!feof(fp))
    {
        char ch = fgetc(fp);
        printf("%c", ch);
    }

    fclose(fp);
}

int main(int argc, char *argv[])
{
    fileRead();
    return 0;
}