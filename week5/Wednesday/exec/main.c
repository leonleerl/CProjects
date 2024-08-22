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
