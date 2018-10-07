#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
using namespace std;

const int N=200002;
int n, m, k;
vector<int> g[N];
int cnt=0, cnt1;
vector<bool> vis(N);
void dfs(int a, int h){
    vis[a]=1;cnt++;
    for(int i : g[a]){
        if(h==1){
            cnt1++;
        }
        if(!vis[i]){
            dfs(i, h+1);
        }
    }
}
int main()
{
    freopen("1.txt", "r", stdin);
    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d %d %d", &n, &m, &k);
        vis.clear();
        vis.resize(n);
        for(int i=0; i<n ;i++)
            g[i].clear();

        int x, y;
        for(int i=0; i<m ;i++){
            scanf("%d %d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int graphs=0;
        int maxD=0, gra=0;
        for(int i=0; i<n ;i++){
            if(maxD < g[i].size()){
                maxD = g[i].size();
                gra=i;
            }
        }
        cnt=0; cnt1=0;
        dfs(gra, 1);
        cnt = cnt-cnt1-1;

        if(cnt>0){
            if(cnt<k){// 如果可以 把孩子的图全部打散 就打散
                graphs += cnt;
                k -= cnt;
            }else{//否则 只打散k个。
                graphs+=k;
                k=0;
            }
        }

        for(int i=0; i<n ;i++){
            if(!vis[i]){
                cnt=0;
                dfs(i, 1);

                cnt--;//该图中有几条边。
                if(cnt>0){
                    if(cnt<k){// 如果可以 全部打散 就打散
                        graphs += cnt;
                        k -= cnt;
                    }else{//否则 只打散k个。
                        graphs+=k;
                        k=0;
                    }
                }

                graphs++;
            }
        }
        printf("%d\n", maxD+graphs);
    }

    return 0;
}
