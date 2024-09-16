#include <stdio.h>

int main()
{
    // 另一种便利数组的方式
    int arr1[3] = {1, 2, 3};
    int arr2[2] = {4, 5};
    int arr3[4] = {6, 7, 8};

    // 预先计算每一个数组的真实长度
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    int len3 = sizeof(arr3) / sizeof(arr3[0]);
    // 再定义一个数组，装所有数组的长度
    int lenArr[3] = {len1, len2, len3};

    int *arr[3] = {arr1, arr2, arr3};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < lenArr[i]; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}