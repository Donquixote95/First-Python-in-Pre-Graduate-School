#include <stdio.h>

// 열거형 ; 변수에 저장할 수 있는 정수 값을 기호로 정의하여 나열한다.
// 열거형의 예약어는 enum
// 컴파일러는 멤버를 0부터 차례로 하나씩 큰 정수로 바꾼다. 즉, SPRING은 0, SUMMER는 1, FALL은 5, WINTER는 6이다. FALL처럼 초깃값은 원하는 값으로 다시 설정할 수도 있다,
// 값이 새로 설정된 멤버 이후의 멤버들은 설정된 멤버보다 1만큼 더 큰 정수로 바뀐다. 즉, WINTER는 6이 된다.
enum season { SPRING, SUMMER, FALL =5 , WINTER }; // 열거형 선언

int main(void)
{
    enum season ss; // 열거형 변수는 int형과 같은 크기로 정수를 저장할 수 있는 공간이 할당된다. 이후 열거형 멤버를 저장하는 용도로 쓰인다.
    // 결국 열거형 멤버는 정수로 바뀌므로 정수 상수를 써서 작성할 수도 있으나 문자로 작성하면 더 직관적으로 코드를 이해할 수 있다.
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

// 공용체(union) ; 공용체는 모든 멤버가 하나의 저장 공간을 같이 사용한다.
// 규칙 1. 공용체 변수의 크기는 멤버 중에서 크기가 가장 큰 멤버로 결정된다. 저장 공간이 하나이다.
// 규칙 2. 공용체 변수의 초기화는 중괄호를 사용하여 첫 번째 멤버만 초기화한다. 만약 첫 번째 멤버가 아닌 멤버를 초기화할 때는 멤버 점근 연산자(.)로 멤버를 직접 지정해줘야 한다.
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

//linked list ; 구조체 변수를 포인터로 연결한 것

// 자기 참조 구조체 ; 자신의 구조체를 가리키는 포인터를 멤버로 가진다.
// struct list
// {
//     int num;
//     struct list *next;
// };

// int main(void)
// {
//     struct list a = {10, 0}, b = {20, 0}, c = {30, 0}; // 구조체 변수 초기화
//     struct list *head = &a, *current; // 헤드 포인터 초기화

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
//         {"홍길동", 23, "111-1111", "울릉도 독도"},
//         {"이순신", 35, "222-2222", "서울 건천동"},
//         {"장보고", 19, "333-3333", "완도 청해진"},
//         {"유관순", 15, "444-4444", "충남 천안"},
//         {"안중근", 45, "555-5555", "황해도 해주"}
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

