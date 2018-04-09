#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 1010, maxm = 10010, inf=1<<15;
int u[maxm], v[maxm], w[maxm];
int n, m, dist[maxn], nextEdge[maxm];//���Ϊe����һ���ߵı��
int first[maxn];//�ڵ�u�ĵ�һ���ߵı��

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> pque;
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n >> m;
    {//input
        fill(first,first+n+1, -1);
        for(int i=0; i<m*2; i++){
            cin >> u[i] >> v[i] >> w[i];
            nextEdge[i] = first[u[i]];//ֻ�ǲ�����ס���
            first[u[i]] = i;

            u[i+1] = v[i];
            v[i+1] = u[i];
            w[i+1] = w[i];

            nextEdge[i+1] = first[u[i+1]];
            first[u[i+1]] = i+1;
            i++;
        }
    }
    /*//test input
    {//travel all edge
        for(int i=1; i<=n; i++){
            printf("��%d������ı���: ", i);
            for(int e=first[i]; e != -1; e=nextEdge[e]){
                printf("-%d->%d ", w[e], v[e]);
            }
            cout << endl;
        }

    }*/
    {//dijkstra
        int source=1;
        fill(dist, dist+n+1, inf);
        dist[source]=0;
        pque.push(make_pair(dist[source], source));
        while(!pque.empty()){
            pii u=pque.top(); pque.pop();//�ҵ�����ĵ�
            int now = u.second;
            if(u.first != dist[now]) continue;

            for(int e=first[now]; e != -1; e=nextEdge[e]){
                if(dist[v[e]] > dist[now]+ w[e]){//ֱ�ӵ�v �� ����u�ٵ�v ��
                    // now ��u[e]
                    dist[v[e]] = dist[now]+ w[e];
                    pque.push(make_pair(dist[v[e]], v[e]));
                }
            }
        }
        for(int i=1; i<=n; i++){
            printf("%d ", dist[i]);
        }
    }

    cout<< endl;

    return 0;
}
