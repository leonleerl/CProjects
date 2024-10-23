#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char *name;
    int age;
} Student;

Student *get_student(int id)
{
    Student *stu;
    stu = (Student *)malloc(sizeof(Student));
    stu->id = id;
    stu->name = "Amy";
    stu->age = 23;
    return stu;
}

int main()
{
    Student *stu = get_student(3);
    printf("id: %d\n", stu->id);
    printf("name: %s\n", stu->name);
    printf("age: %d\n", stu->age);
    return 0;
}