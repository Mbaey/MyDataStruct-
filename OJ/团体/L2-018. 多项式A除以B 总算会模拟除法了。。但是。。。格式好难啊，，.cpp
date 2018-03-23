#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define N 1000000

struct poly{
    double c[N];
    int n;

    void sub(poly b){ //a=a-b
        for(int i=0; i<N; i++){
            if(c[i] || b.c[i]){//如果之一 不为零
                c[i]=  c[i]-b.c[i];
            }
        }
    }

    poly muti(int a){
        poly res;
        for(int i=0; i<N; i++){
            if(c[i] != 0){//如果之一 不为零
                res.c[i]=  c[i]*a;
            }
        }
        return res;
    }

    void dis(int max){
        n=0;
        for(int i=0; i<=max; i++){
            if(abs(c[i])> 0.05){
                n++;
            }
        }
        cout << n;
        if(n==0){
            cout << " 0 0.0"<<endl;
        }else for(int i=max; i>=0; i--){
            if(abs(c[i]) > 0.05){
                printf(" %d %.1f", i, c[i]);
            }
        }
        cout << endl;
    }
};
poly a, b, res;
int main()
{
    freopen("1.txt", "r", stdin);
    int n;
    cin >> n;

    int e, am, bm;
    double c;
    for(int i=0; i<n; i++){
        cin >> e>> c;
        if(i==0) am=e;
        a.c[e]= c;
    }

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> e>> c;
        if(i==0) bm=e;
        b.c[e]= c;
    }

    for(int i=am; i>=bm; i--){
        res.c[i-bm] = a.c[i] / b.c[bm];
        for(int j=bm; j>=0; j--){
            a.c[i+j-bm] -= b.c[j] * res.c[i-bm];
        }
    }
    res.dis(am-bm);
    a.dis(bm-1);

    return 0;
}

