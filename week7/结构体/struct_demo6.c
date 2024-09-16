#include <stdio.h>

typedef struct
{
    char tel[100];
    char email[100];
} Message;

typedef struct
{
    char name[100];
    int age;
    Message msg;
} Student;

typedef struct
{
    double a;
    char b;
    int c;
    char d;
} Demo;

int main()
{
    Student stu;
    printf("%zu\n", sizeof(stu));

    Demo demo;
    printf("%zu\n", sizeof(demo));

    return 0;
}