#include <stdio.h>
#define VER 7  // 치환될 부분이 있는 매크로 정의
#define BIT16  // 치환될 부분이 없는 매크로 정의

int main(void)
{
    int max;

#if VER >= 6                       // VER 6 이상이면
    printf("version %d. \n", VER); // 이 부분을 컴파일
#endif                             // #if의 끝

#undef BIT16

#if (!defined(BIT16) && (VER >= 7))
    printf("good day");
#endif

#ifndef BIT16
    printf("good day");
#endif

#ifdef BIT16                // 매크로명 BIT16이 정의되어 있으면
    max = 32767;            // 이 문장 컴파일
#else
    max = 2147483647;       // 정의되어 있지 않으면 이 문장 컴파일
#endif        

    printf("max of int type variable : %d\n", max);

    return 0;    
}