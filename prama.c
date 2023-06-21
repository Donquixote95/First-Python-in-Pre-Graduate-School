#include <stdio.h>
#pragma pack(push, 1) // 바이트 얼라인먼트를 1로 바꾼다.
// #pragma pack은 구조체의 바이트 얼라인먼트 단위 크기를 결정한다.
// push는 바이트 얼라인먼트를 바꿀 때 현재의 규칙을 기억한다.


// pragma 지시자는 컴파일러의 컴파일 방법을 세부적으로 제어할 때 사용
// 지시명(directive-name)을 통해 컴파일러의 어떤 기능을 제어할 것인지
// pack은 구조체의 패딩 바이트 크기를 결정하며, warning은 경고 메시지를 관리한다.

typedef struct 
{
    char ch;
    int in;
} Sample1;

#pragma pack(pop) //  바꾸기 전의 바이트 얼라인먼트 적용 / 위에서 push로 기억해두었기 때문에 복원 가능

// #pragma pack(1) // 이렇게도 가능하다.

// warning은 컴파일러가 표시하는 경고 메시지를 제거하는데 사용할 수 있다.
#pragma warning(disable:4101) // 4101 경고 메시지는 모두 표시하지 않음

typedef struct 
{
    char ch;
    int in;
} Sample2;

int main(void)
{
    printf("Sample1 구조체의 크기 : %d바이트\n", sizeof(Sample1));
    printf("Sample2 구조체의 크기 : %d바이트\n", sizeof(Sample2));

    return 0;
}