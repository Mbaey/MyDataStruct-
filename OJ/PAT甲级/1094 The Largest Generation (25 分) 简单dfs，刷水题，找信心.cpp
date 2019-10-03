#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)


//int maps[N][N]= {0}, target[N][N]= {0};

const int INF = 1e8;
const int N=1e2+5, L=1e4+5;
vector<int> maps[N];

int mod = 998244353;
int n,m,t,k;
int a[N]= {0}, vis[N];
void dfs(int r, int dth){
    if(!vis[r]){
        vis[r]=1;
        a[dth]++;
    }
    for(int i : maps[r]){
        dfs(i, dth+1);
    }
}
int main()
{
//    freopen("1.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    int root;
    _for(i,0,n)
    {
        scanf("%d %d", &root, &k);
        _for(j,0,k){
            scanf("%d", &t);
            maps[root].push_back(t);
        }
    }
    dfs(1, 1);

    int max=a[1], max_id=1;
    _for(i,1,n+1){
        if(max < a[i]){
            max=a[i];
            max_id=i;
        }
    }
        cout << max<<" "<<max_id << endl;
    return 0;
}
