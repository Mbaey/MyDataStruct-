#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include <iostream>
#include <algorithm>
using namespace std;
//99 999 9999
#define N 1287
#define M 129
#define L 61
int arr[N][M][L]= {0}, n, m, l, T, res=0, cnt=0;
bool vis[N][M][L]= {0};
int dir[6][3]= {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
set<int> s;
queue<int> q, q2;
/*
void BFS()
    {
        printf("BFS:\t");
        vis.clear();
        vis.resize(vexNum);
        int que[MAX_NUM]= {0}, rear=0,front=0;
        int loc=0;
        que[rear++] = loc;
        while(rear > front && front < vexNum)
        {
            loc = que[front++];
            vis[loc]=1;
            cout << ver[loc] << "\t";
            for(int i=0; i<vexNum; i++)
            {
                int weight = arcs[loc][i];
                if(!vis[i] && weight != 0)
                {
                    vis[i]=1;
                    que[rear++] = i;
                }
            }
        }
        cout << endl;
    }
*/
void bfs_space2time(int a, int b, int c, int cnt)
{

    int hash = a+ b*1e4+ c*1e7;
    q2.push(hash);
    s.insert(hash);
    while(!q2.empty())
    {
        hash = q2.front();
        a = hash % 10000;
        hash /= 10000;
        b = hash % 1000;
        hash /= 1000;
        c = hash;
//        printf("a:%d b:%d c:%d\n", a, b, c);
        cnt++;
        q2.pop();

        for(int i=0; i<6; i++)
        {
            int ta = a+dir[i][0];
            int tb = b+dir[i][1];
            int tc = c+dir[i][2];
            hash = ta+ tb*1e4+tc*1e7;
            if(!s.count(hash))
            {
                if(arr[ta][tb][tc] == 1)
                {
                    q2.push(hash);
                    s.insert(hash);

                }
                else  // -1 || 0 ignore
                {

                }
            }
        }
    }
    if(cnt >= T)
    {
        res+=cnt;
    }

}
void bfs(int a, int b, int c, int cnt)
{

    int hash = a+ b*1e4+ c*1e7;
    q2.push(hash);
    vis[a][b][c] = true;
    while(!q2.empty())
    {
        hash = q2.front();
        a = hash % 10000;
        hash /= 10000;
        b = hash % 1000;
        hash /= 1000;
        c = hash;
//        printf("a:%d b:%d c:%d\n", a, b, c);
        cnt++;
        q2.pop();

        for(int i=0; i<6; i++)
        {
            int ta = a+dir[i][0];
            int tb = b+dir[i][1];
            int tc = c+dir[i][2];
            hash = ta+ tb*1e4+tc*1e7;
            if(!vis[ta][tb][tc])
            {
                if(arr[ta][tb][tc] == 1)
                {
                    vis[ta][tb][tc]=1;
                    q2.push(hash);
                }
                else  // -1 || 0 ignore
                {

                }
            }
        }
    }
    if(cnt >= T)
    {
        res+=cnt;
    }

}
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n >> m >> l >> T;
    for(int i=0; i<=n+1; i++)
        for(int j=0; j<=m+1; j++)
            for(int k=0; k<=l+1; k++)
                arr[i][j][k]=-1;


    for(int k=1; k<=l; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin >> arr[i][j][k];
            }
        }
    }

    /*test in
    for(int k=1; k<=l; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                printf("%d ", arr[i][j][k]);
            }
            cout << endl;
        }
        cout << endl;
    }*/
    for(int k=1; k<=l; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++){
                int hash = i+ j*1e4+k*1e7;
                //用时间换空间的话 超时啦。干脆暴力点。
                /*if(!s.count(hash) && arr[i][j][k]==1){
                    bfs_space2time(i, j ,k, 0);
                }*/
                if(!vis[i][j][k] && arr[i][j][k]==1){
                    bfs(i, j ,k, 0);
                }
            }

/*
    bfs里套bfs。。你也是厉害。。
    还有bug。如果arr[1][1][1] 被肿瘤包围的话，扫描就直接退出啦。
    int a=1, b=1, c=1;
    int hash = a+ b*1e4+ c*1e7;
    q.push(hash);
    while(!q.empty())
    {
        hash = q.front();
        a = hash % 10000;
        hash /= 10000;
        b = hash % 1000;
        hash /= 1000;
        c = hash;


        q.pop();
        for(int i=0; i<6; i++)
        {
            int ta = a+dir[i][0];
            int tb = b+dir[i][1];
            int tc = c+dir[i][2];
            hash = ta+ tb*1e4+tc*1e7;
            if(!s.count(hash) && arr[ta][tb][tc] != -1)
            {
                if(arr[ta][tb][tc] == 0)
                {
                    q.push(hash);
                    s.insert(hash);
                }
                else if(arr[ta][tb][tc] == 1)
                {
                    bfs(ta,tb, tc, 0);
                }
            }
        }
    }
*/
    cout << res;
    return 0;
}
/*

3 4 3 2
1 1 1 1
1 1 1 1
1 1 1 1
1 0 0 0
0 0 0 0
0 0 0 1
0 0 0 0
0 1 0 0
1 1 0 1
*/
