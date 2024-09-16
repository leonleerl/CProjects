#include <stdio.h>

void swap(int *a, int *b);
int main()
{
    int a = 10;
    int b = 30;
    printf("%d\n", a);
    printf("%d\n", b);
    swap(&a, &b);
    printf("%d\n", a);
    printf("%d\n", b);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}