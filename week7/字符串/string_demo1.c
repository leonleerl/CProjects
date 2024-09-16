#include <stdio.h>

int main()
{
    char arr[3][100] = {
        "zhangsan",
        "lisi",
        "wangwu"};
    char(*p)[100] = arr;
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", *p);
        p++;
    }
    return 0;
}