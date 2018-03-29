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
�������������Զ��ɽ��  d����ɽ��
����л��Ļ������ø�d
���� ��Ŀ����ÿ��ɽͷ��������������������ٽ�ɽͷ��
���Բ�����ֻ��ϻ���һ��
1.�л�
2.���a����·�˵�
3.���a����·�м�
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
        return a.d > b.d;//d ��
    else
        return a.id < b.id;//id ��
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
