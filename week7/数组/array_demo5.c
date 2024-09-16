#include <stdio.h>
/*
定义加减乘除四个函数
键盘录入三个数字
前两个代表计算数字
第三个代表调用的函数
*/
int add(int a, int b);
int subtract(int a, int b);
int mutiply(int a, int b);
int divide(int a, int b);

int main()
{
    // 专业术语：函数指针数组
    int (*arr[4])(int, int) = {add, subtract, mutiply, divide};

    printf("请录入两个数字参与计算\n");
    int num1;
    int num2;
    scanf("%d%d", &num1, &num2);
    printf("%d %d\n", num1, num2);
    printf("请录入一个数字进行计算\n");
    int operator;
    scanf("%d", &operator);
    int res = (arr[operator-1])(num1,num2);
    printf("%d\n", res);
    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int mutiply(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    return a / b;
}