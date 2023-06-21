#include <stdio.h>
#pragma pack(push, 1) // ����Ʈ ����θ�Ʈ�� 1�� �ٲ۴�.
// #pragma pack�� ����ü�� ����Ʈ ����θ�Ʈ ���� ũ�⸦ �����Ѵ�.
// push�� ����Ʈ ����θ�Ʈ�� �ٲ� �� ������ ��Ģ�� ����Ѵ�.


// pragma �����ڴ� �����Ϸ��� ������ ����� ���������� ������ �� ���
// ���ø�(directive-name)�� ���� �����Ϸ��� � ����� ������ ������
// pack�� ����ü�� �е� ����Ʈ ũ�⸦ �����ϸ�, warning�� ��� �޽����� �����Ѵ�.

typedef struct 
{
    char ch;
    int in;
} Sample1;

#pragma pack(pop) //  �ٲٱ� ���� ����Ʈ ����θ�Ʈ ���� / ������ push�� ����صξ��� ������ ���� ����

// #pragma pack(1) // �̷��Ե� �����ϴ�.

// warning�� �����Ϸ��� ǥ���ϴ� ��� �޽����� �����ϴµ� ����� �� �ִ�.
#pragma warning(disable:4101) // 4101 ��� �޽����� ��� ǥ������ ����

typedef struct 
{
    char ch;
    int in;
} Sample2;

int main(void)
{
    printf("Sample1 ����ü�� ũ�� : %d����Ʈ\n", sizeof(Sample1));
    printf("Sample2 ����ü�� ũ�� : %d����Ʈ\n", sizeof(Sample2));

    return 0;
}