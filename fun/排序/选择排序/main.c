#include <stdio.h>
#include <stdlib.h>
#define N 4
//√∞≈›≈≈–Ú£°
void Insertion(int a[]);

int main()
{
    int a[N], i;
    for(i = 0; i < N; i++)
    {
        printf("Input a No.%d\n", i);
        scanf("%d", &a[i]);
    }
    Insertion(a);

    for(i = 0; i < N; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}

void Insertion(int a[])
{
    int i, j, c, t;
    for(i = 0; i < N ; i++)
    {
        c = i;
        for(j = i + 1; j < N; j++)
        {
            if(a[c] > a[j])
                c = j;
        }
        if(c != i)
        {
            t = a[i];
            a[i] = a[c];
            a[c] = t;
        }

    }
}

