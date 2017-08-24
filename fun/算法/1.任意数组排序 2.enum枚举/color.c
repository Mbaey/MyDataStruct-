#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "color.h"

void CreatTong(COL *t)
{
    srand(time(NULL));
    for(int i = 0; i < N; i++)
        t[i] = rand() % 3;
}
void Swap(COL *a, COL *b)
{
    COL t;
    t = *a;
    *a = *b;
    *b = t;
}

void Sort(COL *t, int n)
{
    int rr = -1, lb = n, nx = 0;
    while(nx != lb)
    {

        if(t[nx] == red)
        {
            rr++;
            Swap(&t[nx], &t[rr]);
//            nx++;
        }
        else if(t[nx] == blue)
        {
            lb--;
            Swap(&t[nx], &t[lb]);
        }
        else
            nx++;
        Display(t, N);
        printf("\n");
    }
//    while (nx != lb)
//    switch (t[nx])
//    {
//      case  red:    rr++;
//                    Swap(&t[nx], &t[rr]);
//                    nx++;
//                    break;
//      case  white:  nx++;
//                    break;
//      case  blue:   lb--;
//                    Swap(&t[nx], &t[lb]);
//                    break;
//    }
}

void Display(COL *t, int n)
{
    for(int i = 0; i < N; i++)
        printf("%d ", t[i]);
}
