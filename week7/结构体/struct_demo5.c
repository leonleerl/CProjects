#include <stdio.h>
#include <string.h>

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

int main()
{
    Student stu;
    strcpy(stu.name, "Tom");
    stu.age = 33;
    strcpy(stu.msg.tel, "134221244");
    strcpy(stu.msg.email, "hello@gmail.com");
    printf("%s\n", stu.name);
    printf("%d\n", stu.age);
    printf("%s\n", stu.msg.tel);
    printf("%s\n", stu.msg.email);
    return 0;
}