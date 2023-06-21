/*
define 매크로명 치환될_부분

매크로명은 대문자를 쓴다.
*/

// __FILE__ ; 전체 디렉터리 경로를 포함한 파일명
// __FUNCTION ; 매크로명이 사용된 함수 이름
// __LINE__ ; 매크로명이 사용된 행 번호
// __DATE__ ; 컴파일을 시작한 날짜
// __TIME__ ; 컴파일을 시작한 시간

#include <stdio.h>

void func(void);

int main(void){
    printf("complile date and time : %s, %s\n\n", __DATE__, __TIME__);
    printf("file name : %s\n", __FILE__);
    printf("function name : %s\n", __FUNCTION__);
    printf("row number : %d\n", __LINE__);

#line 100 "macro.c"    
    func();
    return 0;
}

void func(void)
{
    printf("\n");
    printf("file name : %s\n", __FILE__);
    printf("function name : %s\n", __FUNCTION__);
    printf("row number : %d\n", __LINE__);
}

// #include <stdio.h>
// #define SUM(a, b) ((a) + (b))
// #define MUL(a, b) ((a) * (b))

// int main(void){
//     int a = 10, b = 20;
//     int x = 30, y = 40;
//     int res;

//     printf("a + b = %d\n", SUM(a, b));
//     printf("x + y = %d\n", SUM(x, y));
//     res = 30 / MUL(2, 5);
//     printf("res : %d\n", res);

//     return 0;
// }


// #include <stdio.h>
// #define PI 3.14159
// #define LIMIT 100.0
// #define MSG "passed!"
// #define ERR_PRN printf("this is not allowed.\n")

// int main(void)
// {
//     double radius, area;

//     printf("please input the radius under 10 : ");
//     scanf("%lf", &radius);
//     area = PI * radius * radius;
//     if (area > LIMIT) ERR_PRN;
//     else printf("circle's area : %.2lf (%s)\n", area, MSG);

//     return 0;
// }