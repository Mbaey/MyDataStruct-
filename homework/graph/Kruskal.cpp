#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
struct Edge{
    int i,j;
    int weight;
    void display(){
        printf("%d\t%d\t%d\t\n", i, j, weight);
    }
};
bool cmp(Edge &a, Edge &b){
    return a.weight < b.weight;
}

int USset[10];
int findInSet(int i){
    return USset[i] = USset[i] == i? i : findInSet(USset[i]);
}
vector<Edge> Kruskal(vector<Edge> es, int n){
    sort(es.begin(), es.end(), cmp);
    vector<Edge> res;
    /*set<int> vertexs;//wrong 是不同的集合
    int e = es.size();
    for(int i=0; i<n-1 && i<e; i++){
        if(!(vertexs.count(es[i].i)==1 && vertexs.count(es[i].j) ==1)){
            res.push_back(es[i]);
            vertexs.insert(es[i].i);
            vertexs.insert(es[i].j);
        }
    }*/
    for(int i=0; i<n; i++){ USset[i]=i; }
    int e = es.size();
    for(int i=0; i<e; i++){
//        es[i].display();
        int x = findInSet(es[i].i);
        int y = findInSet(es[i].j);
        if(x!=y){
            res.push_back(es[i]);
            USset[x] = y;
        }
        if(res.size()==n-1) break;
//        for(int i=0; i<n; i++){ printf("%d ", USset[i]); }puts("");
    }

    return res;
}
void display(vector<Edge> es, int e){

    for(int i=0; i<e; i++){
        es[i].display();
    }
}
int main()
{

    vector<Edge> es, MinTree;
    int n, e;//node edge num
    freopen("1.txt", "r", stdin);
    cin >> n >> e;
    for(int i=0; i<e; i++){
        Edge t;
        cin >> t.i >> t.j >> t.weight;
        es.push_back(t);
    }

    MinTree = Kruskal(es, n);
    display(MinTree, n-1);
    return 0;
}
