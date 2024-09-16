#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[100];
    int age;
} Stu;

void method(Stu *student);

int main()
{
    Stu stu;
    strcpy(stu.name, "Tom");
    stu.age = 19;
    method(&stu);
    printf("%s\n", stu.name);
    printf("%d\n", stu.age);
    return 0;
}

void method(Stu *student)
{
    student->age = 300;
}