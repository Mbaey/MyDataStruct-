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

int color[L]= {0}, l, cnt=0;

//最左和最右的数，只要不同，就一定要，no!!
//最长上升子序列 O(nlog2n) https://www.cnblogs.com/frankchenfu/p/7107019.html
int res=0;

int main()
{
    freopen("1.txt", "r", stdin);

    cin >> n >> m;
    int t;
    int order[m+1];
    _for(i, 1, m+1)
    {
        scanf("%d", &t);
        vis[t] = 1;
        a[i] = t;

        order[t] = i;// 最长 不下降 子序列
    }

    cin >> l;
    _for(i,0,l)
    {
        scanf("%d", &t);
        if(vis[t])
        {
//            color[cnt++] = t;
            color[cnt++] = order[t];//里面放它的 顺序，而不是颜色。 数据结构错了、、、
        }
    }

//    _for(i,0,cnt){
//        cout << color[i] << " ";
//    }
    int dp[l+1]= {0}, maxn=0;
    dp[0]=1;
    fill_n(dp, cnt+1, 1);//error。 =.= 但是哪里错了。定义错了。
    _for(i, 0, cnt)
    {
        _for(j, i+1, cnt)
        {
            if(color[j] >= color[i])
            {
                dp[j] = max(dp[i]+1, dp[j]);
            }
        }

    }
    _for(i, 0, cnt)
        maxn = max(maxn, dp[i]);
//    for(int i = 0; i < cnt; i++) { // liuchuo
//        dp[i] = 1;
//        for(int j = 0; j < i; j++)
//            if(color[i] >= color[j])
//                dp[i] = max(dp[i], dp[j] + 1);
//        maxn = max(dp[i], maxn);
//    }
    cout << maxn;

    return 0;
}

/*
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6

2 3 1 5 6
2 2 1 5 5 6 3 1 1 5 6
{2 2 1 1 1 5 6},
{2 2 1 5 5 5 6},
{2 2 1 5 5 6 6},
{2 2 3 1 1 5 6}

1 1 3 4 4 5 2 3 3 4 5
1 1 3 3 3 4 5
1 1 3 4 4 4 5
1 1 3 4 4 5 5
1 1 2 4 4 4 5
*/
