#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
const int N=205, M=105;  // 尴尬。（5≤N,M≤100） 一开始定义N = 10 了
const int INF = 1e8;
#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)

int n,m,k;

int a[N]= {0};
//vector<int> maps[N];
int maps[N][N]= {0};
//int vis[N][M]= {0};

struct City
{
    string name;
    int enemy;
} c[N];
map<string, int> n2i;
string s,e;
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n >> k >> s >> e;
    c[0].name = s;
    n2i[s]=0;
    int te;
    string ta, tb;
    _for(i,1,n)
    {
        cin >> ta >> te;
        c[i].name=ta, c[i].enemy=te;
        n2i[ta]=i;
    }
    _for(i,0,k)
    {
        cin >> ta >>tb >> te;
        maps[n2i[ta]][n2i[tb]] = te;
        maps[n2i[tb]][n2i[ta]] = te;
    }

    int dist[N]= {0}, fa[N]= {0}, paths[N]= {0}, citys[N]= {0}, enemys[N]= {0}, vis[N]= {0};
    fill_n(dist, n, INF);
    dist[0]=0;
    paths[0]=1;
    fa[0]=-1;

    _for(i, 0, n)
    {
        int x=-1, mind=INF;
        _for(j, 0, n) if(!vis[j] && mind> dist[j])
            mind=dist[x=j];

        if(x==-1)
            break;

        vis[x]=1;

        _for(y, 0, n)
        {
            if(maps[x][y] != 0)
            {
                if(dist[y] > mind + maps[x][y]) //最短
                {
                    dist[y] = mind + maps[x][y];
                    paths[y] = paths[x];// paths[y] += paths[x] 错了一个点！ 如果有另一条最短路，该是赋值，而不是 +=！
                    citys[y] = citys[x] + 1;
                    enemys[y] = enemys[x] + c[y].enemy;

                    fa[y] = x;
                }
                else if(dist[y] == mind + maps[x][y]) //最短路距离 相同
                {
                    paths[y] += paths[x]; // 但是路径多
                    if( citys[x] + 1 > citys[y])  //城市最多
                    {
                        citys[y] = citys[x] + 1;
                        enemys[y] = enemys[x] + c[y].enemy;
                        fa[y] = x;
                    }
                    else if(citys[x] + 1 == citys[y] && enemys[x]+c[y].enemy > enemys[y])   //杀伤最强
                    {
                        enemys[y] = enemys[x] + c[y].enemy;
                        fa[y] = x;

                    }
                }
            }

        }
    }
    int endCity=n2i[e];


    vector<string> st;
    while(endCity != -1)
    {
        st.push_back( c[endCity].name );
        endCity = fa[endCity];
    }
    _ufor(i, st.size(), 1)
    {
        cout << st[i] << "->";
    }
    cout << st[0] << endl;

    endCity=n2i[e];

    cout << paths[endCity] <<" "<< dist[endCity] <<" " << enemys[endCity];

    return 0;
}
