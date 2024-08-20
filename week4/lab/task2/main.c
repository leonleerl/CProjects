/*
如果计算机密码包含大小写字符和数字的混合，则通常被认为是“安全的”（即难以猜测）。
编写一个名为isSafe()的函数来确定潜在密码（字符串）是否至少包含两个大写字符、
两个小写字符和两个数字。 您的函数应该采用单个字符数组作为其参数，
并返回一个布尔值来指示密码是否被认为是安全的。
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

bool isSafe(char str[])
{
    int upperCaseCount = 0;
    int lowerCaseCount = 0;
    int numericCount = 0;
    int index = 0;
    while (str[index] != '\0')
    {
        if (isupper(str[index]))
        {
            ++upperCaseCount;
        }
        else if (islower(str[index]))
        {
            ++lowerCaseCount;
        }
        else if (isdigit(str[index]))
        {
            ++numericCount;
        }
        ++index;
    }
    return upperCaseCount >= 2 && lowerCaseCount >= 2 && numericCount >= 2;
}

int main()
{

    return 0;
}