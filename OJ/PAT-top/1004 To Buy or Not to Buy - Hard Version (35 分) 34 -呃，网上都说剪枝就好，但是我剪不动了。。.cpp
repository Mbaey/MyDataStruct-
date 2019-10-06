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
int a[N]= {0}, vis[N], minMore=0;

string strShops[105], strMy,strShop;
int wight[105];
map<char, int> c2i;  int ind=0;
vector<int> v(100);
void dfs(int id){
    if(minMore==0) return;
    string strShop=strShops[id];
    int more=0, less=0;
    _for(i,0,62){ //26*2+10
        if(v[i]>0){
            less += v[i];
        }else if(v[i] < 0){
            more -= v[i];
        }
    }
    if(less>0) return;
    else minMore = min(minMore, more);

    if(id==n) return;
    vector<int> cv = v;
    _for(i,0,strShop.size()){//don't have strShops i;
        int ind=c2i[strShop[i]];
        v[ind]++;
    }
    dfs(id+1);
    v=cv;

    dfs(id+1);

}

int main()
{
//    freopen("1.txt", "r", stdin);

//    scanf("%d %d", &n, &m);
{
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
}

    cin >> strMy;
    set<int> charSet;
    _for(i,0,strMy.size()){
        ind=c2i[strMy[i]];
        a[ind]++;
        charSet.insert(ind);
    }

    cin >> n;
    _for(i,0,n){
        cin>> strShop;
        strShops[i]=strShop;

        _for(j,0,strShop.size()){
            ind=c2i[strShop[j]];
            a[ind]--;
            if(charSet.count(ind)){
                wight[i]++;
            }
        }
    }

//    sort(strShops, strShops+n, cmp);
    _for(i,0,n){
        int max=-INF, maxId=i;
        _for(j,i,n){
            if(max < wight[j]){
                max=wight[j];
                maxId=j;
            }
        }

        swap(strShops[i], strShops[maxId]);
        swap(wight[i], wight[maxId]);
    }
    int more=0, less=0;
    _for(i,0,62){ //26*2+10
        if(a[i]>0){
            less += a[i];
        }else if(a[i] < 0){
            more -= a[i];
        }
        v[i]=a[i];
    }

    minMore=more;
    if(less==0){
        dfs(0);
        printf("Yes %d\n", minMore);
    }else
        printf("No %d\n", less);
    return 0;
}

