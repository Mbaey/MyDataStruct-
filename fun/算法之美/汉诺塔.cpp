#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
#include <queue>

int c;
void hnt(char x, char y, char z, int a)//����x�ϵ�a���Ƶ�z��
{
    if(a>0){
        hnt(x, z, y, a-1);//����x�ϵ�a-1���Ƶ�y��
        printf("No.%d ����%c�ϵ� ��%d������ �Ƶ�%c��\n", c++, x, a, z);
        hnt(y, x, z, a-1);//����y�ϵ�a-1���Ƶ�y��
    }

}
int main()
{
    freopen("hnt20c��.txt", "w", stdout);
    hnt('x', 'y', 'z', 20);


    return 0;
}
