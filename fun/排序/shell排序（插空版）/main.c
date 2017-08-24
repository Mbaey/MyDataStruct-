#include <stdio.h>
#include <stdlib.h>
#define N 6

void PN(int a[], int n)
{
     int i;
    for(i = 0; i < n; i++)
        printf("%4d", a[i]);
    printf("\n");
}

void ShellSort(int a[], int n)
{
    int i, j, k, t;
    int g = n;
    for(k = 0; k < n; k++)
    {
        g = g / 2;
        for(i = g; i < n; i++)
        {
            t = a[i];
            for(j = i - g; (j>=0)&&(a[j]>t); j = j - g)
            {
                a[j + g] = a[j];
            }
            a[j + g] = t;
            PN(a,N);
        }
        printf("g = %d\n", g);
        PN(a,N);
        if(g == 0)
            break;

    }

}


int main()
{
    int a[N], i;
    for(i = 0; i < N ; i++)
    {
        printf("Input a No.%d\n", i);
        scanf("%d", &a[i]);
    }
    PN(a,N);
    ShellSort(a, N);

    printf("The end:\n");
    PN(a, N);
    return 0;
}
