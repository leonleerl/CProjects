#include <stdio.h>
#include <string.h>

struct GirlFriend
{
    char name[100];
    int age;
    char gender;
    double height;
};

int main()
{
    struct GirlFriend gf1;
    struct GirlFriend gf2;
    strcpy(gf1.name, "Jenny");
    gf1.age = 23;
    gf1.gender = 'F';
    gf1.height = 1.63;
    printf("%s\n", gf1.name);
    printf("%d\n", gf1.age);
    printf("%c\n", gf1.gender);
    printf("%.3lf\n", gf1.height);

    strcpy(gf2.name, "Jenny");
    gf2.age = 26;
    gf2.gender = 'F';
    gf2.height = 1.73;
    printf("%s\n", gf2.name);
    printf("%d\n", gf2.age);
    printf("%c\n", gf2.gender);
    printf("%.3lf\n", gf2.height);
    return 0;
}