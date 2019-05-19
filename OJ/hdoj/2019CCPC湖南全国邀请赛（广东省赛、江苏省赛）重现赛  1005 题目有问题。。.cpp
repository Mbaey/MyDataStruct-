#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define _for(i,a,b) for(int i=a; i<b; i++)

const int N=2e5+5;
int n,m, h, cnt=0;
//int a[N], cnt=0, vis[N];
char a[N], vis[N];
int main()
{
//    freopen("1.txt", "r", stdin);
    string str;
    while(cin >> n >> str){

        string to="xtCpc";
        int res=0;
        while((m=str.find(to)) != -1){
            str.erase(m, 5);
            res++;
        }
        cout<< res;
    }
    return 0;
}
