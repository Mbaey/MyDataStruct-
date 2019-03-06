#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
const int N=105, M=105;  // ���Ρ���5��N,M��100�� һ��ʼ����N = 10 ��
const float INF = 1e20;
#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)

int n,m,k;

int P[N]= {0};
//vector<int> maps[N];
int maps[N][M]= {0};
int vis[N][M]= {0};
// ������ܵĵ�һ���ǽ��Լ����沿ѡ�С�
//�����������ص�ĵ÷�֮��Խ��  ֱ��˵����ֵ֮�Ͱ�����
int d[N*M];
int dir[8][2] = {{1,0},{0,1},{-1,0},{0,-1}, {1,1}, {-1,1}, {1,-1}, {-1,-1}};
int x1, y11,x2,y2; //y1�� ��׼����� �����ͻ�ˡ�
int cnt=0;
float minD=INF;
bool in(int x, int y)
{
    return (x<m && x>=0) && (y<n && y>=0);
}

bool upDown(bool f, int x, int y) //true up�����档
{
    if(x==x1&& y==y11)
        return true;
    if(x==x2&& y==y2)
        return true;

    if(f)
        return (y-y11)*(x2-x1)-(x-x1)*(y2-y11) > 0;
    else
        return (y-y11)*(x2-x1)-(x-x1)*(y2-y11) < 0;
}

void dis(float dist)
{
    cnt++;

    cout << cnt <<": "<< endl;
    cout <<"min dist = "<< dist<< endl;
    _for(i,0,m)
    {
        _for(j,0,n)
        cout << vis[j][i]<<" ";
        cout << endl;
    }
}

//������������У�һ����ȷ����������������ʱ�� ��ʱ����⣬���󣿣���dfsӦ��ȫ����·���߹���ѽ��
//3-6 11:28 �ðɣ�upDown()����д���ˣ���������ȷ����ʱ�ˡ� ������1.����ʽ 2.BFS��
void dfs(bool f, int x, int y, float dist)
{
    if((x==x2 && y==y2) || dist > minD)
    {
        minD = min(dist, minD);
        return;
    }

    vis[x][y]=1;
//    dis(dist);
    int xn,yn;
//    typedef pair<int, int> pii;
//    priority_queue<pii, vector<pii>, cmp> pq;

    _for(i, 0, 8)
    {
        xn = x + dir[i][0];
        yn = y + dir[i][1];
        if( !vis[xn][yn] && in(xn,yn) && (upDown(f, xn, yn) || (xn==x2&& yn==y2) )) //���ж���һ��������upDown()��Ȼ������s��end���㡣 ����һֱ�߲����յ㡣
        {
            if(i <= 3)
            {
                dfs(f, xn, yn, dist+ maps[yn][xn]);
            }
            else
                dfs(f, xn, yn, dist+ maps[yn][xn]*sqrt(2) + maps[y][x]*(sqrt(2)-1) );
            vis[xn][yn]=0;
        }
    }
}
//struct node
//{
//    int x,y;
//    float dist;
//};
//�����·�ɣ�ʵ�ڼǲ������·����
//float bfs(bool f, int x, int y)
float shortPath(bool f, int x, int y)
{
    float minD = INF;
    float Dist[N][M];
    _for(i,0,n)
    {
        _for(j,0,m)
        {
            Dist[i][j] = INF;
        }
    }
    Dist[y][x]=maps[y][x];
    vis[x2][y2]=0;
    vis[x1][y11]=0;

//    queue<node> q;
//    node t;
//    t.x=x, t.y=y, t.dist=maps[y][x];
//    q.push(t);
    while(1)
    {
        int xn,yn;
        float dist=INF;
        _for(i,0,n)
            _for(j,0,m)
                if(!vis[j][i] && upDown(f, j, i) &&  Dist[i][j] < dist)
                    dist=Dist[y=i][x=j];


        vis[x][y]=1;
        if((x==x2 && y==y2) || dist > minD)
        {
            minD = min(dist, minD);
            return minD;
        }

        _for(i, 0, 8)
        {
            xn = x + dir[i][0];
            yn = y + dir[i][1];
            if( !vis[xn][yn] && in(xn,yn) && (upDown(f, xn, yn) || (xn==x2&& yn==y2) )) //���ж���һ��������upDown()��Ȼ������s��end���㡣 ����һֱ�߲����յ㡣
            {
                if(i <= 3)
                {
                    Dist[yn][xn] = min(Dist[yn][xn] , dist+ maps[yn][xn]);
                }
                else
                {
                    float tmp =  dist+ maps[yn][xn]*sqrt(2) + maps[y][x]*(sqrt(2)-1);
                    Dist[yn][xn] = min( Dist[yn][xn] , tmp);
                }

            }

        }
//        dis(dist);
    }
    return minD;
}
int main()
{
    freopen("1.txt", "r", stdin);
    int t;
    cin >> n>> m;

    _for(i,0,n)
    {
        _for(j,0,m)
        {
            cin >> t;
            maps[i][j] = t;
        }
    }
    cin >> x1 >> y11 >>x2>>y2;

    float res=0;
    //dfs ��̫��ʱ�ˣ����ڽ�������м���ѡ�
//    dfs(true, x1, y11, maps[y11][x1]);
//    res += minD;
//
//    vis[y11][x1]=0;
//    minD=INF;
//    dfs(false, x1, y11, maps[y11][x1]);
//    res += minD;
    res += shortPath(true, x1, y11);
    res += shortPath(false, x1, y11);

    res = res - (maps[y11][x1] + maps[y2][x2]);

    printf("%.2f", res);
    return 0;
}
