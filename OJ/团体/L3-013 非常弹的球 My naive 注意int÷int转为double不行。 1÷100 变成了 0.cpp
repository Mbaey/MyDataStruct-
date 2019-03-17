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
const int N=10005, M=105;
const int INF = 1e8;
#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)

int n,m,k;

int a[N]= {0};
vector<int> maps[N];
//int maps[N][N]= {0};
int vis[N]= {0};

int main()
{

    //freopen("1.txt", "r", stdin);
    const double g=9.8, E=1000, sqrt2 = sqrt(2);
    double p, M, v, t, s, sum=0, last, e=E;
    cin >> m >> p;
    int cnt=0;
    M=m/100.0;
    p/=100.0;

   while(1){
        last = sum;

        v = sqrt(E*pow(1-p, cnt++)*2/M);
//        printf("%.3f\n", v);
        t = sqrt2*v / g;
        s = v * t / sqrt2;
        sum+= s;
        if(s < 1e-9){
            break;
        }
    }

    printf("%.3f", sum);

//    cout << endl << cnt << endl;

    return 0;
}
