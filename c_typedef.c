#include <stdio.h>

struct student
{
    int num;
    double grade;
};

typedef struct  student Student; // Student형으로 재정의
void print_data(Student *ps);    // 매개변수는 Student형의 포인터

int main(void)
{
    Student s1 = { 315, 4.2 };

    print_data(&s1);

    return 0;
}

void print_data(Student *ps)
{
    printf("S_id : %d\n", ps -> num); // Student 포인터로 멤버 접근
    printf("Grade : %.1lf\n", ps -> grade);
}

//typedef문으로 기본 자료형 재정의하기
typedef unsigned int nbyte;