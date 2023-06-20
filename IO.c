/*
문자 입력 함수 fgetc
파일이 개방되면 데이터를 입출력할 준비가 됐다.
데이터 입출력은 함수를 통해 수행하며 이때 파일 포인터를 함수의 인수로 준다.

fgetc 함수는 파일에서 하나의 문자를 입력하여 반환한다.
*/

#include <stdio.h>

int main(void)
{
    FILE *fp;
    int ch;

    fp = fopen("a.txt", "r"); //a.txt 에는 "apple"을 적어두었음.
    if (fp == NULL)
    {
        printf("file is not opened.\n");
        return 1;
    }

    while (1)
    {
        ch = fgetc(fp); // 개방한 파일에서 하나의 문자 입력해서 ch 변수에 저장
        // fgetc 함수는 함수의 데이터를 모두 읽으면 EOF를 반환한다.
        if (ch == EOF) // 함수의 return 값이 EOF면 입력 종료
        {
            break;
        }
        putchar(ch); // 입력한 문자를 화면에 출력
    }
}

/*
fgetc 함수가 스트림 파일에서 데이터를 입력하는 과정
1. fegtc 함수는 파일 포인터와 연결된 스트림 파일의 버퍼에서 데이터를 가져온다.
2. 버퍼가 비어 있으므로 하드디스크에서 데이터를 가져와 버퍼를 채운다. 읽는 데이터 크기에 주목해야 한다.
3. 하드디스크에서 데이터를 가져올 때는 한 번에 버퍼의 크기만큼 가져와 저장한다.
4. 물론 파일의 크기가 버퍼 크기보다 작으면 모든 데이터가 한 번에 버퍼에 저장된다. 
5. 그 후 fegtc 함수는 버퍼에서 첫 번째 문자를 가져와 반환한다.
6. fgetc 함수가 두 번째 호출될 때는 이미 버퍼에 저장된 데이터가 있으므로 버퍼로부터 바로 문자를 읽어 들인다.
7. 위에서는, fgetc 함수는 자동으로 버퍼의 두 번째 문자인 'p'를 읽어 반환한다.
8. 이런 입력방식이 가능한 이유는 위치 지시자 덕분이다.

스트림 파일에는 문자를 입력할 버퍼의 위치를 알려주는 지시지가 있다. 위치 지시자는 파일이 개방되면
0으로 초기화되며 입력 함수가 데이터를 읽을 때 그 크기만큼 증가한다. 
fgetc 함수는 한 문자씩 읽으므로 데이터를 읽을 때마다 위치 지시자의 값은 1씩 증가한다.

버퍼의 데이터를 모두 읽으면 위치 지시자의 값은 버퍼에 저장된 데이터 크기와 같아진다.
이후에 다시 fgetc 함수가 호출되면 다시 하드디스크로부터 새로운 데이터를 가져와 버퍼를 채운다.
만약 하드디스크에 더 이상 읽을 데이터가 없으면 fgetc 함수는 EOF를 반환한다.

fgetc 함수가 EOF를 반환하면 파일의 데이터를 모두 읽었다는 뜻이다.
EOF는 컴파일 과정에서 stdio.h에 정의된 상수 -1로 바뀌므로 -1을 직접 사용할 수도 있다.
그러나 시스템에 따라 EOF의 정의가 다를 수 있으므로 호환성을 위해 EOF를 쓰는 것이 좋다.
fgetc 함수가 하드디스크에 있는 파일의 입력이 끝났음을 확인하는 방법은
파일의 크기와 현재까지 읽어 들인 데이터의 크기를 비교하여 판단하는 것이다.
파일에는 끝을 표시하는 어떤 정보도 포함되지 않는다.

위와 같은 입출력(IO) 과정은 fgetc 함수뿐만 아니라 스트림 파일을 사용하는 모든 입력 함수에
똑같이 적용된다.
*/