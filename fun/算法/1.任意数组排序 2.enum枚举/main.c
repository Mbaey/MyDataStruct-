#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "color.h"


int main()
{
    COL Tong[N];

    CreatTong(Tong);
    Display(Tong, N);
    printf("\n");
    Sort(Tong, N);
    Display(Tong, N);


    return 0;
}

