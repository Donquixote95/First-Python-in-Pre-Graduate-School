#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *ifp, *ofp;
    char str[80];
    char *res;

    ifp = fopen("a.txt", "r");
    if (ifp == NULL)
    {
        printf("Can't open the input file. \n");
        return 1;
    }

    ofp = fopen("b.txt", "w");
    if (ofp == NULL)
    {
        printf("can't open the file. \n");
        return 1;
    }

    while (1)
    {
        res = fgets(str, sizeof(str), ifp);
        if (res == NULL)
        {
            break;
        }
        str[strlen(str) - 1] = '\0'; // \n 제거
        fputs(str, ofp);
        fputs(" ", ofp);
    }

    fclose(ifp);  // 입력 파일 닫기
    fclose(ofp);  // 출력 파일 닫기

    return 0;
}