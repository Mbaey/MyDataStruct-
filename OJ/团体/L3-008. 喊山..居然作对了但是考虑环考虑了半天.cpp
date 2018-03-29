#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
#define N 10005
int n, m, k, res;
vector<vector<int> > mount(N);
bool vis[N];
int f=0;

/*
需求：输出相邻最远的山。  d最大的山。
如果有环的话，还得改d
由于 题目假设每个山头最多有两个能听到它的临近山头。
所以不会出现环上还有一条
1.有环
2.起点a在链路端点
3.起点a在链路中间
*/
struct M{
    int id, d;
}now;
void dfs(int a,int d,vector<M> &res){
    vis[a] = 1;
    M t;
    t.id=a;
    t.d=d;
    res.push_back(t);
    now = t;
    for(auto i : mount[a]){
        if(!vis[i]){
            dfs(i, d+1, res);
        }
    }
}
bool cmp(M a, M b){
    if(a.d!=b.d)
        return a.d > b.d;//d 降
    else
        return a.id < b.id;//id 升
}
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n >>m >> k;
    int a, b;
    while(m--){
        cin >> a>> b;
        mount[a].push_back(b);
        mount[b].push_back(a);
    }

    while(k--){
        cin >> a;
        if(mount[a].size() == 0){
            cout << 0 << endl;
            continue;
        }
        fill(vis, vis+n+1, 0);
        vector<M> res; f=0; now.id=0, now.d=0;
        dfs(a, 0, res);
        if(now.d != 1 && mount[a].size()==2 && mount[a][1]== now.id){//circle
            cout << res[res.size()/2].id << endl;
        }else{
            sort(res.begin(), res.end(), cmp);
//            for(auto i : res){
//                cout << i.id << " "<<i.d << endl;
//            }
            cout << res[0].id << endl;
        }
    }

    return 0;
}
