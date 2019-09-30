#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e8;
const int N=1e5+5, L=1e4+5;

#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)


//vector<int> a(N);
//vector<int> maps[N];
//int maps[N][N]= {0}, target[N][N]= {0};
//int vis[N][N]= {0};
//int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int mod = 998244353;
int n,m,t,k;
int a[N]= {0}, vis[N];

struct Peo
{
    string name;
    int y,m,d;
} peo[N];
int main()
{
//    freopen("1.txt", "r", stdin);
    scanf("%d", &n);

    Peo tmp;
    int cnt=0;
    int dateNow = 2014*10000 + 9*100+6;
    int max=-INF, min=INF;
    string maxN, minN;
//    cout << dateNow;
    _for(i,0,n)
    {
        cin >> tmp.name;
        scanf("%d/%d/%d", &tmp.y, &tmp.m, &tmp.d );
        int dateA = tmp.y*10000 + tmp.m*100+tmp.d;

        if(dateA > dateNow || dateA < dateNow-200*10000)
            continue;

//        cout << tmp.name << " "
//            << dateA<< endl;
        if(dateA > max)
        {
            max=dateA;
            maxN=tmp.name;
        }
        if(dateA < min)
        {
            min=dateA;
            minN = tmp.name;
        }
        cnt++;
    }
    if(cnt != 0)
    cout
            << cnt << " "
            << minN << " "
            << maxN << endl;

    else
        cout << 0 << endl;
    return 0;
}
