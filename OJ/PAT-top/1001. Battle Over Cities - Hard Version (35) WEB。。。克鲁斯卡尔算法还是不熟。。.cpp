#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
/** \brief
http://blog.csdn.net/guojiaqi007/article/details/56280929
������ȱ��һ�����ʣ�µĵ�������С�������Ĵ��ۡ�
����Խ��ȱ�ĵ�ļ�ֵԽ�����ʣ�µĵ㲻�����
��С���������൱�ڴ������޴�
ʹ��n�� kruskal ��С�������㷨
 *
 */

typedef struct edge
{
    int x, y, c;
    edge(int _x, int _y, int _c)
    {
        x = _x;
        y = _y;
        c = _c;
    }
    bool friend operator < (struct edge a, struct edge b)
    {
        return a.c < b.c;
    }
} Edge;

int f[501];
int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main()
{    freopen("1.txt", "r", stdin);
    int n, m, x, y, c, sta;
    vector<Edge> edges;
    vector<int> ans;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d %d", &x, &y, &c, &sta);
        Edge e(x, y, sta ? 0 : c);
        edges.push_back(e);
    }
    sort(edges.begin(),edges.end());
    bool thereNecessary = false;
    int maxCost = 1;
    for (int i = 1; i <=n; i++)
    {
        int need = n - 2;
        int cost = 0;
        for (int j = 1; j <= n; j++)
        {
            f[j] = j;
        }
        for (int j = 0; need > 0 && j < m; j++)
        {
            if (edges[j].x == i || edges[j].y == i)
                continue;
            int xs = find(edges[j].x);
            int ys = find(edges[j].y);
            if (xs != ys)
            {
                need--;
                f[ys] = xs;
                cost += edges[j].c;
            }
        }
        printf("i,need,cost:%d %d %d\n", i, need,cost);
        if (need > 0)
        {
            if (!thereNecessary)
            {
                thereNecessary = true;
                ans.clear();
            }
            ans.push_back(i);
        }
        else
        {
            if(thereNecessary) {}
            else
            {
                if (cost > maxCost)
                {
                    maxCost = cost;
                    ans.resize(1);
                    ans[0]=i;
                }
                else if (cost == maxCost)
                {
                    ans.push_back(i);
                }
            }
        }
    }

    if (ans.empty())
    {
        puts("0");
    }
    else
    {
        int sAns = ans.size();
        for (int i = 0; i < sAns; i++)
        {
            if (i == 0)
                printf("%d",ans[i]);
            else
                printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
