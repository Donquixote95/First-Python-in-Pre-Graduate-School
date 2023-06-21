#include <stdio.h>

// way2. advanced

int main(void)
{
    int a[5] = {3, 2, 1, 6, 5};
    int i, j, temp;
    int min;

    for (i = 0; i < 4; i++)
    {
        min = i;
        for (j = i +1; j < 5; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

for (i = 0; i < 5; i++)
{
    printf("%5d", a[i]);
}

return 0;
}
// way 1. primitive
// int main(void)
// {
// int a[5] = {3, 2, 1, 6, 5};
// int i, j, temp;

// for (i=0; i<4; i++)
// {
//     for (j = i+1; j < 5; j++)
//     {
//         if (a[i] > a[j])
//         {
//             temp = a[i];
//             a[i] = a[j];
//             a[j] = temp;
//         }
//     }
// }

// for (i = 0; i < 5; i++)
// {
//     printf("%5d", a[i]);
// }

// return 0;
// }