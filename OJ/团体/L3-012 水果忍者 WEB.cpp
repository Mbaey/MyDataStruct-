#include <bits/stdc++.h>
#include <sstream>
using namespace std;
#define _for(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int N=1e4+5,M=10, INF=1e9;

int n,m,k, tmp,len;

int a[N], vis[N];
//int maps[N][N];
//vector<int> maps[N];

struct line
{
    int x, y1, y2;//y1 > y2
} l[10005], id[10005];

struct vec
{
    int x, y;
    vec(int a = 0, int b = 0):x(a), y(b) {};
};

inline int cross(vec a, vec b)  //伪叉积，大于0就返回1，小于返回-1，等于返回0
{
    ll temp = (ll)(a.x)*(ll)(b.y) - (ll)(a.y)*(ll)(b.x);
    if (temp > 0)
        return 1;
    else if (temp == 0)
        return 0;
    return -1;
}
//int n;
vec krmax, krmin, klmax, klmin;

inline bool cmp(const line& a, const line& b)
{
    return a.x < b.x;
}
inline bool cmp2(const line& a, const line& b)
{
    return (a.y1 - a.y2) < (b.y1 - b.y2);
}

int main()
{
    freopen("1.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &l[i].x, &l[i].y1, &l[i].y2);

    sort(l + 1, l + n + 1, cmp);//先根据x坐标从小到大排个序
    for (int i = 1; i <= n; i++)
    {
        id[i].x = i;//这里的x就是记录竖线ID了（即记录是从左到右的第几根竖线）
        id[i].y1 = l[i].y1;
        id[i].y2 = l[i].y2;
    }
    sort(id + 1, id + n + 1, cmp2);//再根据y1-y2从小到大排个序，优先尝试用“短”的竖线下方的端点作“卡子”
    for (int idx = 1; idx <= n; idx++)
    {
        int i = id[idx].x;//尝试以从左到右的第i根竖线下方的端点作“卡子”
        krmax = vec(1, INF);
        krmin = vec(1, -INF);
        klmax = vec(-1, -INF);
        klmin = vec(-1, INF);
        for (int j = i + 1; j <= n; j++)  //向右找允许的最大斜率和最小斜率
        {
            vec v1(l[j].x - l[i].x, l[j].y1 - l[i].y2);
            vec v2(l[j].x - l[i].x, l[j].y2 - l[i].y2);
            if (cross(krmax, v1) < 0)
                krmax = v1;
            if (cross(krmin, v2) > 0)
                krmin = v2;
        }
        for (int j = i - 1; j >= 1; j--)  //向左找允许的最大斜率和最小斜率
        {
            vec v1(l[j].x - l[i].x, l[j].y1 - l[i].y2);
            vec v2(l[j].x - l[i].x, l[j].y2 - l[i].y2);
            if (cross(klmin, v1) > 0)
                klmin = v1;
            if (cross(klmax, v2) < 0)
                klmax = v2;
        }
        //判断以从左到右的第i根竖线下方的端点作“卡子”，是否可行，不可行直接continue
        if (cross(krmax, krmin) > 0)
            continue;
        if (cross(klmax, klmin) > 0)
            continue;
        if (cross(krmax, klmin) < 0)
            continue;
        if (cross(klmax, krmin) < 0)
            continue;
        //可行，分情况讨论
        if (cross(klmax, krmax) * cross(klmax, krmin) <= 0)
            printf("%d %d %d %d", l[i].x + klmax.x, l[i].y2 + klmax.y, l[i].x, l[i].y2);
        else if (cross(klmin, krmax) * cross(klmin, krmin) <= 0)
            printf("%d %d %d %d", l[i].x + klmin.x, l[i].y2 + klmin.y, l[i].x, l[i].y2);
        else if (cross(klmax, krmax) > 0 && cross(klmin, krmin) < 0)
            printf("%d %d %d %d", l[i].x + krmax.x, l[i].y2 + krmax.y, l[i].x, l[i].y2);
        else if (cross(krmax, klmax) > 0 && cross(krmin, klmin) < 0)
            printf("%d %d %d %d", l[i].x + klmin.x, l[i].y2 + klmin.y, l[i].x, l[i].y2);
        break;
    }
    return 0;
}
//优化1：将斜率全部表示为两个int组成的向量，斜率之间比大小用叉积即可，可以提高精度+节省时间。
//优化2：优先枚举“短”的水果（即y1-y2小的水果），直觉嘛，“短”的水果成为“卡子”的几率更大一些。
//（不上优化1，超时，上优化1，200ms过，再上优化2，95ms过）
//
//AC代码：
//---------------------
//作者：foreyes_1001
//来源：CSDN
//原文：https://blog.csdn.net/foreyes_1001/article/details/52208749
//版权声明：本文为博主原创文章，转载请附上博文链接！
