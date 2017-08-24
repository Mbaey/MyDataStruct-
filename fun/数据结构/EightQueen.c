#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define length 8
int c=1;//记录步数

void PrintMap(int M[][length])
{
    int i, j;
    printf("No.%d way:\n", c++);
    for(i = 0; i < length; i++)
    {
        for(j = 0; j < length; j++)
        {
            printf("%d ", M[i][j]);
        }putchar('\n');
    }putchar('\n');
}

void fuzhi(int m1[][length], int m2[][length])
{
    int i, j;
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            m1[i][j] = m2[i][j];
        }
    }
}

int NotConfilct(int M[][length], int row, int column)
{
    int i, j;
    for(i = row, j = column+1; j < 8; j++)
    {
        if(M[i][j] == 1)    return 0;
    }
    for(i = row, j = column-1; j >= 0; j--)
    {
        if(M[i][j] == 1)    return 0;
    }/*行*/
    for(i = row+1, j = column; i < 8; i++)
    {
        if(M[i][j] == 1)    return 0;
    }
    for(i = row-1, j = column; i >= 0; i--)
    {
        if(M[i][j] == 1)    return 0;
    }/*列*/

    for(i = row+1, j = column+1; i <= 7 && j <= 7; i++, j++)
    {
        if(M[i][j] == 1)    return 0;
    }
    for(i = row-1, j = column-1; i >= 0 && j >= 0; i--, j--)
    {
        if(M[i][j] == 1)    return 0;
    }
    for(i = row-1, j = column+1; i >= 0 && j <= 7; i--, j++)
    {
        if(M[i][j] == 1)    return 0;
    }
    for(i = row+1, j = column-1; i <= 7 && j >= 0; i++, j--)
    {
        if(M[i][j] == 1)    return 0;
    }
    return 1;


}

void queen(int M[][length], int row, int column)
{

    int map[8][8] , i= 0, j = 0;
    int f = 0;
    fuzhi(map, M);

    if(row == 8)
    {
        PrintMap(map);
    }
    else
    {
        for(j = 0, f = 0; j < length; j++)
        {
            f = NotConfilct(M, row, j);
            if(f == 1)
            {
                for(i = 0; i < length; i++)
                {
                    map[row][i] = 0;
                }
                map[row][j] = 1;
//                PrintMap(map);
                queen(map, row + 1, length);
            }
        }

    }
}


int main()
{
    int Map[length][length];
    memset(Map, 0, sizeof(Map));

    queen(Map, 0, length);
    return 0;
}
