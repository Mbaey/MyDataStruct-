#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define N 1000005//原来是这里段错误。。
int n, maxd=0;
bool vis[N]={0};
vector<vector<int>> chd(N);
vector<int> res;
void dfs(int in, int d){
    if(d > maxd){
        maxd=d;
        res.clear();
    }
    if(d == maxd){
        res.push_back(in);
    }
    vis[in]=1;
    for(int i : chd[in]){
        if(!vis[i]){
            dfs(i, d+1);
        }
    }
}
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n;
    int t, s;
    for(int i=1; i<=n; i++){
        cin >> t;
        if(t==-1)
            s=i;
        else
            chd[t].push_back(i);
    }
    dfs(s, 1);
    cout << maxd<< endl;
    sort(res.begin(), res.end());
    for(int i=0; i<res.size(); i++){
        if(i!=0)
            cout <<" ";
        cout << res[i];
    }
    return 0;
}
