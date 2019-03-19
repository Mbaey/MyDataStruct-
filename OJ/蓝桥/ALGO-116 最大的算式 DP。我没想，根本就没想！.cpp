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

long long dp[16][16];
long long ans[16];
void init(int n,int k)
{
    long long num;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&num);
        ans[i]=num;
        sum+=num;
        dp[i][0]=sum;//在没有使用乘号的情况全部使用加法
    }
}

//https://www.cnblogs.com/lemonbiscuit/p/7776018.html
int main()
{
    freopen("1.txt", "r", stdin);

    scanf("%d%d",&n,&k);
    init(n,k);
    //先确定了dp[i][j]表示前i个数中使用了j个乘号的所得到最大值。
    for(int i=1;i<=n;i++)//n个数
    {
        for(int j=1;j<=i-1;j++)//最多有i-1个乘号，数量级较小，就不剪枝了
        {
            for(int p=2;p<=i;p++)//第j个乘号插入的位置，如果和前面的乘号位置重叠了，也不影响，还是原来的dp[i][j]
            {
                dp[i][j]=max(dp[i][j],dp[p-1][j-1]*(dp[i][0]-dp[p-1][0]));//从插入位置到i的和，一起乘总比一个乘要大
            }
        }
    }
    printf("%lld\n",dp[n][k]);
    return 0;
}
