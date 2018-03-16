#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;
set<int> maps[501];
bool vis[501], lost[501];
int cnt=0, n;
void dfs(int c)
{
    if(vis[c] || lost[c]) return;
    vis[c] = true;
    for(int i=0; i<n; i++)
    {
        if(maps[c].count(i)==1)
        {
            dfs(i);
        }
    }
}
void get_connect()
{
    cnt=0;
    fill(vis, vis + n, false);
    for(int j=0; j<n; j++)
    {
        if(!vis[j] && !lost[j])
        {

            dfs(j);
            cnt++;
        }
    }
}
int main()
{
    freopen("1.txt", "r", stdin);
    int m, c1, c2, k;
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> c1 >>c2;
        maps[c2].insert(c1);
        maps[c1].insert(c2);
    }
    cin >> k;
    get_connect();
    int pre = cnt;
    for(int i=0; i<k; i++)
    {
        cin >> c1;
        lost[c1]= true;
        get_connect();
        if(cnt > pre)
        {
            printf("Red Alert: City %d is lost!\n", c1);
        }
        else
        {
            printf("City %d is lost.\n", c1);
        }
        pre = cnt;
    }
    if(k==n)
        cout << "Game Over.";
    return 0;
}
