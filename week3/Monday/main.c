#include <stdio.h>
#define N 20

int myarray[N];
int evensum = 0;

void my_strcpy(char destination[], char source[]);

int main(int argc, char *argv[])
{
    char destination[N];
    char source[N] = "Hello World";
    char month[] = {'1', 'a', '4'};

    my_strcpy(destination, source);

    return 0;
}