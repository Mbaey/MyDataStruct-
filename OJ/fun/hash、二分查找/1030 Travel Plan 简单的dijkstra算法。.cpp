#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N=505;//ms
const int INF=N*N;//ms

/*
it must be satisfied that n​1​​ =n​3​​ =max { k | k≤n​2​​  for all 3≤n​2​​ ≤N } with n​1​​ +n​2​​ +n​3​​ −2=N.
*/


int main(){
	freopen("1.txt", "r" ,stdin);
	int n, m, s, d;
    //vector<vector<int>> Map;

    int Map[N][N]={0}, costMap[N][N]={0};

    int dist[N]={0}, cost[N]={0}, vis[N]={0};
    cin >> n >> m >> s >> d;
//    init();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            if(i != j)//?? 是否  floyd算法是Map[i][i] = 0 dijkstra一般都初始化为INF即可。 但是这样也可以。
                Map[i][j] = INF;
    }

    int loop=m, City1, City2, Distance, Cost;

    while(loop--){
        scanf("%d %d %d %d", &City1, &City2, &Distance, &Cost);
        Map[City1][City2]=Distance;
        Map[City2][City1]=Distance;

        costMap[City1][City2]=Cost;
        costMap[City2][City1]=Cost;
    }

    fill_n(dist, n, INF);
    fill_n(cost, n, INF);
    dist[s]=0; cost[s]=0;
    int now=s;

    int fa[N];//def: fa[next] = s 存的是 s->next
    fill_n(fa, n, -1);
    for(int i=0; i<n; i++){
        int disMin=INF;
        for(int j=0; j<n; j++) if(!vis[j] && disMin > dist[j]){//??
            disMin = dist[j];
            now = j;
        }

        vis[now]=1;

        for(int j=0; j<n; j++){
            if(!vis[j] && dist[j] > dist[now] + Map[now][j]){// 小心溢出
                dist[j] = dist[now] + Map[now][j];
                cost[j] = cost[now] + costMap[now][j];

                fa[j] = now;
            }else if(!vis[j] && dist[j] == dist[now] + Map[now][j]){
                if(cost[j] > cost[now] + costMap[now][j]){
                    cost[j] = cost[now] + costMap[now][j];
                    fa[j] = now;
                }
            }
        }

    }
    list<int> res;
    int e = d;
    while(e != -1){
        res.push_front(e);
        e = fa[e];
    }

    for(int i : res){
//        printf("city:%d cost:%d\n", dist[i], cost[i]);
        printf("%d ", i);
    }

    printf("%d %d", dist[d], cost[d]);



    return 0;
}
