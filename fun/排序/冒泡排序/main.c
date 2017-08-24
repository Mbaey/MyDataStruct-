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
}

void sort(int a[], int n)
{
    int i, j;
    int f;
    for(i=0; i<n-1 && f==0; i++)
    {
        f = 1;
        for(j=0; j<n-i-1; j++) //减少多余的排序！
        {
            if(a[j+1] > a[j])
            {
                Swap(&a[j+1], &a[j]);
                PA(a, N);
                f = 0;
            }
        }
        printf("\n");

    }


}

int main()
{
    int a[N];
    int i = 0;

    srand(time(NULL));
    for(; i<N; i++)
        a[i] = rand() % 100 + 1;
    PA(a, N);
    sort(a, N);
    printf("After quick sort:\n");
    PA(a, N);
    return 0;
}


