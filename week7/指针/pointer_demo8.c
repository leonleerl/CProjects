#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int len = sizeof(arr) / sizeof(arr[0]);

    int *p = arr;
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", *(p + i));
    }
    return 0;
}