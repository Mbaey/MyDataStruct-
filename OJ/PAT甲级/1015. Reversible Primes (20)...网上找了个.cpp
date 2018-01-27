#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int rev_num(int num1,int radix) //判断基数radix下的倒叙数（还是转换为10进制的）
{
    int num2 = 0;
    while(num1)
    {
        num2 *= radix;
        num2 += num1 % radix;
        num1 /= radix;
    }
    return num2;
}
bool isPrim(int a)
{
    if(a <= 1)
        return false;
    for(int i=2; i<=sqrt(a); i++)
    {
        if(a % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("1.txt", "r", stdin);
    int d;
    int n;
    while(cin >> n>> d)
    {
//        cout << s << "n:" << endl;
        if(n <0)
            return 0;
        int n_rev;
        n_rev = rev_num(n,d);
        if(isPrim(n) && isPrim(n_rev))
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }

}
