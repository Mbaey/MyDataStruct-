#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
const int MAX=10005;
int N, M, K;

int P[MAX]={0};

int main()
{
    freopen("1.txt", "r", stdin);
    cin >> N >>M>>K;
    for(int i=0; i<N; i++){
        int sum=0,mint=100, maxt=0, t;
        for(int j=0; j<M; j++){
            scanf("%d", &t);
            sum+=t;
            mint=min(mint,t);
            maxt=max(maxt,t);
        }
        P[i]=sum-mint-maxt;
    }
    sort(P,P+N, [](int a,int b)-> bool{return a>b;});

    for(int i=K-1; i>0; i--){
        printf("%.3f ", P[i]*1.0 / (M-2) );
    }
    printf("%.3f", P[0]*1.0 / (M-2) );

    return 0;
}
