#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void function(void)
{
    int pid = fork();
    switch (pid)
    {
    case -1:
        printf("fork() failed\n"); // process creation failed
        exit(EXIT_FAILURE);
        break;
    case 0:
        printf("child is pid=%i\n", getpid());
        for (int t = 0; t < 3; ++t)
        {
            printf(" tick\n");
            sleep(1);
        }
        exit(EXIT_SUCCESS);
        break;
    default:
    { // original parent process
        int child, status;

        printf("parent waiting\n");
        child = wait(&status);

        printf("process pid=%i terminated with exit status=%i\n",
               child, WEXITSTATUS(status));
        exit(EXIT_SUCCESS);
        break;
    }
    }
}

int main(int argc, char *argv[])
{
    // function();
    int x = 10;
    int *p = &x;
    printf("%d\n", x);
    printf("%p\n", &x);
    printf("%d\n", *p);
    printf("%p\n", p);

    return 0;
}