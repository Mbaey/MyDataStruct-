#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define INFINITY_VALUE 65535
#define MAX_NUM 20

typedef char VertexType;

struct Edge
{
    int i,j;
    int weight;
    Edge()=default;
    Edge(int x, int y, int w):i(x), j(y),weight(w) {};
    Edge(int x, int y):i(x), j(y) {};
};

struct ArcNode
{
    int next;
    int weight;
    ArcNode()=default;
    ArcNode(int y, int w):next(y), weight(w) {};
    ArcNode(int y):next(y) {};
};

struct VNode
{
    int data;
    vector<ArcNode> arcs;
    VNode()=default;
    VNode(int v):data(v) {};
};

struct ALGraph
{
    vector<VNode> vexs;
    int vexNum, arcNum;
    ALGraph()=default;
    ALGraph(int n, int e, vector<Edge> es):vexNum(n),arcNum(e)
    {
        vexs.resize(vexNum);
        for(int i=0; i<n; i++)
        {
            VNode v(i);
            vexs[i] = v;
        }
        for(int i=0; i<e; i++)
        {
            int x=es[i].i, y=es[i].j, w= es[i].weight;
            ArcNode arc(y, w);
            vexs[x].arcs.push_back(arc);
        }
    };

    void display()
    {
        for(int i=0; i<vexNum; i++)
        {
            int e= vexs[i].arcs.size();
            printf("%d\t", vexs[i].data);
            for(int j=0; j<e; j++)
            {
                printf("-%d->%d\t", vexs[i].arcs[j].weight, vexs[i].arcs[j].next);
            }
            putchar('\n');
        }
    }
    /**
    1.��ʼ���
    2.�ҳ����Ϊ0�Ķ��� ��ջ
    3.ɾ���������ĳ��ߣ���ȥ��ı��ϵ����
    �ظ�2,3
    */
    int topologicalOrder(stack<int> res)
    {
        cout << "TopologicalOrder:\t";
        inDegree.clear();
        inDegree.resize(vexNum);
        init_InDegree();

        int count=0;
        stack<int> vexSta;
        ve.clear(), ve.resize(vexNum);
        for(int i=0; i<vexNum; i++)
        {
            if(!inDegree[i]) vexSta.push(i);
        }
        while(!vexSta.empty())
        {
            int y= vexSta.top();
            vexSta.pop();
            res.push(y);
            printf("%d\t", y);
            count++;
            int e= vexs[y].arcs.size();
            for(int j=0; j<e; j++)
            {
                int next = vexs[y].arcs[j].next;
                if(--inDegree[next]==0) vexSta.push(next);
                if(ve[y] +  vexs[y].arcs[j].weight> ve[next]) ve[next]=ve[y] +  vexs[y].arcs[j].weight;
            }
        }
        printf("\n");

//        for(int i : ve){
//            printf("%d\t", i);
//        }
        if(count< vexNum)//�л�
            return -1;
        else
            return 1;
    }

    int criticalPath()
    {
        stack<int> T;
        if(topologicalOrder(T)==-1) return -1;

    }
private:
    vector<int> inDegree, ve, vl, e, l;
    void init_InDegree()
    {
        for(int i=0; i<vexNum; i++)
        {
            int e= vexs[i].arcs.size();
            for(int j=0; j<e; j++)
            {
                ++inDegree[vexs[i].arcs[j].next] ;
            }
        }
//        for(int i : inDegree){
//            printf("%d\t", i);
//        }
    }
};
int main()
{
    string ver="abcdef";
    int n, e;//node edge num
    freopen("CriticalPath.txt", "r", stdin);
    cin >> n >> e;
    vector<Edge> es;
    for(int i=0; i<e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        Edge t(x,y,w);
        es.push_back(t);
    }
    ALGraph G(n, e, es);

    G.display();
    G.criticalPath();



//    display(MinTree, n-1);

    return 0;
}
void display(int a[], int e)
{
    for(int i=0; i<e; i++)
    {
        printf("%d ", a[i]);
    }
    putchar('\n');
}
