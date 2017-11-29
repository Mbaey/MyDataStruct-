#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

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
    vector<VNode> OutVexs;
    vector<VNode> InVexs;
    int vexNum, arcNum;
    ALGraph()=default;
    ALGraph(int n, int e, vector<Edge> es):vexNum(n),arcNum(e)
    {
        OutVexs.resize(vexNum);
        InVexs.resize(vexNum);
        for(int i=0; i<n; i++)
        {
            VNode v(i);
            OutVexs[i] = v;
            InVexs[i] = v;
        }
        for(int i=0; i<e; i++)
        {
            //x --> y
            int x=es[i].i, y=es[i].j, w= es[i].weight;
            ArcNode arc(y, w);
            ArcNode arc2(x, w);
            OutVexs[x].arcs.push_back(arc);
            InVexs[y].arcs.push_back(arc2);
        }
    };

    void display()
    {
        for(int i=0; i<vexNum; i++)
        {
            int e= OutVexs[i].arcs.size();
            printf("%d\t", OutVexs[i].data);
            for(int j=0; j<e; j++)
            {
                printf("-%d->%d\t", OutVexs[i].arcs[j].weight, OutVexs[i].arcs[j].next);
            }
            putchar('\n');
        }
    }
    /**
    1.初始入度
    2.找出入度为0的顶点 入栈
    3.删除它和它的出边，减去别的边上的入度
    重复2,3
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
            int e= OutVexs[y].arcs.size();
            for(int j=0; j<e; j++)
            {
                int next = OutVexs[y].arcs[j].next;
                if(--inDegree[next]==0) vexSta.push(next);
                if(ve[y] +  OutVexs[y].arcs[j].weight> ve[next]) ve[next]=ve[y] +  OutVexs[y].arcs[j].weight;
            }
        }
        printf("\n");

        for(int i : ve)
        {
            printf("%d\t", i);
        }
        if(count< vexNum)//有环
            return -1;
        else
            return 1;
    }
    int DFS_topologicalOrder()
    {
        cout << "DFS TopologicalOrder:\t";
        inDegree.clear();
        inDegree.resize(vexNum);
        init_InDegree();
        count=0;

        vis.clear(), vis.resize(vexNum);
        ve.clear(), ve.resize(vexNum);
        vl.clear(), vl.resize(vexNum);
        for(int i=0; i<vexNum; i++)
        {
            if(!inDegree[i] && !vis[i]) DFS_topologicalOrder(i);
        }
        cout << endl;
        printf("ve: ");
        for(int i : ve)
        {
            printf("%d\t", i);
        }
        cout << endl;
        printf("vl: ");
        for(int i : vl)
        {
            printf("%d\t", i);
        }
        cout << endl;

        if(count< vexNum)//有环
            return -1;
        else
            return 1;
    }

    int criticalPath()
    {

        if(DFS_topologicalOrder()==-1) return -1;
        e.clear(), e.resize(arcNum);
        l.clear(), l.resize(arcNum);
        for(int i=0; i<vexNum; i++)
        {
            int e= OutVexs[i].arcs.size();
            for(int j=0; j<e; j++)
            {
                int next = OutVexs[i].arcs[j].next, weight=OutVexs[i].arcs[j].weight;
                int ee, el;
                ee=ve[i]; el=vl[next]-weight;
//                char tag = (ee==el)?'*':'';
                if(ee==el)
                 printf("%d-%d->%d\n", i, next, weight);
            }
        }

        cout << endl;
        return 0;
    }
private:
    vector<int> inDegree, ve, vl, e, l, vis;
    int count;
    void DFS_topologicalOrder(int y)
    {
        vis[y]=1;
        printf("%d\t", y);
        count++;
        int e= OutVexs[y].arcs.size();
        for(int j=0; j<e; j++)
        {
            int next = OutVexs[y].arcs[j].next;
            --inDegree[next];
            if(ve[y] +  OutVexs[y].arcs[j].weight> ve[next]) ve[next]=ve[y] +  OutVexs[y].arcs[j].weight;
            if(count==vexNum-1)
                for(int j=0; j<vexNum; j++)
                {
                    vl[j] = ve[vexNum-1];
//                    cout << ve[vexNum-1] << "********"<< y<< endl;
                }

        }
        for(int i=0; i<vexNum; i++)
        {
            //y --> i
            if(!inDegree[i] && !vis[i])
            {
                DFS_topologicalOrder(i);
//                InVexs[y].arcs[j].weight
                int e= InVexs[i].arcs.size();
                for(int j=0; j<e; j++)
                {
                    int pre = InVexs[i].arcs[j].next;
                    int t = vl[i] -  InVexs[i].arcs[j].weight;
//                    printf("vl[pre]:%d,  vl[i]:%d,   InVexs[i].arcs[j].weight:%d\n", vl[pre], vl[i] ,InVexs[i].arcs[j].weight);
                    if(t < vl[pre])
                        vl[pre] = t;
                }

            }
        }
    }

    void init_InDegree()
    {
        for(int i=0; i<vexNum; i++)
        {
            int e= OutVexs[i].arcs.size();
            for(int j=0; j<e; j++)
            {
                ++inDegree[OutVexs[i].arcs[j].next] ;
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
//    G.DFS_topologicalOrder();


//    display(MinTree, n-1);

    return 0;
}
