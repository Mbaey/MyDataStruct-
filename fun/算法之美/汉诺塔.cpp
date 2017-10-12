#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
#include <queue>

int c;
void hnt(char x, char y, char z, int a)//把在x上的a曾移到z上
{
    if(a>0){
        hnt(x, z, y, a-1);//把在x上的a-1曾移到y上
        printf("No.%d 步把%c上的 第%d个盘子 移到%c上\n", c++, x, a, z);
        hnt(y, x, z, a-1);//把在y上的a-1曾移到y上
    }

}
int main()
{
    freopen("hnt20c层.txt", "w", stdout);
    hnt('x', 'y', 'z', 20);


    return 0;
}
