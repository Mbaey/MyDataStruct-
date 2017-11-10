#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

#define INFINITY 65536
#define MAX_NUM 20
typedef char VertexType;
typedef enum {DG, DN,UDG,UDN} GraphKind; //有向图，有相网， 无相图，无相网

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
                    arcs[i][j] = t;
                    ++arcNum;
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
            printf("%c\t", ver[loc]);
            for(int i=0; i<vexNum; i++){
                int weight = arcs[loc][i];
                if(!vis[i] && weight != 0){
                    que[rear++] = i;
                }
            }
        }
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
int main()
{
    string ver="abcde";
//    const char v[5] = ver.c_str();
    int arc[][MAX_NUM]= { {0,1,0,1,0},{1,0,1,0,1},{0,1,0,1,1},{1,0,1,0,0},{0,1,1,0,0}, };
    MatrixGraph G(5,ver.c_str() ,arc, UDG);

    G.display();
    G.DFS();
    G.BFS();

    return 0;
}