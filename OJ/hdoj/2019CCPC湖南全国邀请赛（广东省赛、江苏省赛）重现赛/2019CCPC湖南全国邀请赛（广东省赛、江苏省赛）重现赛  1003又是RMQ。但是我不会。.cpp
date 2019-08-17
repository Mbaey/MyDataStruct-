#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define _for(i,a,b) for(int i=a; i<b; i++)
//http://acm.hdu.edu.cn/contests/contest_show.php?cid=858
const int N=2e4;
int n,m,K, h, cnt=0;
//int a[N], cnt=0, vis[N];
int a[N], vis[N];
int dp[N][N];
int main()
{
//    freopen("1.txt", "r", stdin);
    cin >> n >> m >> K;
    _for(i,0,n){
        scanf("%d", a+i );
    }

    _for(i,0,n){
        dp[i][i] = 0;
        _for(j,i+1,n){
            int cnt=0;
            for(int k=j-1; k>=i; --k){
                if(abs(a[k]-a[j]) <= K){
                    cnt++;
                }
            }
            dp[i][j] = dp[i][j-1] + cnt;
        }
    }
    int u,v;
    _for(i,0,m){
        scanf("%d %d", &u, &v);
        printf("%d\n", dp[u-1][v-1]);
    }

    return 0;
}