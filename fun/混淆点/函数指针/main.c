#include <stdio.h>
#include <stdlib.h>
#define N 10

void PA(const void *_tmp, int num, int width,
               void (*_printf)(const void *))
{
    int i;
    for(i = 0; i<num; i++)
        {
             _printf((char *)_tmp + i*width);
             printf(" ");
        }
    printf("\n");
}
void Pi(int *i)
{
    printf("%d", *i);
}
void Pc(char *i)
{
    printf("%c", *i);
}
void swap_i(int *i, int *j)
{
    int c;
    c = *i;
    *i = *j;
    *j = c;
}
void swap_c(char *i, char *j)
{
    char c;
    c = *i;
    *i = *j;
    *j = c;
}
int compare_i(int *a, int *b)
{
    if(*a < *b)
        return 1;
    else
        return 0;
}
int compare_c(char *a, char *b)
{
    if(strcmp(a, b) < 0)
        return 1;
    else
        return 0;
}
void Sort(const void *a, int l, int w, int (*compare)(void *, void *), void (*swap)(void *, void *))
{
    int i, j, min;
    for(i=0; i<l-1; i++)
    {
        min = i;
        for(j=i+i; j<l; j++)
        {
            if(compare((char *)a + j*w, (char *)a+ min* w))
            min = j;
        }
        swap((char *)a + i*w, (char *)a+ min* w);
        PA(a, l, sizeof(char), Pc);

    }

}

int main()
{
    int i;
    int const a[N]=  {9, 2, 3, 8, 1, 5, 6, 4, 7, 12};
    char c_char[10] = {'g', 'h', 't', 'a', 'd', 'w', 'q', 'b', 'm', 'c'};
    Sort(a, N, sizeof(int), compare_i, swap_i);
    Sort(c_char, N, sizeof(char), compare_c, swap_c);
    PA(a, N, sizeof(int), Pi);
    PA(c_char, N, sizeof(char), Pc);
    return 0;
}
