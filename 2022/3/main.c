#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// 函数：将源文件编译为对象文件
int compileSourceToObject(char *sourcefiles[])
{
    int i = 0;

    // 遍历所有的源文件
    while (sourcefiles[i] != NULL)
    {
        // 获取源文件名
        char *sourcefile = sourcefiles[i];

        // 创建对象文件名，将 .c 改为 .o
        char objectfile[256];
        strcpy(objectfile, sourcefile);
        char *dot = strrchr(objectfile, '.');
        if (dot != NULL)
        {
            strcpy(dot, ".o"); // 将 .c 后缀替换为 .o
        }
        else
        {
            fprintf(stderr, "无效的文件名: %s\n", sourcefile);
            return 1;
        }

        // 使用 fork() 创建子进程
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork 失败");
            return 1;
        }

        // 子进程：执行编译器
        if (pid == 0)
        {
            // 准备编译器命令：/usr/bin/cc -c sourcefile -o objectfile
            char *cc = "/usr/bin/cc";
            char *args[] = {cc, "-c", sourcefile, "-o", objectfile, NULL};
            execvp(cc, args);

            // 如果 execvp 失败，打印错误并退出
            perror("execvp 失败");
            exit(1);
        }

        // 父进程：等待子进程完成并检查退出状态
        int status;
        wait(&status);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
        {
            fprintf(stderr, "编译失败: %s\n", sourcefile);
            return 1;
        }

        // 处理下一个文件
        i++;
    }

    // 所有文件都编译成功
    return 0;
}
