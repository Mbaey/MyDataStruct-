#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int i=1;//记录步数
void move(int n,char from,char to) //将编号为n的盘子由from移动到to
{
    printf("No.%d step: %d's plate %c--->%c\n", i++, n, from, to);

}
//汉诺塔递归, 将n个盘子从x移动到z
void HNT(int n, char x, char y, char z)
{

    if(n < 2)
    {
        move(n, x, z);
    }
    else
    {
        HNT(n - 1, x, z, y);
        move(n, x, z);
        HNT(n - 1, y, x, z);
    }
}

int main()
{
     printf("please input the number of plate:\n");
     int n;
     scanf("%d",&n);
     char x='A',y='B',z='C';
//     printf("盘子移动情况如下:\n");
     HNT(n,x,y,z);
     return 0;
}
