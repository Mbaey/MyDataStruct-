#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e8;
const int N=1e2+5, L=1e4+5;

#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)


//vector<int> a(N);
//vector<int> maps[N];
//int maps[N][N]= {0}, target[N][N]= {0};
//int vis[N][N]= {0};
//int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int mod = 998244353;
int n,m,t,k;
int a[N]= {0}, vis[N];

int l[N], r[N],data[N], cnt=0;
void pre_dfs(int root)
{
    int lc, rc;
    lc=l[root], rc=r[root];

    if(lc != -1)
        pre_dfs(lc);

    if(vis[lc+1])
    {
        data[root]=a[cnt++];
        vis[root+1]=1;
    }

    if(rc != -1)
        pre_dfs(rc);



}
int main()
{
//    freopen("1.txt", "r", stdin);
    scanf("%d", &n);

    _for(i,0,n)
    {
        scanf("%d %d", l+i,r+i);
    }
    _for(i,0,n)
    scanf("%d", a+i);

    sort(a,a+n);

    vis[0]=1;
    pre_dfs(0);

//    _for(i,0,n)
//        cout << data[i] << endl;
    queue<int> qu;
    qu.push(0);
    cnt=0;
    while(!qu.empty())
    {
        int lc, rc, root;
        root=qu.front();
        qu.pop();
        lc=l[root], rc=r[root];

        if(lc != -1)
            qu.push(lc);
        if(rc != -1)
            qu.push(rc);

        a[cnt++]=data[root];
    }

    _for(i,0,n)
    if(i == 0)
        cout << a[i];
    else
        cout <<" "<< a[i];
    return 0;
}
