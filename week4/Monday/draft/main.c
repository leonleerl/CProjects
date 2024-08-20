#include "config.h"

void read_using_descriptor(char filename[]);

int main(int argc, char *argv[])
{
    // 调用函数读取并输出文件内容
    read_using_descriptor("example.txt");

    return 0;
}