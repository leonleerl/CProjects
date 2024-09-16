# 基础

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



函数*open* 、 *read*和*close*不是 C11 函数，而是操作系统**系统调用**，提供用户级程序和操作系统实现之间的接口



**execv()**

该程序通过 `fork()` 创建一个子进程，然后在子进程中调用 `execv()` 来执行另一个程序（例如 `ls` 命令）。父进程将继续执行并等待子进程完成。

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    // 创建一个子进程
    pid_t pid = fork();

    if (pid == -1)
    {
        // fork() 失败
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // 子进程

        // 准备执行的新程序及其参数
        char *program = "/bin/ls";
        char *arguments[] = {"ls", "-l", "-h", NULL}; // 参数数组

        printf("Child Process: Executing ls command...\n");

        // 使用 execv() 执行新的程序
        execv(program, arguments);

        // 如果 execv() 失败，将执行以下代码
        perror("execv failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        // 父进程

        // 等待子进程结束
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
        {
            printf("Parent Process: Child terminated with status %d\n", WEXITSTATUS(status));
        }
        else
        {
            printf("Parent Process: Child terminated abnormally\n");
        }

        exit(EXIT_SUCCESS);
    }
}
```



读取文件

写法1，`ch == EOF`：

```c
#include <stdio.h>
#include <stdlib.h>

void fileRead()
{
    FILE *fp = fopen("./file.txt", "r");
    if (fp == NULL)
    {
        perror("open file failed:");
    }
    while (1)
    {
        char ch = fgetc(fp);
        if (ch == EOF)
        {
            break;
        }
        printf("%c", ch);
    }

    fclose(fp);
}

int main(int argc, char *argv[])
{
    fileRead();
    return 0;
}
```

写法2，用`feof`:

```c
v#include <stdio.h>
#include <stdlib.h>

void fileRead()
{
    FILE *fp = fopen("./file.txt", "r");
    if (fp == NULL)
    {
        perror("open file failed:");
    }
    while (!feof(fp))
    {
        char ch = fgetc(fp);
        printf("%c", ch);
    }

    fclose(fp);
}

int main(int argc, char *argv[])
{
    fileRead();
    return 0;
}
```

写单个字符

```c
#include <stdio.h>
#include <stdlib.h>

void fileWrite()
{
    FILE *fp = fopen("file2.txt", "w");
    if (fp == NULL)
    {
        perror("Open Failed:");
        return;
    }
    char ch = fputc('E', fp);
    printf("%c", ch);
}

int main()
{
    fileWrite();
    return 0;
}
```

写一句话

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fileWrite()
{
    FILE *fp = fopen("file2.txt", "w");
    if (fp == NULL)
    {
        perror("Open Failed:");
        return;
    }
    char str[] = "Hello file22222";
    for (int i = 0; i < strlen(str); ++i)
    {
        char ch = fputc(str[i], fp);
        printf("%c", ch);
    }
}

int main()
{
    fileWrite();
    return 0;
}
```

写入一行并读取一行

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fileReadWrite()
{
    FILE *fp = fopen("file3.txt", "w+");
    if (fp == NULL)
    {
        perror("Open Failed:");
    }
    int fputsRes = fputs("Hello file3333", fp);
    printf("result:%d\n", fputsRes);

    rewind(fp); // 把光标移到开头
    char buffer[128] = {0};
    char *fgetsRes = fgets(buffer, sizeof(buffer), fp);
    printf("Content:%s\n", fgetsRes);
    fclose(fp);
}

int main()
{
    fileReadWrite();
    return 0;
}
```

写入多行并读取多行

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fileReadWrite()
{
    FILE *fp = fopen("file3.txt", "w+");
    if (fp == NULL)
    {
        perror("Open Failed:");
        return;
    }

    // 写入多行内容
    fputs("Hello, this is the first line.\n", fp);
    fputs("This is the second line.\n", fp);
    fputs("And here is the third line.\n", fp);

    // 刷新缓冲区，确保内容写入到文件
    fflush(fp);

    // 将文件指针移到文件开头
    rewind(fp);

    // 读取并输出多行内容
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("Content: %s", buffer);
    }

    fclose(fp);
}

int main()
{
    fileReadWrite();
    return 0;
}
```









# 指针

## 数组

注意指针指向arr和&arr，在+1时的区别

![Screenshot 2024-09-16 at 9.05.29 AM](C笔记.assets/Screenshot 2024-09-16 at 9.05.29 AM.png)

~~~c
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
~~~

~~~
40
0x16fabb020
0x16fabb020
移动后：
0x16fabb024
0x16fabb048
~~~



另一种方式遍历数组，如下所示。但是只能得到前两个数据，原因是在使用arr1数组名进行计算的时候，退化为指向第一个元素的指针，此时不再表示数组整体了。所以计算结果为8个字节除以4个字节，length长度永远为2

```c
#include <stdio.h>

int main()
{
    // 另一种便利数组的方式
    int arr1[3] = {1, 2, 3};
    int arr2[2] = {4, 5};
    int arr3[4] = {6, 7, 8};

    int *arr[3] = {arr1, arr2, arr3};
    for (int i = 0; i < 3; i++)
    {
        int length = sizeof(arr[i]) / sizeof(int);
        for (int j = 0; j < length; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```

```
1 2 
4 5 
6 7 
```

改进：

```c
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
```

```
1 2 3 
4 5 
6 7 8 0 
```



## 二维数组



 ![Screenshot 2024-09-16 at 9.53.26 AM](C笔记.assets/Screenshot 2024-09-16 at 9.53.26 AM.png)

```c
#include <stdio.h>

int main()
{

    int arr[3][5] = {
        {1, 2, 3, 4, 5},
        {11, 22, 33, 44, 55},
        {111, 222, 333, 444, 555}};

    int(*p)[5] = arr;

    printf("%p\n", arr);
    printf("%p\n", arr + 1);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", *(*p + j));
        }
        p++;
        printf("\n");
    }

    return 0;
}
```



## 函数指针

```c
#include <stdio.h>
void method1();
int method2(int a, int b);

int main()
{
    void (*p1)() = method1;
    int (*p2)(int, int) = method2;

    p1();
    int res = p2(32, 99);
    printf("%d\n", res);
    return 0;
}

void method1()
{
    printf("method1\n");
}

int method2(int a, int b)
{
    printf("method2\n");
    return a + b;
}
```

```
method1
method2
131
```



```c
#include <stdio.h>
/*
定义加减乘除四个函数
键盘录入三个数字
前两个代表计算数字
第三个代表调用的函数
*/
int add(int a, int b);
int subtract(int a, int b);
int mutiply(int a, int b);
int divide(int a, int b);

int main()
{
    // 专业术语：函数指针数组
    int (*arr[4])(int, int) = {add, subtract, mutiply, divide};

    printf("请录入两个数字参与计算\n");
    int num1;
    int num2;
    scanf("%d%d", &num1, &num2);
    printf("%d %d\n", num1, num2);
    printf("请录入一个数字进行计算\n");
    int operator;
    scanf("%d", &operator);
    int res = (arr[operator-1])(num1,num2);
    printf("%d\n", res);
    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int mutiply(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    return a / b;
}
```

```
请录入两个数字参与计算
45 21
45 21请录入一个数字进行计算
1
66
```

