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
const int N=10005, M=105;
const int INF = 1e8;
#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)

int n,m,k;

int a[N]= {0};
vector<int> maps[N];
//int maps[N][N]= {0};
int vis[N]= {0};
int isRoot[N]= {0};
int maxH=0, cnt=0;
vector<int> res;
void dfs(int r, int h, bool findRoot)
{
    if(findRoot)
        if(h>maxH)
        {
            maxH = h;
            res.clear();
            res.push_back(r);
        }
        else if(h==maxH)
        {
            if(!isRoot[r]){
                isRoot[r]=1;
                res.push_back(r);
            }
        }

    vis[r]=1;
    cnt++;
    for(int i : maps[r])
        if(!vis[i])
            dfs(i, h+1, findRoot);
}
int main()
{

    freopen("1.txt", "r", stdin);
    cin >> n;
    int u,v;
    _for(i,0,n-1)
    {
        cin >> u >> v;
        maps[u].push_back(v);
        maps[v].push_back(u);
    }

    dfs(1, 1, 1);
    if(cnt != n)
    {
        int com=1;
        _for(i,1,n+1)
        {
            if(!vis[i])
            {
                dfs(i, 1, 0);
                com++;
            }
        }
        printf("Error: %d components", com);
        return 0;
    }

    fill_n(vis, n+1, 0);
    fill_n(isRoot, n+1, 0);
    int root = res[0];
    dfs(root, 1, 1);

    vector<int> tmp = res;
    res.clear();
    fill_n(vis, n+1, 0);
    dfs(tmp[0], 1, 1);
    tmp.insert(tmp.end(), res.begin(), res.end());


    sort(tmp.begin(), tmp.end());


    fill_n(vis, n+1, 0);
    for(auto i : tmp)
    {
        if(!vis[i])
        {
            vis[i]=1;
            cout << i << endl;
        }
    }



    return 0;
}
