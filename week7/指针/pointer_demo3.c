#include <stdio.h>

// 定义一个函数，将两数相除，获取它们的余数
// 返回值：表示计算的状态 正常 0 不正常 1
int getRemainder(int num1, int num2, int *res);

int main()
{
    int res;
    int status = getRemainder(630, 323, &res);
    if (status == 0)
        printf("res:%d\n", res);
    return 0;
}

int getRemainder(int num1, int num2, int *res)
{
    if (num2 == 0)
    {
        return 1;
    }
    *res = num1 % num2;
    return 0;
}