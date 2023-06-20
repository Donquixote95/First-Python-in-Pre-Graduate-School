#include <stdio.h>
extern void set_key(int);
extern int get_key(void);
int key;
int main(void)
{
    int res;
    set_key(10);
    key = get_key();
    set_key(20);
    res = key + get_key();
    printf("%d", res);
    return 0;
}

// #include <stdio.h>
// #include "point.h"
// #include "line.h"

// int main(void)
// {
//     Line a = { {1, 2}, {5, 6} };
//     Point b;

//     b.x = (a.first.x + a.second.x) / 2;
//     b.y = (a.first.y + a.second.y) / 2;
//     printf(" The middle of line : (%d, %d)\n", b.x, b.y);

//     return 0;
// }


// 다른 파일에서 선언된 전역 변수를 사용할 때는 extern 선언
// 다른 파일에서 전역 변수를 공유하지 못하게 할 때는 static 

// 함수는 (변수와 달리) static 선언을 하지 않으면 기본적으로 extern 선언으로 간주한다.

// #include <stdio.h>

// int input_data(void); 
// double average(void); 
// void print_data(double);

// int count = 0;
// static int total = 0;

// int main(void)
// {
//     double avg;

//     total = input_data();
//     avg = average();
//     print_data(avg);

//     return 0;
// }

// void print_data(double avg)
// {
//     printf("The number of positive integers : %d\n", count);
//     printf("Total sum and avearge : %d, %.lf\n", total, avg);
// }



// 소스파일 - main.c
// #include <stdio.h>    // 시스템 헤더 파일의 내용 복사
// #include "students.h" // 사용자 정의 헤더 파일의 내용 복사

// int main(void)
// {
//     Student a = {315, "Hong Gil Dong"}; // 구조체 변수 선언과 초기화

//     printf("Grade : %d, Name : %s\n", a.num, a.name); //구조체 멤버 출력

//     return 0;
// }