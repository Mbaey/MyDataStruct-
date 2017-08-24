#include <stdio.h>
#include <stdlib.h>
#define N 4
//Insertiong≈≈–Ú£°
void Insertion(int a[]);
void PA(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%4d", a[i]);
    printf("\n");
}

int main()
{
    int a[N], i;
    for(i = 0; i < N; i++)
    {
        printf("Input a No.%d\n", i);
        scanf("%d", &a[i]);
    }
    Insertion(a);

    printf("The end:\n");
    PA(a, N);

    return 0;
}

void Insertion(int a[])
{
    int i, j, t;
    printf("initial sorting:");
    PA(a, N);
    for(i = 1; i < N; i++)
    {
        t = a[i];
        for(j = i - 1; (j>=0) && (t<a[j]); j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = t;
        printf("after %d sorting:", i);
        PA(a, i+1);
    }
}
