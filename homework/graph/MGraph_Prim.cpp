#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define INFINITY_VALUE 65535
#define MAX_NUM 20

typedef char VertexType;
typedef enum {DG, DN, UDG,UDN} GraphKind; //有向图，有相网， 无相图，无相网
struct Edge{
    int i,j;
    int weight;
    Edge()=default;
    Edge(int x, int y, int w):i(x), j(y),weight(w){};

    void display(){
        printf("No.%d->No.%d's weight:%d\t\n", i, j, weight);
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
    MatrixGraph(const int n, const VertexType v[], const int arc[][MAX_NUM], const GraphKind k)
    {
        if(n>=MAX_NUM) exit(0);
        vexNum=n;
        kind=k;
        arcs.resize(n);
        for(int i=0; i<n; i++){   arcs.at(i).resize(n);}
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
                    if(k==UDG|| k==UDN){
                        arcs[i][j] = t;
                        arcs[j][i] = t;
                        ++arcNum;
                        ++arcNum;
                    }else if(k==DG || k==DN){
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
            printf("%c\t", ver[i]);
        }cout << endl;
        for(int i=0; i<vexNum; i++)
        {
            printf("%c\t", ver[i]);
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


    void DFS(){ printf("DFS:\t");
        vis.clear();
        vis.resize(vexNum);
        DFS(0);
        cout << endl;
    }

    void BFS(){ printf("BFS:\t");
        vis.clear();
        vis.resize(vexNum);
        int que[MAX_NUM]={0}, rear=0,front=0;
        int loc=0;
        que[rear++] = loc;
        while(rear > front && front < vexNum){
            loc = que[front++];
            vis[loc]=1;
            printf("%c\t", ver.at(loc));
            for(int i=0; i<vexNum; i++){
                int weight = arcs[loc][i];
                if(!vis[i] && weight != 0){
                    vis[i]=1;
                    que[rear++] = i;
                }
            }
        }cout << endl;
    }



    vector<Edge> Prim(int index){
        vector<Edge> res;
        vector<pair<int, int>> closeEdge;
        for(int i=0; i<vexNum; i++){  int wei =arcs[index][i]!=0 ? arcs[index][i]:INFINITY_VALUE; closeEdge.push_back(make_pair(index, wei)); }
        closeEdge[index].second =  0;

        for(int i=0; i<vexNum-1; i++){
            int min = INFINITY_VALUE, nextVex=-1;
            //debug
//            for(int i=0; i<vexNum; i++){             cout << closeEdge[i].first << " "<< closeEdge[i].second << endl;            }
//            cout << endl;
            for(int j=0; j<vexNum; j++){
                int t= closeEdge[j].second;
                if( t!=0 && t < min){
                    min = t;  nextVex=j;
                }
            }
            Edge t;
            t.i= closeEdge[nextVex].first; t.j=nextVex; t.weight=min;
            res.push_back(t);

            index=nextVex;
            for(int j=0; j<vexNum; j++){
                int t= closeEdge[j].second;
                int t2= arcs[index][j];
                if(t2 != 0 && t2 < t){
                    closeEdge[j].second = t2;
                    closeEdge[j].first = index;
                }
            }
            closeEdge[index].second =  0;
        }
        return res;
    }


private:
    vector<int> vis;
    void DFS(int loc){
        vis[loc]=1; printf("%c\t", ver[loc]);
        for(int i=0; i<vexNum; i++){
            if(!vis[i] && arcs[loc][i]!=0){
                DFS(i);
            }
        }
    }

};


void display(vector<Edge> es, int e){
    for(int i=0; i<e; i++){
        es[i].display();
    }
}

void display(vector<int> a, int e){
    for(int i=0; i<e; i++){
        printf("%d ", a[i]);
    }putchar('\n');
}

int main()
{
    string ver="abcdef";
    int n, e;//node edge num
    freopen("1.txt", "r", stdin);
    cin >> n >> e;
    int arc[MAX_NUM][MAX_NUM]={0};
    for(int i=0; i<e; i++){
        int x, y, w;
        cin >> x >> y >> w;
        arc[x][y]=w;
    }
    MatrixGraph G(ver.length(),ver.c_str() ,arc, UDG);

    G.display();
    G.DFS();
    G.BFS();

    vector<Edge> MinTree = G.Prim(0);
    display(MinTree, n-1);
    return 0;
}
void display(int a[], int e){
    for(int i=0; i<e; i++){
        printf("%d ", a[i]);
    }putchar('\n');
}
