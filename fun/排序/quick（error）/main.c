#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void PA(int a[], int n)
{
    int i=0;
    for(; i<n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}

void Swap(int *a, int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void Quick(int a[], int l, int r)
{
    int i, j, t;
    i=l;
    j=r+1;
    while(1)
    {
        do i++;
        while((a[i]>=a[l]) && i <= r);
        do j--;
        while((a[j]<=a[l]) && j >= l);
        if(i < j)
        {
            Swap(&a[i], &a[j]);
            PA(a, N);
        }
        else
            break;
    }
    Swap(&a[j], &a[l]);
    PA(a, N);
    Quick(a, l, j);
    Quick(a, j, r);
}

int main()
{
    int a[N];
    int i = 0;

    srand(time(NULL));
    for(; i<N; i++)
        a[i] = rand() % 10 + 1;
    PA(a, N);
    Quick(a, 0, N - 1);
    printf("After quick sort:\n");
    PA(a, N);
    return 0;
}


