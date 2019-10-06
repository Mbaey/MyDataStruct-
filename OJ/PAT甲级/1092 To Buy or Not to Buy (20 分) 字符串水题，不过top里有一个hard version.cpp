#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)

const int INF = 1e8;
const int N=1e5+5, L=1e4+5;
//vector<int> maps[N];
//int maps[N][N]= {0}, target[N][N]= {0};

int mod = 1000000007;
int n,m,t,k;
int a[N]= {0}, vis[N];

int main()
{
//    freopen("1.txt", "r", stdin);
    string strShop, strMy;
//    scanf("%d %d", &n, &m);
    cin >>strShop>> strMy;

//    _for(i, '0', 'z'){
//        char c=i;
//        cout <<c << " ";
//    }
    map<char, int> c2i;
    int ind=0;
    _for(i, '0', '9'+1){
        c2i[i]=ind++;
    }
    _for(i, 'A', 'Z'+1){
        c2i[i]=ind++;
    }
    _for(i, 'a', 'z'+1){
        c2i[i]=ind++;
    }

//    for(auto k: c2i){
//        cout << k.first << " " << k.second<<endl;
//    }

    _for(i,0,strMy.size()){
        ind=c2i[strMy[i]];
        a[ind]++;
    }
    _for(i,0,strShop.size()){
        ind=c2i[strShop[i]];
        a[ind]--;
    }

    int more=0, less=0;
    _for(i,0,62){ //26*2+10
        if(a[i]>0){
            less += a[i];
        }else if(a[i] < 0){
            more -= a[i];
        }
    }
    if(less==0){
        printf("Yes %d\n", more);
    }else
        printf("No %d\n", less);
    return 0;
}

