#include <stdio.h>
#include <string.h>

int main()
{

    FILE *fileA = fopen("./a.txt", "r");
    FILE *fileB = fopen("./b.txt", "w");
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fileA))
    {
        printf("%s", buffer);
        fputs(buffer, fileB);
    }

    return 0;
}