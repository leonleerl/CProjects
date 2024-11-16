#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // 动态分配内存，大小为 n 个整数
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // 使用动态分配的数组
    for (int i = 0; i < n; i++)
    {
        arr[i] = i * i;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 使用完毕后释放内存
    free(arr);
    return EXIT_SUCCESS;
}
