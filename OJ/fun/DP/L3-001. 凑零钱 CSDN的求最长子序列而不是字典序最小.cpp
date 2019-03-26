#include <cstdio>
#include <vector>
#include <algorithm>
#include<cstring>
#include <iostream>
#define inf 0x3f3f3f3f
using namespace std;
using namespace std;
typedef long long ll;
const int maxn=1e4+10;
int dp[111],ans[maxn],a[maxn],pre[maxn];
void print(int u)
{
    if(!pre[u])
    {
        printf("%d",ans[u]);
        return ;
    }
    print(pre[u]);
    printf(" %d",ans[u]);
}
int main()
{
    freopen("1.txt", "r", stdin);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    memset(dp,-inf,sizeof(dp));
    memset(pre,-1,sizeof(pre));
    dp[0]=0;
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++)
    {
        for(int j=m; j>=a[i]; j--)
        {
            if(dp[j]<=dp[j-a[i]]+1)
            {
                dp[j]=dp[j-a[i]]+1;
                ans[j]=a[i];
                pre[j]=j-a[i];
            }
        }
    }
    //cout<<dp[m]<<endl;
    if(dp[m]>0)
    {
        print(m);
    }
    else
        cout<<"No Solution"<<endl;
    return 0;
}
