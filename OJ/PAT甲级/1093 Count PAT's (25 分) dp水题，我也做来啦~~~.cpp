#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)


//int maps[N][N]= {0}, target[N][N]= {0};

const int INF = 1e8;
const int N=1e5+5, L=1e4+5;
vector<int> maps[N];

int mod = 1000000007;
int n,m,t,k;
int a[3][N]= {0}, vis[N];
//a[0] : 前[i]有多少p
//a[1] : 有多少pa
//a[2] : 有多少pat
int main()
{
    freopen("1.txt", "r", stdin);
    char str[N];
    scanf("%s", str);
    n=strlen(str);
    _for(i,0,n){
        if(i > 0){
            a[0][i] += a[0][i-1];
            a[1][i] += a[1][i-1];
            a[2][i] += a[2][i-1];
        }
        if(str[i]=='P'){
            a[0][i]++;
        }else if(str[i] == 'A'){
            a[1][i] = (a[1][i]+a[0][i])%mod;
        }else{
            a[2][i] = (a[2][i]+a[1][i])%mod;
        }
    }
    cout << a[2][n-1];
    return 0;
}
