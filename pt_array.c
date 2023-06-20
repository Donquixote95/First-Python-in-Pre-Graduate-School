#include <stdio.h>

//포인터 배열의 초기화
// char 포인터 배열의 초기화는 2차원 char 배열의 초기화와 같다.
/*
즉,
(1) char *pary[5] = { "dog", "element", "horse", "tiger", "lion" };
(2) char animal[5][20] = { "dog", "elephant", "horse", "tiger", "lon"};

은 같다. 단, (1)의 방법은 문자열의 시작 주소만 배열 요소에 저장되며, 2차원 char 배열의 초기화는 문자열 자체를 배열의 공간에 저장한다.
*/

//여러 개의 1차원 배열을 2차원 배열처럼 사용
int main(void)
{
    int ary1[4] = {1, 2, 3, 4};
    int ary2[5] = {11, 12, 13, 14};
    int ary3[5] = {21, 22, 23, 24, 100};
    int *pary[3] = { ary1, ary2, ary3 };
    int i, j;

    for (i=0; i < 3; i++)
    {
        for (j=0; j<5; j++)
        {
            printf("%5d", pary[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// int main(void)
// {
//     char *pary[5]; // 각 배열 요소의 자료형이 포인터인 배열 선언
//     int i;

//     pary[0] = "dog";
//     pary[1] = "element";
//     pary[2] = "horse";
//     pary[3] = "tiger";
//     pary[4] = "lion";

//     for (i = 0; i < 5; i++)
//     {
//         printf("%s\n", pary[i]);
//     }

//     return 0;
// }