// 구조체 선언 ; 구조체의 형태를 컴파일러에 미리 알려주는 것, 구조체 선언이 끝나면 새로운 자료형이 만들어지며 이후 구조체의 변수를 사용할 수 있다.
// 구조체 초기화 ; 배열 초기화와 비슷한 방법을 사용한다. 초깃값을 중괄호로 묶고 각 멤버의 형태에 맞는 값으로 초기화한다.
// 구조체 선언을 함수 밖에서 하면 함께 선언되는 함수가 전역 변수가 되므로 초기화하지 않을 경우 모든 멤버는 0으로 자동 초기화된다.
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
    scanf("%lf%lf", &(robot.left), &(robot.right)); //우선순위 ; 접근연산자(.) > 주소연산자(&)
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

    // struct student s1 = {315, "홍길동", 3.1},
    //                s2 = {316, "이순신", 4.2},
    //                s3 = {317, "킹세종", 4.4};

    // struct student max; // 최고 학점을 저장할 구조체 변수

    // max = s1;
    // if (s2.grade > max.grade) 
    // {
    //     max = s2;
    // }
    // else if (s3.grade > max.grade)
    // {
    //     max = s3;
    // }
    
    // printf("학번 : %d\n", max.id);
    // printf("이름 : %s\n", max.name);
    // printf("학점 : %.lf\n", max.grade);

    // printf("나이 : %d\n", yuni.pf.age);
    // printf("키 : %.lf\n", yuni.pf.height);
    // printf("학번 : %d\n", yuni.id);
    // printf("학점 : %.lf\n", yuni.grade);

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

//     strcpy(yuni.name, "서하윤");
//     yuni.age = 17;
//     yuni.height = 164.5;

//     yuni.intro = (char *)malloc(80);
//     printf("자기소개 : ");
//     gets(yuni.intro);

//     printf("이름 : %s\n", yuni.name);
//     printf("나이 : %d\n", yuni.age);
//     printf("키 : %.lf\n", yuni.height);
//     printf("자기소개 : %s", yuni.intro);
//     free(yuni.intro);
    
//     return 0;
// }

//struct 예약어를 사용해서 구조체 선언
// struct student
// { 
//     int num; // int형 멤버
//     double grade; // double형 멤버
// }; // 세미콜론 사용

// int main(void)
// {
//     struct student s1; //struct student 형의 변수 선언
    // 구조체 변수를 선언하면 저장 공간이 할당된다.
    // 각 멤버의 공간이 메모리에 연속으로 할당되며 모든 멤버를 더한 전체 저장 공간이 하나의 구조체 변수가 된다.
    // 변수의 크기는 각 멤버의 크기를 더한 값이 된다. 4byte(int) + 8byte(double) = 12byte(student)

//     s1.num = 2;  // 멤버 접근 연산자 "."
//     s1.grade = 2.7;

//     printf("학번 : %d\n", s1.num);
//     printf("학점 : %.1lf\n", s1.grade);

//     return 0;
// }

/*
모든 시스템은 데이터를 빠르게 읽고 쓰기 위해 일정한 크기 단위로 메모리에 접근한다.
byte alignment(바이트 얼라인먼트); 컴파일러는 구조체 멤버의 크기가 들쑥날쑥한 경우 멤버 사이에 패딩 바이트(padding byte)를 넣어 멤버들을 가지런하게 정렬한다.

구조체 변수의 크기는 바이트 얼라인먼트 때문에 시스템마다 다를 수 있다.
크기가 가장 큰 멤버가 메모리를 할당하는 기준 단위가 된다.

위에서, struct student 구조체는 grade 멤버의 크기가 가장 크므로 8바이트가 기준 단위가 된다.
따라서 num 멤버는 첫 번째 8바이트 블록의 처음 4바이트에 할당된다.
grade 멤버는 남은 4바이트에 할당할 수 없으므로 다음 8바이트를 사용한다. 위의 남은 4바이트는 패딩 바이트가 채운다.
결국 4바이트의 패딩바이트가 포함되므로 전체 구조체의 크기는 16바이트가 된다.

기준 블록 내에서 크기가 작은 멤버들은 각 자료형의 크기 단위로 할당된다.
char 형은 1바이트 단위로 할당되므로 모든 위치에서 할당될 수 있다.
short 형은 2바위트 단위, int 형은 4바이트 단위로 끊어서 할당된다.

결국 멤버의 순서에 따라 구조체의 크기가 달라질 수 있으므로 패딩 바이트가 가장 작도록 구조체를 선언하면 메모리를 아낄 수 있다.
또는 다음과 같이 컴파일러에 패딩 바이트를 넣지 않도록 지시할 수 있다.
#pragma pack(1); // 바이트 얼라인먼트를 1로 설정하면 패딩 바이트가 필요 없음.

위 경우 데이터를 읽고 쓰는 시간은 더 걸릴 수 있다. 구조체의 크기는 모든 멤버의 크기를 더한 것과 같아지므로 사용하는 메모리의 크기는 최소화할 수 있다.
이 구문은 구조체 선언 전에 적어주며, 보통 include 다음에 넣어준다.
*/