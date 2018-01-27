#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
我个人感觉是求图的最大联通数-1
但是我记得有一题有权重的 是用prim做的
*/
int w[1006][1006] = {0}, vis[1006]= {0};
int n, m, k;
void dfs(int j, int occupied){
    vis[j] = 1;
    for(int i=1; i<=n; i++){
        if(i!=occupied&& !vis[i] && w[j][i]==1){
            dfs(i, occupied);
        }
    }
}

int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n >> m >> k;
    for(int i=0; i<m; i++){
        int a, b;
        cin >>a >> b;
        w[a][b] = 1;
        w[b][a] = 1;
    }
    for(int i=0; i<k; i++){
        int cnt = -1, occupied=-1;//记录不连通分支数；
        cin >> occupied;
        fill_n(vis, n+1, 0);
        for(int j=1; j<=n; j++){
            if(!vis[j] && j != occupied){
                cnt++;
                dfs(j, occupied);
            }
        }
        cout << cnt << endl;
    }
}
