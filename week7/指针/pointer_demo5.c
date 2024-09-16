#include <stdio.h>

int main()
{

    int a = 10;
    int b = 20;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p1 = arr;
    // while (*p1 != 11)
    // {
    //     printf("%d\n", *p1);
    //     p1++;
    // }
    printf("%d\n", *p1);
    printf("%d\n", *(p1 + 1));
    printf("%d\n", *(p1 + 2));

    return 0;
}