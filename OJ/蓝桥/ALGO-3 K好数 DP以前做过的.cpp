#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
const int INF = 1e8;
#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)
const int N=205, L=1e4+5;

int n,m,k;

int a[N]= {0};
vector<int> maps[N];
//int maps[N][N]= {0};
int vis[N]= {0};

int dp[N][N]={0};
//L位数下，每个以k结尾的数字有多少个，
int main()
{
//    freopen("1.txt", "r", stdin);
    int l;
    cin >> k>> l;
    if(k==1){
        cout << 0;
        return 0;
    }

    if(l==1){
        cout << k;
        return 0;
    }
    _for(j,1,k)
        dp[1][j]=1;

    _for(i, 2, l+1){//L位
        _for(j, 0, k){
            _for(ii, 0, k){
                dp[i][j] = (dp[i][j] + dp[i-1][ii] * ( abs(ii -j) == 1 ? 0: 1))  % 1000000007;
            }
        }
    }
    int ans=0;
    _for(j,0,k)
        ans = (ans + dp[l][j]) % 1000000007;

    cout << ans;
    return 0;
}
