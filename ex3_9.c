#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    int a;

    scanf("%d", &a); //scan formatted
    printf("�Էµ� �� : %d\n", a);

    int age;
    double height;

    printf("���̿� Ű�� �Է��ϼ��� : ");
    scanf("%d%lf", &age, &height);
    printf("���̴� %d��, Ű�� %.1lfcm�Դϴ�.\n", age, height);

    char grade;
    char name[20];

    printf("���� �Է� : ");
    scanf("%c", &grade);

    printf("�̸� �Է� : ");
    scanf("%s", name);

    printf("%s�� ������ %c�Դϴ�.\n", name, grade);

    return 0;
}

/*
���� (unsigned) 2byte %hd(%hu)
���� (unsigned) 4byte %d(%u)
���� (unsigned) 4byte %ld(%lu)
���� (unsigned) 8byte %lld(%llu)

�Ǽ� float 4byte %f
�Ǽ� double 8byte %lf
�Ǽ� long double 8, 10, 12, 16byte $Lf

���� char 1byte $c

���ڿ� char �迭 ������ $s
*/