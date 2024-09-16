#include <stdio.h>
/*
返回数组的最大值和最小值
*/
void getMaxAndMin(int *arr, int len, int *max, int *min);
int main()
{
    int arr[] = {43, 2123, 52, -23, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    int max;
    int min;
    getMaxAndMin(arr, len, &max, &min);
    printf("max:%d\n", max);
    printf("min:%d\n", min);
    return 0;
}

void getMaxAndMin(int *arr, int len, int *max, int *min)
{
    *max = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
    }
    *min = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (arr[i] < *min)
        {
            *min = arr[i];
        }
    }
}