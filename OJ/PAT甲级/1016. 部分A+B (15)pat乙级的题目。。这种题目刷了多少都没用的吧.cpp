#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
    freopen("1.txt", "r", stdin);
    long a, d, p, sum=0;
    cin >> a >> d;

    int cnt = 0;
    while(a != 0){
        int t= a%10;
        a /= 10;
        if(t == d){
            sum += d * pow(10, cnt++);
//            cout << sum << endl;
        }
    }
    cin >> a >> d;
    cnt = 0;
    while(a != 0){
        int t= a%10;
        a /= 10;
        if(t == d){
//            cout << sum << " "<< d * pow(10, cnt)<<endl;
            sum += d * pow(10, cnt++);
        }
    }

    cout << sum;
    return 0;
}
