# week2

编译命令

```
gcc hello.c -o hello
```

在命令行中传入参数

* argc：表示参数的个数
* argv：是参数列表，第0个是文件名，第1个是第一个参数，第2个是第二个参数

```c
#include <stdio.h>
#include <stdlib.h>

extern double sqrt(double x);

float square(float x)
{
    return x * x;
}

int main(int argc, char *argv[])
{
    if(argc > 2) {
      float a, b, sum;

      a   = atof(argv[1]);
      b   = atof(argv[2]);

      sum = square(a) + square(b);
      printf("hypotenuse = %f\n",
             sqrt(sum) );
    }
    return 0;
}
```

常见错误：

一下这段代码在windows上运行会先传3，后传4

在mac intel上运行会先传4，后传3

所以编译器可能会采取效率最高的代码的顺序执行，并且这个也和不同的处理器架构有关

**总之**：不能理所当然认为函数会从左到右顺序执行

~~~c
#include <stdio.h>

int square(int a)
{
    printf("square函数被调用,传入的参数为%d,返回%d\n", a, a * a);
    return a * a;
}

void sum(int x, int y)
{
    printf("sum函数被调用，传入的参数为%d和%d，sum = %i\n", x, y, x + y);
}

int main(int argc, char *argv[])
{
    sum(square(3), square(4));
    return 0;
}
~~~



static关键字(期末来补充)

```
```



生成57-69之间的随机数

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 57 - 69
    // 12
    for (int i = 0; i < 20; i++)
    {

        int randomNum = (rand() % 13) + 57;
        printf("随机整数57-69: %d\n", randomNum);
    }

    return 0;
}
```

qsort排序

```c
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
```



遍历字符数组

```c
int main(int argc, char *argv[])
{

    char arr[] = "hello\nworld";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%c\n", arr[i]);
    }

    return 0;
}
```

