#include <stdio.h>

/*
野指针：指针指向的空间未分配
悬空指针：指针指向的空间已分配，但是被释放了
*/

int *method();

int main()
{
    // 野指针
    int a = 10;
    int *p1 = &a;
    printf("%p\n", p1);
    printf("%d\n", *p1);
    // p2是野指针
    int *p2 = p1 + 1;
    printf("%p\n", p2);
    printf("%d\n", *p2);

    // p3是悬空指针
    int *p3 = method();
    printf("拖点时间\n");
    printf("拖点时间\n");
    printf("拖点时间\n");
    printf("拖点时间\n");
    printf("%p\n", p3);
    printf("%d\n", *p3);
    return 0;
}

int *method()
{

    int num = 10;
    int *p = &num;
    return p;
}