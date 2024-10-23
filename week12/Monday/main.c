#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
long count = 43;

void *hello_world()
{
    printf("Hello World, from thread #%li!\n", count);
    count++;
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];

    for (long tid = 0; tid < NUM_THREADS; tid++)
    {
        printf("In main(): creating thread %li\n", tid);

        int err = pthread_create(&threads[tid], NULL, hello_world, 0);

        if (err != 0)
        {
            printf("ERROR; return code from pthread_create() is %d\n", err);
            exit(EXIT_FAILURE);
        }
    }

    pthread_exit(NULL); // as main() is a thread, too
    return 0;
}

/*
how fork work no
allocate no

老师建议cheat sheet不写code
*/
