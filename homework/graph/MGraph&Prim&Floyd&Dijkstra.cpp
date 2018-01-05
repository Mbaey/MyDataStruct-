#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define INFINITY_VALUE 65535
#define MAX_NUM 20

typedef string VertexType;
typedef enum {DG, DN, UDG,UDN} GraphKind; //有向图，有相网， 无相图，无相网
struct Edge
{
    int i,j;
    int weight;
    VertexType tail, head;
    Edge()=default;
    Edge(int x, int y, int w):i(x), j(y),weight(w) {};
    Edge(int x, int y, int w, VertexType a, VertexType b):i(x), j(y),weight(w), tail(a), head(b) {};
    void display()
    {
        cout << tail << "--" << weight << "-->" << head  << "\t";
//        printf("No.%d -> No.%d's :%d\t\n", i, j, weight);
    }
};


struct MatrixGraph
{
//    int arcs[MAX_NUM][MAX_NUM];
//    VertexType ver[MAX_NUM];
    vector<vector<int> > arcs;
    vector<VertexType> ver;
    int vexNum,arcNum;
    GraphKind kind;

    MatrixGraph()=default;
    MatrixGraph(const int n, const VertexType v[], const int arc[][MAX_NUM], const GraphKind k):vexNum(n),arcNum(0)
    {
        if(n>=MAX_NUM) exit(0);
        vexNum=n;
        kind=k;
        arcs.resize(n);
        for(int i=0; i<n; i++)
        {
            arcs.at(i).resize(n);
        }
        for(int i=0; i<n; i++)
        {
            ver.push_back(v[i]);
        }
        for(int i=0; i<n; i++)
        {
            arcs.at(i).resize(n);
            for(int j=0; j<n; j++)
            {
                int t = arc[i][j];
                if(t != 0)
                {
                    if(k==UDG|| k==UDN)
                    {
                        arcs[i][j] = t;
                        arcs[j][i] = t;
                        ++arcNum;
                        ++arcNum;
                    }
                    else if(k==DG || k==DN)
                    {
                        arcs[i][j] = t;
                        ++arcNum;
                    }
                }
            }
        }
    }

    void display()
    {
        printf(" \t");
        for(int i=0; i<vexNum; i++)
        {
//            printf("%s\t", ver[i]);
            cout << ver[i] << "\t";
        }
        cout << endl;
        for(int i=0; i<vexNum; i++)
        {
            cout << ver[i] << "\t";
            for(int j=0; j<vexNum; j++)
            {
                printf("%d\t", arcs[i][j]);
            }
            cout << endl;
        }
    }

    /*
    int locateVex(VertexType u);
    VertexType getVex(int index);
    int putVex(VertexType u);
    VertexType firstAdjVex(VertexType u);
    VertexType firstAdjVex(VertexType u,VertexType w);
    int insertArc(int i, int j, int weight);
    int deleteArc(int i, int j);
    int deleteVex(VertexType u);
    */


    void DFS()
    {
        printf("DFS:\t");
        vis.clear();
        vis.resize(vexNum);
        DFS(0);
        cout << endl;
    }

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

    vector<Edge> Prim(int index)
    {
        vector<Edge> res;
        vector<pair<int, int>> closeEdge;
        for(int i=0; i<vexNum; i++)
        {
            int wei =arcs[index][i]!=0 ? arcs[index][i]:INFINITY_VALUE;
            closeEdge.push_back(make_pair(index, wei));
        }
        closeEdge[index].second =  0;

        for(int i=0; i<vexNum-1; i++)
        {
            int min = INFINITY_VALUE, nextVex=-1;
            //debug
//            for(int i=0; i<vexNum; i++){             cout << closeEdge[i].first << " "<< closeEdge[i].second << endl;            }
//            cout << endl;
            for(int j=0; j<vexNum; j++)
            {
                int t= closeEdge[j].second;
                if( t!=0 && t < min)
                {
                    min = t;
                    nextVex=j;
                }
            }
            int x = closeEdge[nextVex].first;
            int y = nextVex;
//            Edge(int x, int y, int w, VertexType a, VertexType b):i(x), j(y),weight(w), tail(a), head(b){};
            Edge t(x, y, min, ver[x], ver[y]);
            res.push_back(t);

            index=nextVex;
            for(int j=0; j<vexNum; j++)
            {
                int t1= closeEdge[j].second;
                int t2= arcs[index][j];
                if(t2 != 0 && t2 < t1)
                {
                    closeEdge[j].second = t2;
                    closeEdge[j].first = index;
                }
            }
            closeEdge[index].second =  0;
        }
        show_MinTree(res, vexNum-1);
        return res;
    }

    /*
    1.求一点到其余所有点的最短路
    2.加入最短边 a->b
    3.继续求最短路 i 0~n cost[i] = mix(cost[i], cost[a]+w[a][i])
    */
    vector<int> Dijkstra(int start)
    {   cout << "Dijkstra path:\t";
        vector<vector<int> > w = arcs;
        int fa[vexNum]={0};
        for(int i=0; i<vexNum; i++)
        {
            for(int j=0; j<vexNum; j++)
            {
                if(w[i][j]==0) w[i][j]=INFINITY_VALUE;
            }
        }
//        display();
        vis.clear();
        vis.resize(vexNum);
//        vis[start]=1;
        vector<int> res(vexNum, INFINITY_VALUE);
        for(int i=0; i<vexNum; i++) res[i]=w[start][i];
        res[start]=0;
        for(int j=0; j<vexNum-1; j++)
        {
            int min_cost=INFINITY_VALUE, next=-1;
//            for(int i: res){
//                cout << i << "\t";
//            }cout <<endl;
            for(int i=0; i<vexNum; i++)
            {
                if(!vis[i] && res[i] < min_cost)
                {
                    min_cost=res[i];
                    next=i;
                }
            }
            if(next == -1)//实在没有路了
                break;
            vis[next]=1;

            for(int i=0; i<vexNum; i++)
            {

                if(!vis[i] && w[next][i]!= INFINITY_VALUE)
                {
                    //进过next能到达的点，更新res
                    if(res[i] > res[next] + w[next][i]){
                        res[i] = res[next] + w[next][i];
                        fa[i] = next;
                    }
//                    cout <<res[i]<< "   ***"  <<res[next] + w[next][i]<< endl;
                }
            }
        }
        res[start]=0;
        for(int i : res)
            printf("%d ",i);
        printf("\n");
        vis.clear();
        vis.resize(vexNum);
//        vis[start]=1;
        cout << "ShortestPath is:\t";
//        show_shortestPath(res, start);
        show_shortestPath(res, start, fa);
        cout << endl;
        return res;
    }

    vector<vector<int> > Floyd(){cout << "Floyd Path: \n";
        vector<vector<int> > w = arcs;
        for(int i=0; i<vexNum; i++)
        {
            for(int j=0; j<vexNum; j++)
            {
                if(w[i][j]==0 && i != j) w[i][j]=INFINITY_VALUE;
            }
        }
//        display();
        vis.clear();
        vis.resize(vexNum);
        for(int i=0; i<vexNum; i++)
        {
            for(int j=0; j<vexNum; j++)
            {
                for(int k=0; k<vexNum; k++){
                    if( w[i][j] > w[i][k] + w[k][j]){
                        w[i][j] = w[i][k] + w[k][j];
                    }
                }
            }
        }
        for(auto row : w){
            for(auto i : row){
                cout << i << " ";
            }cout << endl;
        }cout << endl;
        return w;
    }

private:
    vector<int> vis;

    void show_shortestPath(const vector<int> &cost, int index)
    {
        for(int i=0; i<vexNum; i++)
        {
//            cout << cost[i] <<"**"<<arcs[index][i] + cost[index]<<endl;
            if( !vis[i] && cost[i] == arcs[index][i] + cost[index])
            {
                cout << ver[index] <<"--"<< arcs[index][i] <<"-->" << ver[i] << " ";
//                printf("%d ", arcs[index][i], i);
                vis[i]=1;
                index=i;
                show_shortestPath(cost, index);
//                break;
            }
        }
    }
    void show_shortestPath(const vector<int> &cost, int index, int fa[])
    {
        for(int i=0; i<vexNum; i++)
        {
            cout << fa[i] << endl;
        }
    }
    void show_MinTree(vector<Edge> es, int e)
    {cout << "MinTree is:\t";
        for(int i=0; i<e; i++)
        {
            es[i].display();
        }
        cout << endl;
    }

    void DFS(int loc)
    {
        vis[loc]=1;
        cout << ver[loc] << "\t";
        for(int i=0; i<vexNum; i++)
        {
            if(!vis[i] && arcs[loc][i]!=0)
            {
                DFS(i);
            }
        }
    }

};




int main()
{
    VertexType ver[]= {"v0","v1","v2","v3","v4","v5","v6","v7","v8","v9","v10","v11","v12"};
    int n, e;//node edge num
    freopen("1.txt", "r", stdin);
//    freopen("ShortestPath&DG&P189.txt", "r", stdin);
    cin >> n >> e;
    int arc[MAX_NUM][MAX_NUM]= {0};
    for(int i=0; i<e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        arc[x][y]=w;
    }
    MatrixGraph G(n, ver,arc, DG);

    G.display();
//    G.DFS();
//    G.BFS();

//    vector<Edge> MinTree = G.Prim(0);
    G.Dijkstra(0);
//    G.Floyd();
    return 0;
}
