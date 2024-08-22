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
