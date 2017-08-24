#include <stdio.h>
#include<time.h>
int main()
{
    int a;
    scanf("%d", &a);
    printf("%d\n", a);
    printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
