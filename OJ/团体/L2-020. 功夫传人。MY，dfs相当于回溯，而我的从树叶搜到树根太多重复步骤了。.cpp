#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <cmath>
using namespace std;
int f[100005], dai=0;
void find(int n){
    dai = 0;
    while(n != 0){
        n = f[n];
        dai++;
    }
}

int main()
{
    freopen("1.txt", "r", stdin);
//    double sum = 4294967297.0;
    int n, di, td; //弟子
    double z, r, sum;
    cin >>n>>z>>r;

    for(int i=0; i<n; i++){
        cin >> di;
        for(int j=0; j<di; j++){
            cin >> td;
            f[td] = i;
        }
        if(di == 0){
            cin >> td;//放大倍数
            find(i);
            sum += td * pow( 1-r*0.01,dai)* z;
        }
    }
    printf("%d", (int)sum);
    return 0;
}
