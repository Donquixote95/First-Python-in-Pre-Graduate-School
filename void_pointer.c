// void pointer
// �ּҴ� ����Ű�� �ڷ����� ��ġ�ϴ� �����Ϳ��� ������ �����ϴ�. ���� ����Ű�� �ڷ����� �ٸ� �ּҸ� �����ϴ� ����� void �����͸� ����Ѵ�.
// void pointer�� ����Ű�� �ڷ����� �������� ���� �������̴�.
// void�� ����Ű�� �ڷ����� �������� �ʰڴٴ� ���̴�.
// void pointer�� � �ּҵ� ������ �� ������, ���� ���� �����̳� ������ ���ϴ� ������ ������ �Ұ����ϴ�. ���ϴ� ���·� ��ȯ�ؼ� ����ؾ� �Ѵ�.
// �� ��ȯ �����ڿ� ���� ���� �����ڴ� ��� ���� �����ڷμ� �켱������ ����.
#include <stdio.h>

int main(void)
{
    int a = 10;
    double b = 3.5;
    void *vp;

    vp = &a;
    printf("a : %d\n", *(int *)vp);

    vp = &b;
    printf("b : %.1lf\n", *(double *)vp);

    printf("a�� �ּ� : %d\na�� �ּ� + 1�� �� : %d\n", (int *)vp, (int *)vp + 1);

    //void �����Ͱ� �� ��ȯ�� ���� �ʴ� ���� ���� ������ �� ���̴�. �� ��ȯ ���� void �����͸� �ٸ� �����Ϳ� ������ �� �ִ�.
    int *pi2 = (int *)vp;
    int *pi1 = vp;

    return 0;
}

// �Լ� �������� Ȱ��
// #include <stdio.h>

// void func(int (*fp)(int, int));
// int sum(int a, int b);
// int mul(int a, int b);
// int max(int a, int b);

// int main(void)
// {
//     int sel;    // ���õ� �޴� ��ȣ�� ������ ����

//     printf("01 �� ������ ��\n");
//     printf("02 �� ������ ��\n");
//     printf("01 �� ���� �� �� ū ��\n");
//     printf("���ϴ� ������ �����϶� : ");
//     scanf("%d", &sel); // �޴� ��ȣ �Է�

//     switch (sel)
//     {
//     case 1: func(sum); break; //1�� �����ϸ� func�� ���� ��� �߰�
//     case 2: func(mul); break;
//     case 3: func(mul); break;
//     default:
//         break;
//     }

//     return 0;
// }

// void func(int (*fp)(int, int))
// {
//     int a, b;
//     int res;

//     printf("�� ������ ���� �Է��ϼ��� : ");
//     scanf("%d%d", &a, &b);
//     res = fp(a, b);
//     printf("�ᱣ���� : %d\n", res);
// }

// int sum(int a, int b)
// {
//     return (a + b);
// }

// int mul(int a, int b)
// {
//     return (a * b);
// }

// int max(int a, int b)
// {
//     if (a > b) return a;
//     else return b;
// }
// �Լ� ������
// �Լ��� : �Լ� ���ǰ� �ִ� �޸��� ���� ��ġ, �� �ּ��̴�.

// �Լ� �����͸� ����� �Լ� ȣ��

// #include <stdio.h>

// int sum(int, int);

// int main(void)
// {
//     int (*fp)(int, int); //function pointer
//     // ��ȣ�� ������, int *fp(int, int); �� �����ϸ�, �� ������ �μ��� �ް� �ּҸ� ��ȯ�ϴ� �Լ��� ������ �ȴ�. ������ ������ �ƴϰ� �ȴ�.
//     int res;
//     int res1;
//     int res2;

//     fp = sum;
//     res = fp(10, 20);
//     res1 = (*sum)(10, 20);
//     res2 = sum(10, 20);
//     printf("result : %d\n", res);
//     printf("result1 : %d\n", res1);
//     printf("result2 : %d\n", res2);

//     return 0;
// }

// int sum(int a, int b)
// {
//     return (a + b);
// }