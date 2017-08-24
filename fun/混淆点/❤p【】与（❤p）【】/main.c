#include <stdio.h>
#include <stdlib.h>
#define N 10
int main()
{
    int a[2][3] = {{1,2,3},{4,5,6}};
    int *p[2], (*pt)[3] = a, i, j;
    for(i = 0; i < 2; i++)
    {
        p[i] = a[i];
        for(j = 0; j < 3; j++)
        {
            printf("%d ", pt[i][j]);
        }
        printf("\n");
    }
    return 0;
}
