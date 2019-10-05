#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)

const int INF = 1e8;
const int N=1e5+5, L=1e4+5;
//vector<int> maps[N];
//int maps[N][N]= {0}, target[N][N]= {0};

int mod = 1000000007;
int n,m,t,k;
int a[N]= {0}, vis[N];

int main()
{
//    freopen("1.txt", "r", stdin);

    scanf("%d", &n);
    _for(i,1,n+1){
        scanf("%d", &k);
        a[i] += a[i-1] + k;
    }

    //floyd!

    scanf("%d", &m);
    int l, r;
    _for(i,1,m+1){
        scanf("%d %d", &l, &r);
        if(l > r){
            swap(l,r);
        }
        l--, r--;
        int forward=a[r]-a[l];
        int back=a[n]-forward;
        int res =  min(forward, back);
        cout << res <<endl;
    }

    return 0;
}
/*
5 1 2 4 14 9
3
1 3
2 5
4 1

3
10
7
 1 2 3 4  5
0 1 3 7 21 30 £¨ÀÛ¼Ó£©
1 3£º a[2]-a[0] : a[5] - a[2] ?
		3			27
2 5: a[4] - a[1] : a[5]-a[4] + a[1]-a[0]
		20			9+1
*/
