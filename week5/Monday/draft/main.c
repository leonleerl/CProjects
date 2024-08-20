#include <stdio.h>
#include <string.h>
#define N 5

int A[N + 1][N + 1];

void function(void)
{
    for (int j = 0; j < N; ++j)
    {
        for (int i = 0; i < N; ++i)
        {
            if ((i % N) == j)
                A[j][i] = 1;
            else
                A[j][i] = 0;
        }
    }
    for (int j = 0; j < N; ++j)
    {
        for (int i = 0; i < N; ++i)
        {
            printf("%i ", A[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{

    function();
    return 0;
}