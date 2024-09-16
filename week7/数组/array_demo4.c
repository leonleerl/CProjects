#include <stdio.h>
void method1();
int method2(int a, int b);

int main()
{
    void (*p1)() = method1;
    int (*p2)(int, int) = method2;

    p1();
    int res = p2(32, 99);
    printf("%d\n", res);
    return 0;
}

void method1()
{
    printf("method1\n");
}

int method2(int a, int b)
{
    printf("method2\n");
    return a + b;
}