
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

long long g(long long a, long long b){
    return b==0? a : g(b, a%b);
}
void simple(long long &a, long long &b){
    long long c = abs(g(a, b));
    if(c!=0){
        a/=c;
        b/=c;
    }
}
void f(const long long a1, const long long b1, long long *a2, long long *b2)
{
//    if(*a2 != 0 && a1 != 0){
        *a2 = a1*(*b2) + (*a2)*b1;
        *b2 = b1*(*b2);
        simple(*a2, *b2);
//    }
}

int main()
{
    freopen("1.txt", "r", stdin); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!
    long long a[105] = {0}, b[105] = {0};
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {   char t;
        cin >> a[i] >> t >> b[i];
    }

    for(int i = 0; i < n - 1; i++)
    {
        f(a[i], b[i], &a[i+1], &b[i+1]);
    }
    int i = n-1;
    //cout << a[n - 1] << '/' << b[n - 1] << endl;
    simple(a[i], b[i]);
    int c = a[i] / b[i];
    bool flag = abs(a[i]) > abs(b[i]); //标记a[i] 与b[i]谁大  =true 表示有整数
    bool flag1 = a[i] % b[i] == 0;//标记 = true 表示没有分数


    if(flag && flag1 )//3
    {
        cout << c << endl;
    }
    else if(!flag && !flag1 )
    {
        cout << a[n - 1] << '/' << b[n - 1] << endl;
    }
    else if(flag && !flag1)
    {
        a[i] -= b[i] * c;
//        if(c != 0)
        cout << c << ' ';
        cout << a[n - 1] << '/' << b[n - 1] << endl;
    }
    else{
        cout << 0;
    }
    return 0;
}
