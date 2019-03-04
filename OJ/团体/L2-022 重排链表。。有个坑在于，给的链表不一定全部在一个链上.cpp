#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
const int N=1e6+5;
#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)

int n,m,k;
int v,cnt=1;

int P[N]= {0};
//vector<int> maps[N];
//int maps[N][N]= {0};
//有个坑在于给的链表不一定全部在一个链上
int d[N],nt[N];

int main()
{

    freopen("1.txt", "r", stdin);
    int a;
    cin >> a>> n;
    int ta,td,tn;
    _for(i, 0,n){
        cin>>ta>>td>>tn;
        d[ta]=td;
        nt[ta]=tn;
    }

    ta = a;
    int cnt=0;
    while(ta != -1){
//        if(nt[ta] == -1){
//            printf("%05d %d -1\n", ta, d[ta]);
//        }else
//            printf("%05d %d %05d\n", ta, d[ta], nt[ta]);
        P[cnt++] = ta;
        ta=nt[ta];
    }

    int order[cnt] = {0};
    _for(i, 0 , cnt / 2  ){// 3/2= 1  4/2= 2
        order[i*2]= cnt-i-1;
        order[i*2 + 1]=i;
    }
    if(n%2){
        order[n-1] = cnt/2;
    }

    _for(i,0,cnt-1){
        ta = P[order[i]];
        printf("%05d %d %05d\n",ta , d[ta], P[order[i+1]]);
    }
        ta = P[order[cnt-1]];
    printf("%05d %d -1\n", ta, d[ta]);
//        printf("%d \n",order[i]);

    return 0;
}
