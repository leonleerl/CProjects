#include <stdio.h>
#include <stdlib.h>

// 比较函数，用于比较两个整数
int compareInt(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int arr[] = {32, 71, 12, 45, 26, 80, 53, 33};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 使用 qsort 函数排序数组
    qsort(arr, n, sizeof(int), compareInt);

    // 输出排序后的数组printf("排序后的数组: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
