#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void PA(int a[], int n)
{
    int i=0;
    for(; i<n; i++)
        printf("%d  ", a[i]);
    printf("\n");
}

void Swap(int *a, int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void sort(int a[], int n)
{
    int i, j;
    int f, g = n;
    do
    {
        g /= 2;
        do
        {
            f = 1;
            for(i=0; i<=n-g; i++)
            {
                j = i + g;
                if(a[j] > a[i])
                {
                    Swap(&a[j], &a[i]);
                    PA(a, N);
                    f = 0;
                }
            }
        }while(f != 1);
    }while(g != 0);
}

int main()
{
    int a[N];
    int i = 0;

    srand(time(NULL));
    for(; i<N; i++)
        a[i] = rand() % 100 + 1;
    PA(a, N);
    sort(a, N);
    printf("After quick sort:\n");
    PA(a, N);
    return 0;
}


