#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e8;
const int N=1e6+5, L=1e4+5;

#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)


int n,m,k;

int a[N]= {0};
//vector<int> a(N);
//vector<int> maps[N];
//int maps[N][N]= {0}, target[N][N]= {0};
//int vis[N][N]= {0};
//int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int mod = 998244353;
//permutation 2 µÝÍÆ¡£dp¡£ÄÔ¿ÇÍ´¡£
int mis_match=0;

int gcd(int a, int b){
    return b==0? a : gcd(b, a%b);
}
int main()
{

//    freopen("1.txt", "r", stdin);
    int t;
    cin >> t;

    while(t--){
        scanf("%d", &n);
        int f,g, fi, gi, tmp;
        f=g=fi=gi=tmp=0;
        _for(i,0,n){
            scanf("%d", &tmp);
            if(tmp != 0){
                fi=i;
                f=tmp;
            }
        }

        _for(i,0,n){
            scanf("%d", &tmp);
            if(tmp != 0){
                gi=i;
                g=tmp;
            }
        }
        if(fi == gi){
            int gcdi = gcd(f,g);
            printf("%d/%d\n", f/gcdi, g/gcdi);
        }
        else if(fi>gi){
            printf("1/0\n");
        }else{
            printf("0/1\n");
        }

    }
    return 0;
}
