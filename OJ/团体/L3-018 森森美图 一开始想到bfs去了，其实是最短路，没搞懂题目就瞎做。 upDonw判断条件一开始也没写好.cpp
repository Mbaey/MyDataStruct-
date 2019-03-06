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
const int N=105, M=105;  // 尴尬。（5≤N,M≤100） 一开始定义N = 10 了
const float INF = 1e20;
#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)

int n,m,k;

int P[N]= {0};
//vector<int> maps[N];
int maps[N][M]= {0};
int vis[N][M]= {0};
// 这个功能的第一步是将自己的面部选中。
//任意连续像素点的得分之和越低  直接说像素值之和啊。。
int d[N*M];
int dir[8][2] = {{1,0},{0,1},{-1,0},{0,-1}, {1,1}, {-1,1}, {1,-1}, {-1,-1}};
int x1, y11,x2,y2; //y1与 标准库里的 定义冲突了。
int cnt=0;
float minD=INF;
bool in(int x, int y)
{
    return (x<m && x>=0) && (y<n && y>=0);
}

bool upDown(bool f, int x, int y) //true up返回真。
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

//五个测试用例中，一个正确，两个错误，两个超时。 超时我理解，错误？？？dfs应该全部的路都走过了呀。
//3-6 11:28 好吧，upDown()函数写错了，现在俩正确，仨超时了。 接下来1.启发式 2.BFS？
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
        if( !vis[xn][yn] && in(xn,yn) && (upDown(f, xn, yn) || (xn==x2&& yn==y2) )) //少判断了一个条件，upDown()当然不包含s，end两点。 所以一直走不到终点。
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
//用最短路吧，实在记不清访问路径了
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
            if( !vis[xn][yn] && in(xn,yn) && (upDown(f, xn, yn) || (xn==x2&& yn==y2) )) //少判断了一个条件，upDown()当然不包含s，end两点。 所以一直走不到终点。
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
    //dfs ，太耗时了，答案在解答树的中间而已。
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
