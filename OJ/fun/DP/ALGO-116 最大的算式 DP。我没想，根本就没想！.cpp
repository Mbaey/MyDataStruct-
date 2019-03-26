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
        dp[i][0]=sum;//��û��ʹ�ó˺ŵ����ȫ��ʹ�üӷ�
    }
}

//https://www.cnblogs.com/lemonbiscuit/p/7776018.html
int main()
{
    freopen("1.txt", "r", stdin);

    scanf("%d%d",&n,&k);
    init(n,k);
    //��ȷ����dp[i][j]��ʾǰi������ʹ����j���˺ŵ����õ����ֵ��
    for(int i=1;i<=n;i++)//n����
    {
        for(int j=1;j<=i-1;j++)//�����i-1���˺ţ���������С���Ͳ���֦��
        {
            for(int p=2;p<=i;p++)//��j���˺Ų����λ�ã������ǰ��ĳ˺�λ���ص��ˣ�Ҳ��Ӱ�죬����ԭ����dp[i][j]
            {
                dp[i][j]=max(dp[i][j],dp[p-1][j-1]*(dp[i][0]-dp[p-1][0]));//�Ӳ���λ�õ�i�ĺͣ�һ����ܱ�һ����Ҫ��
            }
        }
    }
    printf("%lld\n",dp[n][k]);
    return 0;
}
