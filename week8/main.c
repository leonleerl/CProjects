#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STUDENTNUM 5

typedef struct
{
    int id;
    char *name;
} Student;

int main(int argc, char *argv[])
{
    Student *students = (Student *)malloc(STUDENTNUM * sizeof(Student));
    Student *p = students;
    students[0].id = 1;
    students[0].name = "Tom";
    students[1].id = 2;
    students[1].name = "Jack";
    for (int i = 0; i < 2; i++)
    {
        printf("id: %d; name: %s\n", students[i].id, students[i].name);
    }
    p++;
    printf("id: %d; name: %s\n", p->id, p->name);

    free(students);
    return 0;
}