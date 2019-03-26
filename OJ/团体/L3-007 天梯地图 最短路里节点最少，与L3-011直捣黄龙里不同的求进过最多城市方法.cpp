#include <bits/stdc++.h>
#include <sstream>
using namespace std;
#define _for(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int N=505,M=10, INF=1e8;

int n,m,k, t,len;

int a[N], vis[N];
int maps1[N][N];
int maps2[N][N];
//vector<int> maps[N];

void dis(vector<int> &a){
    len=a.size();
//    _for(i,0,len-1)
    for(int i=len-1; i>=1; i--){
        printf("%d => ", a[i]);
    }
    printf("%d\n",a[0]);

}

int main()
{
//    freopen("1.txt", "r", stdin);
    cin >> n >> m;
    int u,v,one,len, time;
    _for(i,0,m){
        cin >>u>>v>>one>>len>>time;
        if(one){
            maps1[u][v]=len;
            maps2[u][v]=time;
        }else{
            maps1[u][v]=len;
            maps2[u][v]=time;

            maps1[v][u]=len;//最短
            maps2[v][u]=time;//最快
        }
    }
    int s,e;
    cin >> s>>e;

    int dist1[N]={0}, vis1[N]={0}, fa1[N]={0};
    fill_n(fa1, n, -1);
    fill_n(dist1, n, INF);
    dist1[s]=0;
    _for(i, 0, n){
        int x,minD=INF;
        _for(y,0,n) if(!vis1[y] && minD> dist1[y]) minD=dist1[x=y];
        vis1[x]=1;
        //如果最短距离的路线不唯一，则输出途径节点数最少的那条,
        //能不松弛就不松弛。
        _for(y,0,n) if(maps1[x][y] != 0){
            if(dist1[y] > maps1[x][y]+minD){
                dist1[y] = maps1[x][y]+minD;
                fa1[y] = x;
            }else if(dist1[y] == maps1[x][y]+minD){
                int cntY=0,cntX=0;
                int ty=y,tx=x;
                while(ty!=-1){
                    ty=fa1[ty], cntY++;
                }

                while(tx!=-1){
                    tx=fa1[tx], cntX++;
                }
                //经过x到达y，节点少
                if(cntX+1<cntY){
                    fa1[y] = x;
                }
            }
        }
    }
    t=e;
    vector<int> res1;
    int dist=dist1[e];
    while(t != -1){
        res1.push_back(t);
        t=fa1[t];
    }

    /***************/

    int dist2[N]={0}, distLen[N]={0}, vis2[N]={0}, fa2[N]={0};
     fill_n(fa2, n, -1);
    fill_n(dist2, n, INF);
    fill_n(distLen, n, INF);
    dist2[s]=0; distLen[s]=0;
    _for(i, 0, n){
        int x,minD=INF;
        _for(y,0,n) if( !vis2[y] && minD> dist2[y]) minD=dist2[x=y];
        vis2[x]=1;
        //如果最快到达路线不唯一，则输出几条最快路线中最短的那条
        _for(y,0,n){
            if(maps2[x][y] != 0){
                if(dist2[y] > maps2[x][y]+minD){
                    dist2[y] = maps2[x][y]+minD;
                    fa2[y] = x;
                    distLen[y] = maps1[x][y]+distLen[x];
                }else if(dist2[y] == maps2[x][y]+minD){
                    if(distLen[y] > maps1[x][y]+distLen[x]){
                        distLen[y] = maps1[x][y]+distLen[x];
                        fa2[y] = x;
                    }
                }
            }
        }
    }
    t=e;
    vector<int> res2;
    int timeMin=dist2[e];
    while(t != -1){
        res2.push_back(t);
        t=fa2[t];
    }

    if(res1 == res2){
        printf("Time = %d; Distance = %d: ", timeMin, dist);
        dis(res1);
    }else{
        printf("Time = %d: ", timeMin);
        dis(res2);

        printf("Distance = %d: ", dist);
        dis(res1);
    }


    return 0;
}
