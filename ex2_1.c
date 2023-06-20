#include <stdio.h> // stdio : standard input ouput(ǥ�������)
#include <string.h>

// stdio.h ���� C���� �⺻���� ����ϴ� ����� �Լ��� ��� �ִ�. printf �Լ��� ����

int main(void) //function prototype
{
    10+20;

    printf("Be happy\n");
    printf("1234569789\n");
    printf("My\tfriend\n");
    printf("Good\bd\tchance\n");
    printf("Cow\rW\a\n");
    printf("\n");    

    printf("%d\n", 10);
    printf("%lf\n", 3.5); // �Ҽ��� ���� 6�ڸ����� ��µȴ�.
    printf("%.1lf\n", 3.45); //�Ҽ��� ���� ù° �ڸ����� ���(��° �ڸ����� �ݿø�)
    printf("%.10lf\n", 3.45); //�Ҽ��� ���� 10�ڸ����� ���
    printf("\n");

    printf("%d\n", 12); //10����
    printf("%d\n", 014); //8������ 10������ ���
    printf("%d\n", 0xc); //16������ 10������ ���
    printf("\n");

    printf("%o\n", 12); //8������ ���
    printf("%x\n", 12); //16���� �ҹ��ڷ� ���
    printf("%X\n", 12); //16���� �빮�ڷ� ���
    printf("\n");

    printf("%.1lf\n",1e6); // ���� ������ �Ǽ��� �Ҽ��� ���·� ���
    printf("%.7lf\n",3.14e-5); // �Ҽ��� ���� 7�ڸ����� ���, ���� ��� ����� �Ҽ��� ���� 6�ڸ������� ��µȴ�.
    printf("%le\n",0.0000314); // �Ҽ��� ������ �Ǽ��� ���� ���·� ���
    printf("%.2le\n",1e6); // ���� ���·� �Ҽ��� ���� ��° �ڸ����� ���
    printf("\n");

    printf("%c\n", 'A'); //���� ��� ���
    printf("%s\n", "A"); //���ڿ� ��� ���
    printf("%c�� %s�Դϴ�.\n", '1', "first"); // ����(%c)�� ���ڿ�(%s)�� �Բ� ���

    int a;
    int b,c;
    double da;
    char ch;

    a=10;
    b=a;
    c=a+20;
    da=3.5;
    ch='A';

    printf("���� a�� �� : %d\n", a);
    printf("���� b�� �� : %d\n", b);
    printf("���� c�� �� : %d\n", c);
    printf("���� da�� �� : %.1f\n", da);
    printf("���� ch�� �� : %c\n", ch);

    char ch1 = 'A'; //���ڷ� �ʱ�ȭ, ����� ���� ������ �ƽ�Ű �ڵ� ��
    char ch2 = 65; //���� 'A'�� �ƽ�Ű �ڵ� ���� �ش��ϴ� ������ �ʱ�ȭ

    printf("���� %c�� �ƽ�Ű �ڵ� �� : %d\n", ch1, ch1);
    printf("�ƽ�Ű �ڵ� ���� %d�� ���� : %c\n", ch2, ch2);

    short sh = 32767;
    int in = 2147483647;
    long ln = 2147483647;
    long long lln = 123456789;

    printf("short�� ���� ��� : %d\n", sh);
    printf("int�� ���� ��� : %d\n", in);
    printf("long int�� ���� ��� : %ld\n", ln);
    printf("long long int�� ���� ��� : %lld\n", lln);

    printf("char���� ũ�� : %d����Ʈ\n", sizeof(char));
    printf("short���� ũ�� : %d����Ʈ\n", sizeof(short));
    printf("int���� ũ�� : %d����Ʈ\n", sizeof(int));
    printf("long int���� ũ�� : %d����Ʈ\n", sizeof(long int));
    printf("long long���� ũ�� : %d����Ʈ\n", sizeof(long long));

    //unsigned�� �߸� ����ϴ� ���
    unsigned int x;

    x = 4294967295; // ū ��� ����
    printf("%d\n", x); //%d�� ���, %d�� ��ȣ���� �����ؼ� 10������ ����ϴ� ��ȯ ����
    x = -1;  // ���� ����
    printf("%u\n", x); //%u�� ���, %u�� ��ȣ ���� 10������ ����ϴ� ��ȯ ����

    // ��ȿ ���� Ȯ��
    float ft = 1.234567890123456789;
    double db = 1.234567890123456789;

    printf("float�� ������ �� : %.20f\n", ft);
    printf("double�� ������ �� : %.20lf\n", db);

    char fruit[20] = "strawberry";

    printf("���� : %s\n", fruit);
    printf("����´ : %s %s \n", fruit, "jam");

    // char �迭�� ���ڿ� ����

    char fruits[20] = "strawberry";

    printf("%s\n", fruit);
    strcpy(fruits, "bannaa");
    printf("%s\n", fruits);

// const�� ����ϸ� �ʱ�ȭ�� ���� �ٲ� �� ����.
int income = 0;
double tax;
const double tax_rate = 0.12;

income =456;
tax = income * tax_rate;
printf("������ : %.1lf�Դϴ�.\n", tax);

    return 0;
}

// ���� ����: ���ڴ� �ƴ����� ��� ��Ŀ� ������ �ִ� ����. ��������(\)�� �Բ� ����Ѵ�.
// \n : new line, �� �ٲ�
// \b : backspace, �� ĭ �������� �̵�
// \t : 8ĭ ���������� �̵�
// \r : carriage return, �� ������ �̵�
// \a : alert, �� �Ҹ�, ���Ҹ��� ����

// ������ %d, �Ǽ��� %lf(long float)�� ����Ѵ�.

//normalization notation ; ����ȭ ǥ���, �Ҽ��� �տ� 0�� �ƴ� ��ȿ ���� �� �ڸ��� ����Ͽ� ���� ���·� �ٲ� ��

//���ڴ� ��������ǥ(���� ���)�� ����, ���ڿ��� ū����ǥ(���ڿ� ���)�� ���´�. �ϳ��� ���ڶ� ū����ǥ�� ������ ���ڿ� �����.

//float���� ��ȿ ���� 7�ڸ�, double���� 15�ڸ��� ���� ���� ���� ����ϴ� �� ����.
//long double���� ũ��� �����Ϸ����� �ٸ���. ���н��� ���������� ����ϴ� gcc �����Ϸ��� 16����Ʈ, VC++ �����Ϸ��� double���� ���� 8����Ʈ�� ó���Ѵ�.
//long duble�� ��� ��ȯ ���ڴ� %Lf
//Dev-C++ �����Ϸ��� 12����Ʈ, TC++ �����Ϸ��� 10����Ʈ�� ó���Ѵ�.
//�Ǽ��� double�� ������ �����ϴ� �� �����ϰ�, �� float�� ������ ����Ѵٸ� ������ ���� 1.23f(�Ǵ� 1.23F)�� ���� f,F�� �ٿ��� 4����Ʈ ũ���� ����� ó���ǵ��� �ۼ��ϴ� �� ����.

/*
char �迭��[���ڿ� ���� + 1] = ���ڿ�;
 - ���ڿ��� ���̺��� �迭�� ũ�⸦ �ϳ� �� ũ�� ��ƾ� �ϴ� ������ �����Ϸ��� ���ڿ��� ����
 - \0(null character)�� �ڵ����� �߰��ϱ� �����̴�. �� ���ڴ� ���ڿ��� ���� ǥ���ϴ� Ư���� ���ڴ�.

���� ���, apple�� �����Ϸ���
char fruit[6] = "apple";
*/

//strcpy ; string copy �Լ�

// reserved word(�����) ; �����Ϸ��� ��� ����� ��ӵ� �ܾ�
// identifier(�ĺ���) ; �ʿ信 ���� ����� ����ϴ� �ܾ�