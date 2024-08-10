#include <string.h>
void my_strcpy(char destination[], char source[])
{
    int length = strlen(source);

    for (int i = 0; i < length; i++)
    {
        destination[i] = source[i];
    }
    destination[length] = '\0';
}