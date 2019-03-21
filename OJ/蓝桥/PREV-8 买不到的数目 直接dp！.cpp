#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
const int INF = 1e8;
#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)
const int N=100000, L=1e4+5;

int n,m,k;

int a[N]= {0};
int b[N]= {0};
//vector<int> a(N);
vector<int> maps[N];
//int maps[N][N]= {0};
int vis[N]= {0};

int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n >> m;


    _for(i, 0, N){
        if(i*n>=N)
            break;
        _for(j, 0, N){
            if(i*n+j*m>=N)
                break;
            vis[i*n+j*m]=1;
        }

    }

    int res;
    _for(i, 0, N){
        if(!vis[i]){
            res = i;
        }
    }
    cout << res;

    return 0;
}
