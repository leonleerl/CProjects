#include <stdio.h>

union MoneyType
{
    int moneyi;
    double moneyd;
    char moneystr[100];
};

int main()
{
    union MoneyType money;
    // 每次只能赋一个值
    money.moneyi = 55555;

    printf("%d\n", money.moneyi);

    return 0;
}