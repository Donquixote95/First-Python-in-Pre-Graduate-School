#include <stdio.h>

void my_fflush(FILE *fp){
        while(fgetc(fp) != '\n'){ }
    }

int main(void)
{
    FILE *fp;
    int age;
    char name[20];

    fp = fopen("a.txt", "r");

    fscanf(fp, "%d", &age);
    while (fgetc(fp) != '\n'){}
    fgets(name, sizeof(name), fp);

    printf("age : %d, name : %s", age, name);
    fclose(fp);

    // int fflush(FILE *);

    return 0;
}