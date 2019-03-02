#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
const int MAX=105;
int N, M, K;
int a,b,r;
int heat[MAX][MAX]={0};

int P[MAX]={0};
int find(int i){
    return P[i]==-1? i : P[i]=find(P[i]);
}

void Union(int a,int b){
    a=find(a); b=find(b);
    if(a != b){
        P[a]=b;
    }
}
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> N >>M>>K;
    fill_n(P,MAX,-1);
    for(int i=0; i<M; i++){
        cin >>a>>b>>r;
        if(r==1){
            Union(a,b);
        }else{
            heat[a][b]=1;
            heat[b][a]=1;
        }
    }

    for(int i=0; i<K; i++){
        cin >>a>>b;
        bool f=0,h=0;
        if(heat[a][b]) h=1;
        if(find(a)== find(b)) f=1;

        if(f && !h){
            printf("No problem\n");
        }else if(!f&&!h){
            printf("OK\n");
        }else if(f && h){
            printf("OK but...\n");
        }else
            printf("No way\n");
    }

    return 0;
}
