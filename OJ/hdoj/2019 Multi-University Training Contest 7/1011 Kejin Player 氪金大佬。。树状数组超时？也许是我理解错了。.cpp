#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e8;
const int N=5e6+5, L=1e4+5;

#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)


int n,m,k;

int C[N]= {0};
//vector<int> a(N);
//vector<int> maps[N];
//int maps[N][N]= {0}, target[N][N]= {0};
//int vis[N][N]= {0};
//int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int mod = 1e9+7;

int R[N], S[N];
int X[N], A[N];

int lowbit(int x) {
   return x & -x;
}

void add(int x, int v){//n=3，则有4个等级。
    for(int i = x; i <= n+1; i += lowbit(i)){
        C[i] += v;
    }
}
int sum(int x){
    int s =0;
    for(int i = x; i ; i -= lowbit(i)){
        s += C[i];
    }
    return s;
}
int tmp[N]={0};
int main()
{
//    freopen("1.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    int q, l, r;
    while(t--){
        memset(C, 0, sizeof(C));
        scanf("%d %d", &n, &q);

        _for(i,1,n+1){
            //充Ai的钱，有ri/si.的概率升级到下一级，否则降到Xi。
            scanf("%d %d %d %d", R+i, S+i, X+i, A+i);
//            printf("%d %d %d %d\n", R[i], S[i], X[i], A[i]);

            if( X[i] == i){//回退到当前等级。
                int value = (int)(A[i] / (R[i]*1.0/S[i])) % mod;
                add(i, value);
//                tmp[i] = (int)(A[i] / (R[i]*1.0/S[i])) % mod;
            }else{
                int value = (int )(A[i] * S[i] + (sum(i-1)- sum(X[i]-1))*(R[i]) ) % mod;
                add(i,  value) ;
//                tmp[i] = value;
            }
        }

//        _for(i,1,n+1){
//
//        }



        _for(i,0,q){
            scanf("%d %d", &l, &r);
            printf("%d\n", sum(r) - sum(l-1));
        }
    }
//      test 树状数组
//    add(1,1);
//    add(2,2);
//    add(3,3);
//
//    printf("%d\n", sum(3));
//    printf("%d", 4* (1.0/3) % 3);
    return 0;
}
