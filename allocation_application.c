#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//main �Լ��� ����� �μ� ���
//����� �μ�(command line argument) ; ����࿡�� ���α׷��� �����ų ���� ���α׷��� �̸� �ܿ��� ���α׷��� �ʿ��� ������ �Բ� �� �� �ִ�. �̵��� ��� ����� �μ���� �Ѵ�.
// �ü���� ����� �μ��� ���α׷��� main �Լ��� �ѱ�� ����� ���� �����ͷ� ���� �Ҵ��� ������ �迭ó�� ����ϴ� ���� ���캸��.
int main(int argc, char **argv) //����� �μ��� ���� �Ű�����
//�Ű������� �̸��� ���Ƿ� �ۼ��� �� �ִ�. �׷��� ���������� argc�� argv�� ����Ѵ�.
//�ǹ̴� argument count, argument verctor�̴�.
/*
����� �μ��� ���� 3�� argc �Ű������� ����ǰ�(�� 3������ p470 ����),
����࿡�� �Է��� ���ڿ��� ��ġ�� argv �Ű������� ����ȴ�.
*/
{
    int i;

    for(i = 0; i < argc; i++) //�μ� ���� ��ŭ �ݺ�
    {
        printf("%s\n", argv[i]);
    }
    
    return 0;
}

// void print_str(char **ps); // ���� �Ҵ� ������ ���ڿ��� ����ϴ� �Լ�

// int main(void)
// {
//     char temp[80]; // �ӽ� char �迭
//     char *str[21] = { 0 }; // ���ڿ��� ������ ������ �迭, �� �����ͷ� �ʱ�ȭ, 22���� ������ ��� �η� �ʱ�ȭ �ȴ�.
//     int i = 0;

//     while (i < 20) // �ִ� 20������ �Է��Ѵ�. 20���� �� ä���, str[20] ��, 21��°�� �ּ� NULL �����͸� �����ؾ� �Ѵ�..?
//     {
//         printf("���ڿ��� �Է��ϼ��� : ");
//         gets(temp); // ���ڿ� �Է�
//         if (strcmp(temp, "end") == 0) break; //end�� �ԷµǸ� �ݺ� ����
//         //strcmp() �Լ��� 2���� string�� ���ϴ� �Լ���.
//         //������ 0�� ����
//         str[i] = (char *)malloc(strlen(temp) + 1); // ���ڿ� ���� ���� �Ҵ�, null ���� �����ؼ�
//         strcpy(str[i], temp);
//         i++;
//     }
//     print_str(str);

//     for (i = 0; str[i] != NULL; i++) // str�� ����� ���ڿ��� ���� ������
//     {
//         free(str[i]); // ���� �Ҵ� ���� ��ȯ
//     }

//     return 0;
// }

// void print_str(char **ps)
// {
//     while (*ps != NULL) // �迭�� �����Ͱ� �� �����Ͱ� �ƴ� ���� �ݺ�
//     {
//         printf("%s\n", *ps); // ps�� ����Ű�� ���� ������ �迭 ���
//         ps++; //ps�� ���� �迭 ��Ҹ� ����Ų��.
//     }
// }


// int main(void)
// {
//     char temp[80];
//     char *str[3];
//     int i;

//     for ( i= 0; i < 3; i++)
//     {
//         printf("���ڿ��� �Է��ϼ��� : ");
//         gets(temp);
//         str[i] = (char *)malloc(strlen(temp) + 1);
//         strcpy(str[i], temp);
//     }

//     for (i = 0; i < 3; i++)
//     {
//         printf("%s\n", str[i]);
//     }

//     for (i = 0; i < 3; i++)
//     {
//         free(str[i]);
//     }

//     return 0; 
// }