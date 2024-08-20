#include "config.h"

void read_using_descriptor(char filename[])
{
    // 尝试以只读模式打开文件
    int fd = open(filename, O_RDONLY);

    // 检查文件是否成功打开
    if (fd == -1)
    {
        printf("无法打开 '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    // 定义一个字符数组来保存文件内容
    char buffer[MYSIZE];
    size_t got;

    // 多次读取文件，直到文件末尾
    while ((got = read(fd, buffer, sizeof(buffer))) > 0)
    {
        // 将读取到的内容输出到标准输出
        write(STDOUT_FILENO, buffer, got);
    }

    // 关闭文件
    close(fd);
}