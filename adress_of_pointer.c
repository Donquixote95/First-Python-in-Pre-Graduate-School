//2���� �迭�� ���� ����ϴ� �Լ�
#include <stdio.h>

void print_ary(int (*)[4]);

int main(void)
{
    int ary[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };

    print_ary(ary); //�迭���� �μ��� �ְ� �Լ� ȣ��

    return 0;
}

void print_ary(int (*pa)[4]) //�Ű������� �迭 ������
{
    int i, j;

    for (i=0; i<3; i++)
    {
        for (j=0; j<4; j++)
        {
            printf("%5d", pa[i][j]);
        }
        printf("\n");
    }
}

//2���� �迭�� �迭 ������
// #include <stdio.h>

// int main(void)
// {
//     int ary[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
//     int (*pa)[4]; //int�� ���� 4���� �迭�� ����Ű�� �迭 ������, int 4���� 1���� �迭�� ����Ų��. ��ȣ�� ������ ������ �迭�� �ȴ�. *pa�̱� ������ pa�� �����ʹ�.
//     int i, j;

//     pa = ary; // �����Ϳ� �迭���� �����ϸ� �迭ó�� �� �� �ִ�. 
//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 4; j++)
//         {
//             printf("%5d", pa[i][j]); // �����Ϳ� �迭���� �����߱� ������ �迭 �����͸� 2���� �迭ó�� �� �� �ִ�.
//         }
//         printf("\n");
//     }

//     return 0;
// }

//�ּҷ� ���̴� �迭��� �迭�� �ּ� ��
// #include <stdio.h>

// int main(void)
// {
//     int ary[5];

//     printf(" ary�� �� : %u\t", ary);
//     printf("ary�� �ּ� : %u\n", &ary);
//     printf("  ary + 1 : %u\t", ary + 1);
//     printf(" &ary + 1�� �ּ� : %u\n", &ary + 1);

    // ary ��ü�� �ּҷ� ���� ���� ù ��° ��Ҹ� ����Ų��.
    // &ary�� �迭�� �ּҷμ�, �迭 ��ü�� ����Ų��. 

    /*
    �� ���,
    �迭�� ���� ������
    ary + 1�� ���� �ּ� + 1 * sizeof(ary[0]) ������,

    �迭�� �ּҿ� ���� ������ �ϴ�
    &ary + 1�� ���� �ּ� + 1 * sizeof(ary)�� �ȴ�.

    sizeof(ary)�� sizeof(ary[0])�� �翬�� �ٸ���. 
    */

//     return 0;
// }

//���� ������
//3�� �������� ���� ���� double ***ppp;

// ���� �������� Ȱ�� 1; ������ ���� �ٲٴ� �Լ��� �Ű�����
// ���� �������� Ȱ�� 2; ������ �迭�� �Ű������� �޴� �Լ�
// #include <stdio.h>

// void swap_ptr(char **ppa, char **ppb);
// void print_str(char **pps, int cnt);

// int main(void)
// {
//     char *ptr_ary[] = {"eagle", "tiger", "lion", "squirrl"}; 
//     int count; //�迭 ��� ���� ������ ����

//     count = sizeof(ptr_ary) / sizeof(ptr_ary[0]); // �迭 ��� �� ���
//     print_str(ptr_ary, count); //�迭��� �迭 ��� ���� �ְ� ȣ��

//     char *pa = "success";
//     char *pb = "failure";

//     printf("pa -> %s, pb -> %s\n", pa, pb);
//     swap_ptr(&pa, &pb);
//     printf("pa -> %s, pb -> %s\n", pa, pb);

//     return 0;
// }

// void swap_ptr(char **ppa, char **ppb)
// {
//     char *pt;

//     pt = *ppa;
//     *ppa = *ppb;
//     *ppb = pt;
// }

// void print_str(char **pps, int cnt)
// {
//     int i;

//     for (i = 0; i < cnt; i++)
//     {
//         printf("%s\n", pps[i]);
//     }
// }

// �����͵� �޸𸮿� ���� ������ ���� �ϳ��� �����̹Ƿ� �ּ� �������� �������� �ּҵ� ���� �� �ִ�.

// #include <stdio.h>

// int main(void)
// {
//     int a =10; //int�� ������ ����� �ʱ�ȭ
//     int *pi;   //pointer ����
//     int **ppi; //���� pointer ����

//     pi = &a;    //int�� ������ �ּҸ� ������ ������
//     ppi = &pi;  //�������� �ּҸ� ������ ���� ������

//     printf("-------------------------------------------\n");
//     printf("����    ������     &����     *����   **����\n");
//     printf("-------------------------------------------\n");
//     printf("  a%10d%10u\n", a, &a);
//     printf(" pi%10u%10u%10d\n", pi, &pi, *pi);
//     printf("ppi%10u%10u%10u%10u\n", ppi, &ppi, *ppi, **ppi);
//     printf("-------------------------------------------\n");

//     return 0;
// }