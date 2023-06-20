#include <stdio.h>

// ������ ; ������ ������ �� �ִ� ���� ���� ��ȣ�� �����Ͽ� �����Ѵ�.
// �������� ������ enum
// �����Ϸ��� ����� 0���� ���ʷ� �ϳ��� ū ������ �ٲ۴�. ��, SPRING�� 0, SUMMER�� 1, FALL�� 5, WINTER�� 6�̴�. FALLó�� �ʱ갪�� ���ϴ� ������ �ٽ� ������ ���� �ִ�,
// ���� ���� ������ ��� ������ ������� ������ ������� 1��ŭ �� ū ������ �ٲ��. ��, WINTER�� 6�� �ȴ�.
enum season { SPRING, SUMMER, FALL =5 , WINTER }; // ������ ����

int main(void)
{
    enum season ss; // ������ ������ int���� ���� ũ��� ������ ������ �� �ִ� ������ �Ҵ�ȴ�. ���� ������ ����� �����ϴ� �뵵�� ���δ�.
    // �ᱹ ������ ����� ������ �ٲ�Ƿ� ���� ����� �Ἥ �ۼ��� ���� ������ ���ڷ� �ۼ��ϸ� �� ���������� �ڵ带 ������ �� �ִ�.
    char *pc = NULL;

    ss = SPRING;
    switch(ss)
    {
        case SPRING:
            pc = "inline"; break;
        case SUMMER:
            pc = "swimming"; break;
        case FALL:
            pc = "trip"; break;
        case WINTER:
            pc = "skiing"; break;
    }
    printf("My lesiure => %s\n", pc);

    return 0;
}

// ����ü(union) ; ����ü�� ��� ����� �ϳ��� ���� ������ ���� ����Ѵ�.
// ��Ģ 1. ����ü ������ ũ��� ��� �߿��� ũ�Ⱑ ���� ū ����� �����ȴ�. ���� ������ �ϳ��̴�.
// ��Ģ 2. ����ü ������ �ʱ�ȭ�� �߰�ȣ�� ����Ͽ� ù ��° ����� �ʱ�ȭ�Ѵ�. ���� ù ��° ����� �ƴ� ����� �ʱ�ȭ�� ���� ��� ���� ������(.)�� ����� ���� ��������� �Ѵ�.
// union student
// {
//     int num;
//     double grade;
// };

// int main(void)
// {
//     union student s1 = { 315 };

//     printf("sid : %d\n", s1.num);
//     s1.grade = 4.4;
//     printf("grade : %.1lf\n", s1.grade);
//     printf("sid : %d\n", s1.num);

//     return 0;
// }

//linked list ; ����ü ������ �����ͷ� ������ ��

// �ڱ� ���� ����ü ; �ڽ��� ����ü�� ����Ű�� �����͸� ����� ������.
// struct list
// {
//     int num;
//     struct list *next;
// };

// int main(void)
// {
//     struct list a = {10, 0}, b = {20, 0}, c = {30, 0}; // ����ü ���� �ʱ�ȭ
//     struct list *head = &a, *current; // ��� ������ �ʱ�ȭ

//     a.next = &b;
//     b.next = &c;

//     printf("head->num : %d\n", head->num);
//     printf("head->next->num : %d\n", head->next->num);

//     printf("list all : ");
//     current = head;
//     while (current != NULL)
//     {
//         printf("%d  ", current->num);
//         current = current->next;
//     }
//     printf("\n");

//     return 0;
// }

// struct address
// {
//     char name[20];
//     int age;
//     char tel[20];
//     char addr[80];
// };

// void print_list(struct address *lp);

// int main(void)
// {
//     struct address list[5] = {
//         {"ȫ�浿", 23, "111-1111", "�︪�� ����"},
//         {"�̼���", 35, "222-2222", "���� ��õ��"},
//         {"�庸��", 19, "333-3333", "�ϵ� û����"},
//         {"������", 15, "444-4444", "�泲 õ��"},
//         {"���߱�", 45, "555-5555", "Ȳ�ص� ����"}
//     };

//     print_list(list);

//     return 0;
// }

// void print_list(struct address *lp)
// {
//     int i;
//     for (i = 0; i < 5; i++)
//         {
//             printf("%10s%5d%15s%20s\n",
//                 (lp+i) -> name, (lp+i) -> age, (lp+i) -> tel, (lp+i) -> addr);
//                 // list[i].name, list[i].age, list[i].tel, list[i].addr);
//         }
// }
// struct score
// {
//     int kor;
//     int eng;
//     int math;
// };

// int main(void)
// {
//     struct score yuni = { 90, 80, 70 };
//     struct score *ps = &yuni;

//     printf("korean : %d\n", (*ps).kor);
//     printf("english : %d\n", (*ps).eng);
//     printf("math : %d\n", (*ps).math);
//     printf("\n");
//     printf("korean : %d\n", ps -> kor);
//     printf("english : %d\n", ps -> eng);
//     printf("math : %d\n", ps -> math);
// }

