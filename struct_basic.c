// ����ü ���� ; ����ü�� ���¸� �����Ϸ��� �̸� �˷��ִ� ��, ����ü ������ ������ ���ο� �ڷ����� ��������� ���� ����ü�� ������ ����� �� �ִ�.
// ����ü �ʱ�ȭ ; �迭 �ʱ�ȭ�� ����� ����� ����Ѵ�. �ʱ갪�� �߰�ȣ�� ���� �� ����� ���¿� �´� ������ �ʱ�ȭ�Ѵ�.
// ����ü ������ �Լ� �ۿ��� �ϸ� �Բ� ����Ǵ� �Լ��� ���� ������ �ǹǷ� �ʱ�ȭ���� ���� ��� ��� ����� 0���� �ڵ� �ʱ�ȭ�ȴ�.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vision
{
    double left;
    double right;
};

struct vision exchange(struct vision robot);

int main(void)
{
    struct vision robot;

    printf("level of vision : ");
    scanf("%lf%lf", &(robot.left), &(robot.right)); //�켱���� ; ���ٿ�����(.) > �ּҿ�����(&)
    robot = exchange(robot);
    printf("After change : %.1lf %.1lf\n", robot.left, robot.right);

    return 0;
}

struct vision exchange(struct vision robot)
{
    double temp;

    temp = robot.left;
    robot.left = robot.right;
    robot.right = temp;

    return robot;
}


// struct profile
// {
//     int age;
//     double height;
// };

// struct student
// {
    // struct profile pf;
//     int id;
//     char name[20];
//     double grade;
// };

// int main(void)
// {
    // struct student yuni;

    // yuni.pf.age = 17;
    // yuni.pf.height = 164.5;
    // yuni.id = 315;
    // yuni.grade=4.3;

    // struct student s1 = {315, "ȫ�浿", 3.1},
    //                s2 = {316, "�̼���", 4.2},
    //                s3 = {317, "ŷ����", 4.4};

    // struct student max; // �ְ� ������ ������ ����ü ����

    // max = s1;
    // if (s2.grade > max.grade) 
    // {
    //     max = s2;
    // }
    // else if (s3.grade > max.grade)
    // {
    //     max = s3;
    // }
    
    // printf("�й� : %d\n", max.id);
    // printf("�̸� : %s\n", max.name);
    // printf("���� : %.lf\n", max.grade);

    // printf("���� : %d\n", yuni.pf.age);
    // printf("Ű : %.lf\n", yuni.pf.height);
    // printf("�й� : %d\n", yuni.id);
    // printf("���� : %.lf\n", yuni.grade);

//     return 0;
// }

// struct profile
// {
//     char name[20];
//     int age;
//     double height;
//     char *intro;
// };

// int main(void)
// {
//     struct  profile yuni;

//     strcpy(yuni.name, "������");
//     yuni.age = 17;
//     yuni.height = 164.5;

//     yuni.intro = (char *)malloc(80);
//     printf("�ڱ�Ұ� : ");
//     gets(yuni.intro);

//     printf("�̸� : %s\n", yuni.name);
//     printf("���� : %d\n", yuni.age);
//     printf("Ű : %.lf\n", yuni.height);
//     printf("�ڱ�Ұ� : %s", yuni.intro);
//     free(yuni.intro);
    
//     return 0;
// }

//struct ���� ����ؼ� ����ü ����
// struct student
// { 
//     int num; // int�� ���
//     double grade; // double�� ���
// }; // �����ݷ� ���

// int main(void)
// {
//     struct student s1; //struct student ���� ���� ����
    // ����ü ������ �����ϸ� ���� ������ �Ҵ�ȴ�.
    // �� ����� ������ �޸𸮿� �������� �Ҵ�Ǹ� ��� ����� ���� ��ü ���� ������ �ϳ��� ����ü ������ �ȴ�.
    // ������ ũ��� �� ����� ũ�⸦ ���� ���� �ȴ�. 4byte(int) + 8byte(double) = 12byte(student)

//     s1.num = 2;  // ��� ���� ������ "."
//     s1.grade = 2.7;

//     printf("�й� : %d\n", s1.num);
//     printf("���� : %.1lf\n", s1.grade);

//     return 0;
// }

/*
��� �ý����� �����͸� ������ �а� ���� ���� ������ ũ�� ������ �޸𸮿� �����Ѵ�.
byte alignment(����Ʈ ����θ�Ʈ); �����Ϸ��� ����ü ����� ũ�Ⱑ �龦������ ��� ��� ���̿� �е� ����Ʈ(padding byte)�� �־� ������� �������ϰ� �����Ѵ�.

����ü ������ ũ��� ����Ʈ ����θ�Ʈ ������ �ý��۸��� �ٸ� �� �ִ�.
ũ�Ⱑ ���� ū ����� �޸𸮸� �Ҵ��ϴ� ���� ������ �ȴ�.

������, struct student ����ü�� grade ����� ũ�Ⱑ ���� ũ�Ƿ� 8����Ʈ�� ���� ������ �ȴ�.
���� num ����� ù ��° 8����Ʈ ����� ó�� 4����Ʈ�� �Ҵ�ȴ�.
grade ����� ���� 4����Ʈ�� �Ҵ��� �� �����Ƿ� ���� 8����Ʈ�� ����Ѵ�. ���� ���� 4����Ʈ�� �е� ����Ʈ�� ä���.
�ᱹ 4����Ʈ�� �е�����Ʈ�� ���ԵǹǷ� ��ü ����ü�� ũ��� 16����Ʈ�� �ȴ�.

���� ��� ������ ũ�Ⱑ ���� ������� �� �ڷ����� ũ�� ������ �Ҵ�ȴ�.
char ���� 1����Ʈ ������ �Ҵ�ǹǷ� ��� ��ġ���� �Ҵ�� �� �ִ�.
short ���� 2����Ʈ ����, int ���� 4����Ʈ ������ ��� �Ҵ�ȴ�.

�ᱹ ����� ������ ���� ����ü�� ũ�Ⱑ �޶��� �� �����Ƿ� �е� ����Ʈ�� ���� �۵��� ����ü�� �����ϸ� �޸𸮸� �Ƴ� �� �ִ�.
�Ǵ� ������ ���� �����Ϸ��� �е� ����Ʈ�� ���� �ʵ��� ������ �� �ִ�.
#pragma pack(1); // ����Ʈ ����θ�Ʈ�� 1�� �����ϸ� �е� ����Ʈ�� �ʿ� ����.

�� ��� �����͸� �а� ���� �ð��� �� �ɸ� �� �ִ�. ����ü�� ũ��� ��� ����� ũ�⸦ ���� �Ͱ� �������Ƿ� ����ϴ� �޸��� ũ��� �ּ�ȭ�� �� �ִ�.
�� ������ ����ü ���� ���� �����ָ�, ���� include ������ �־��ش�.
*/