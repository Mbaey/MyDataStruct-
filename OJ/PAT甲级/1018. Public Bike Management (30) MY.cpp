#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 65536
using namespace std;
/**
���·�����⡣��Ҫ�����Ľڵ��Ȩ�غ����
dijkstra�㷨
 *
 */
int cmax, n, s, m;
int stas[501][501], we[501];//stations��վ,
int sht[501], vis[501]= {0}; //short
void show_stas(){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout << stas[i][j]<< " ";
        }
        cout << endl;
    }
}
void show_sht(){
    for(int i=0; i<=n; i++){
            cout << sht[i]<< " ";
    }
        cout << endl;
}
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> cmax >> n>>s>>m;
    cmax /=2;

    for(int i=1; i<=n; i++)
    {
        cin >> we[i];
        we[i] -= cmax;
    }
    fill(&stas[0][0], &stas[n][n]+1, INF);
//    show_stas();
    for(int i=0; i<m; i++)
    {
        int a, b, w;
        cin >> a>>b>>w;
        stas[a][b] =w;
        stas[b][a] =w;

    }
//    show_stas();
    //dijkstra
    fill_n(sht, n+1, INF);
    sht[0] = 0;
    int now=0, fa[501]={0}, cost[501]={0};
//    cost[now]=we[now];
//    show_sht();
    while(now != s){
        int min=INF;
        for(int i=0; i<=n; i++){
            if(sht[i] < min && ! vis[i]){
                now=i;
                min=sht[i];
            }
        }
        vis[now]=1;
//    cost[now]=we[now]; //�ȸ㶨fa
        //�ҵ�����һ������Ľڵ㣬ˢ��sht
        for(int i=0; i<=n; i++){
            if(sht[now] + stas[now][i] < sht[i]){
                sht[i] = sht[now] + stas[now][i];
                cost[i] = we[i] + cost[now];
                fa[i] = now;//i �ĸ����� now;
            }else if(sht[now] + stas[now][i] == sht[i]){
                if(cost[i] < we[i] + cost[now]){//���ú�����ָ��s�����ٵĻ��������С�ں� ����֮
                    cost[i] = we[i] + cost[now];
                    fa[i] = now;
                }
            }
        }
    }
//    for(int i=0; i<=n; i++){
//        cout << sht[i]<< " "<<cost[i]<<" "<< fa[i]<<endl ;
//    }


    //out
    cout << 0-cost[s]<< " "<<0;
    vector<int> res;
    while(s != 0){
        res.push_back(s);
        s=fa[s];
    }
    for(auto i=res.rbegin(); i!=res.rend(); i++){
        cout << "->"<< *i;
    }
    cout << " " << 0;

    return 0;
}
