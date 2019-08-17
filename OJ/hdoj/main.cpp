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
void get_next(string T,int next[]){
  int j = 0;
  int i = 1;
  mis_match = next[0] = 0;
  while(i < T.size()){

    if(T[i] == T[j]){
      next[i] = j + 1;
      ++j;
      ++i;
    }
    else{// Ê§ÅäÁË£¡

      if(j!=0){
        j = next[j-1];
      }
      else{
        mis_match ++;
        next[i] = 0;
        ++i;
      }
    }
  }
}

int main()
{

//        freopen("1.txt", "r", stdin);

    int t;
    cin >> t;

    getchar();
    string s;
    while(t--){
        int sum=0;
        getline(cin, s);
        get_next(s, a);

        _for(i,1,s.size()){
            //
//            if(log)
//                printf("%d ", a[i]);
            sum += a[i];
        }
        printf("%d\n", sum);
//        printf("\n%d %d %d\n", sum , mis_match, s.size());
        //
//        if(log) puts(s.c_str());
    }
    return 0;
}
