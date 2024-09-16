#include <stdio.h>

int main()
{

    int a = 10;
    int *p = &a;

    printf("%p\n", p);
    printf("%p\n", p + 1);
    printf("%p\n", p + 2);
    printf("%p\n", p + 3);
    return 0;
}