#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1000;
const int inf = 1<<15;
//输入无根树的结点个数n，输入n-1条边(u, v)，输入欲指定的根的编号root，建立以root为根的树
int G[maxn][maxn];
int root=1,n, m, p[maxn];
bool vis[maxn]={0};
int main(){
    freopen("1.txt", "r", stdin);
    cin >> n >> m;
    int u, v, w;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            G[i][j]=inf;
        }
    }
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        G[u][v]=w;
        G[v][u]=w;
    }
//    for(int i=1; i<=n; i++){//test in
//        for(int j=1; j<=n; j++){
//            printf("%d ", G[i][j]);
//        }printf("\n");
//    }
    //dijkstra
    puts("dijkstra");
    for(int i=1; i<=n; i++){
        p[i]=inf;
    }
    p[root]=0;
    for(int i=1; i<=n; i++){
        int min=inf, x;
        for(int j=1; j<=n; j++){ if(!vis[j] && min >p[j]) { x=j; min=p[j];}        }
        vis[x]=1;
        for(int j=1; j<=n; j++){
            if(p[j] > p[x] + G[x][j]){
                p[j] = p[x] +  G[x][j];
            }
        }
    }
    for(int i=1; i<=n; i++){
        printf("%d ", p[i]);
    }
    putchar('\n');
    puts("floyd");
    //floyd
    for(int i=1; i<=n; i++)
        G[i][i] = 0;
//   for(int k=1; k<=n; k++)
    /* 有bug！
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(G[root][i] > G[root][j] + G[j][i]){
                G[root][i] = G[root][j] + G[j][i];
            }
        }
    }*/
//    int k=1;
    for(int k=1; k<=n; k++)
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            //for(int k=1; k<=n; k++) // f k is local in here  will cause bug
            if(G[i][j] > G[k][j] + G[i][k]){
                G[i][j] = G[k][j] + G[i][k];
            }
        }
    }
    for(int i=1; i<=n; i++){
        printf("%d ", G[root][i]);
    }

    return 0;
}

/* 1.txt
4 5
1 2 5
1 3 3
1 4 1
2 3 1
3 4 1


4 5
1 2 1
1 3 3
1 4 5
2 3 1
3 4 1
*/
