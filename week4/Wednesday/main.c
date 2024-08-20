
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define MYSIZE 10000

void read_using_descriptor();

int main(int argc, char *argv[])
{
    FILE *file = fopen("file.txt", "r");

        return 0;
}

void read_using_descriptor(char filename[])
{
    //  ATTEMPT TO OPEN THE FILE FOR READ-ONLY ACCESS
    int fd = open(filename, O_RDONLY);

    //  CHECK TO SEE IF FILE COULD BE OPENED
    if (fd == -1)
    {
        printf("cannot open '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    //  DEFINE A CHARACTER ARRAY TO HOLD THE FILE'S CONTENTS
    char buffer[MYSIZE];
    size_t got;

    //  PERFORM MULTIPLE READs OF FILE UNTIL END-OF-FILE REACHED
    while ((got = read(fd, buffer, sizeof buffer)) > 0)
    {
        printf("%d", got);
        // loop
    }

    //  INDICATE THAT THE PROCESS WILL NO LONGER ACCESS FILE
    close(fd);
}