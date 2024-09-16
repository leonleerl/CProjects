typedef struct
{
    char name[100];
    int age;
} UWAStu, CurtinStu;

int main()
{
    UWAStu stu1 = {"zhangsan", 23};
    CurtinStu stu2 = {"lisi", 24};
    UWAStu stu3 = {"wangwu", 25};
    CurtinStu stuArr[3] = {stu1, stu2, stu3};
    for (int i = 0; i < 3; i++)
    {
        CurtinStu temp = stuArr[i];
        printf("name:%s,age:%d\n", temp.name, temp.age);
    }

    return 0;
}