#include <stdio.h>

void swap(void *a, void *b, int length)
{
    // 把void类型指针转为char类型
    char *pc1 = a;
    char *pc2 = b;
}

int main()
{
    int a = 10;
    int *p = &a;

    int **pp = &p;

    printf("%d\n", **pp);

    return 0;
}