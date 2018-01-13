#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("1.txt", "r", stdin);
    int n, p=0, cnt=0;
    cin >> n;
    for(int i=0; i<n; i++){
        int q = p;
        cin >> p;
        if(p > q){
            cnt += (p-q)*6;
        }else{
            cnt += (q-p)*4;
        }
        cnt +=5;
    }
    cout << cnt;

    return 0;
}
