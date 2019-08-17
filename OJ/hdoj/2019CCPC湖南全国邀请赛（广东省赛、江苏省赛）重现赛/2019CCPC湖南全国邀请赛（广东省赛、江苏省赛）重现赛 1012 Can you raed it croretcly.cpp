#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define _for(i,a,b) for(int i=a; i<b; i++)
#define MY_MIN  99999999
#define MY_MAX  -99999999
const int N=1e5+5;
int n,m, h;
//int a[N], cnt=0, vis[N];
int main()
{
//    freopen("1.txt", "r", stdin);
    int n;
    string a,b;
    while(cin >>a>>b){
        bool f=1;
//        cout << a<<" "<<b<<endl;
        if(a.size()==b.size()){
            if(a==b){
                cout <<"Equal"<<endl;
                continue;
            }
            n=a.size();
            int ac[26]={0},bc[26]={0};//
            if(a[0]== b[0] && a[n-1]==b[n-1]){
                _for(i,1,n-1){
                    ac[a[i]-'a']++;
                    bc[b[i]-'a']++;
                }
                _for(i,0,26){
                    if(ac[i] != bc[i])
                        f=0;
                }
            }else{
                f=false;
            }
        }else{
            f=false;
        }
        if(f){
            cout<< "Yes"<<endl;
        }else
            cout<< "No"<<endl;
    }

    return 0;
}
