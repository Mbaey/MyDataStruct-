#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)

const int INF = 1e8;
const int N=100, L=1e4+5;

int n,m,k;

int a[N]= {0};
//vector<int> a(N);
vector<int> maps[N];
//int maps[N][N]= {0};
int vis[N][N]= {0};
//感知机不能分类 异或问题。 >0 正 <=0 负
int main()
{
//    freopen("1.txt", "r", stdin);
    int t;
    cin >> t;
    int table[2][2]={0};
    int a[3][N]={0};
    float a,b,c, mean;
    while(t--){
        cin >> n;
        int a,b, c;
        int fa=0,fb=0,fc=0;
        bool flag=0;
        _for(i,0,n){
            cin >> a>> b>> c;
            if(a>0) fa=1;
            else fa=0;

            if(b>0) fb=1;
            else fb=0;
            if(c>0) fc=1;
            else fc=0;
            if(!vis[fa][fb]){
                vis[fa][fb]=1;
                table[fa][fb]=fc;
            }else{
                if(table[fa][fb] != fc){
                    flag=1;
                    break;
                }
            }
//            cout << a<<" "<<b<<" "<<f<<endl;
        }
        int sum=0;
        _for(i,0,2){
            _for(j,0,2)
                sum+= vis[i][j];
        }
        if(sum==4){
            sum=0;
            _for(i,0,2){
                _for(j,0,2){
                    sum += table[i][j];
                }
            }
            if(sum==2 && table[1][0] == table[0][1])
                flag=1;
        }
        if(flag ){
            cout << "Infinite loop!\n";
        }else
            cout << "Successful!\n";
    }


    return 0;
}
