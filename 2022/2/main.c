#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 定义一个结构体来存储每个名字及其出现次数
typedef struct
{
    char name[50]; // 名字的长度假设不超过50
    int count;
} NameCount;

// 函数用于判断单词是否全为大写字母
int is_uppercase_word(const char *word)
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (!isupper(word[i]))
        {
            return 0; // 如果遇到非大写字母，返回0
        }
    }
    return 1; // 如果所有字母都是大写，返回1
}

// 函数用于处理文本并统计名字出现次数
void process_file(const char *filename, NameCount names[], int *name_count)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("无法打开文件");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file))
    {
        // 将非字母字符替换为空格
        for (int i = 0; line[i] != '\0'; i++)
        {
            if (!isalpha(line[i]))
            {
                line[i] = ' ';
            }
        }

        // 逐个提取单词
        char *word = strtok(line, " ");
        while (word != NULL)
        {
            if (is_uppercase_word(word))
            {
                // 检查名字是否已经在数组中
                int found = 0;
                for (int i = 0; i < *name_count; i++)
                {
                    if (strcmp(names[i].name, word) == 0)
                    {
                        names[i].count++;
                        found = 1;
                        break;
                    }
                }

                // 如果名字不在数组中，添加新的名字
                if (!found && *name_count < 100)
                { // 假设名字的最大数量为100
                    strcpy(names[*name_count].name, word);
                    names[*name_count].count = 1;
                    (*name_count)++;
                }
            }
            word = strtok(NULL, " ");
        }
    }
    fclose(file);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "用法: %s <文件1> <文件2> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    // 数组用于存储名字及其出现次数
    NameCount names[100] = {0}; // 假设最多有100个名字
    int name_count = 0;

    // 处理每个文件
    for (int i = 1; i < argc; i++)
    {
        process_file(argv[i], names, &name_count);
    }

    // 找到出现次数最多的名字
    int max_count = 0;
    char *most_frequent_name = NULL;
    for (int i = 0; i < name_count; i++)
    {
        if (names[i].count > max_count)
        {
            max_count = names[i].count;
            most_frequent_name = names[i].name;
        }
    }

    if (most_frequent_name)
    {
        printf("提到最多的名字是: %s (%d 次)\n", most_frequent_name, max_count);
    }
    else
    {
        printf("未找到任何名字。\n");
    }

    return EXIT_SUCCESS;
}
