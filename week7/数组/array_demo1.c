#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    printf("%zu\n", sizeof(arr));
    printf("%p\n", arr);
    printf("%p\n", &arr);
    printf("移动后：\n");
    printf("%p\n", arr + 1);
    printf("%p\n", &arr + 1);
    return 0;
}