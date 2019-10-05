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
struct Peo{
    char name[9];
    int age,worth;
}peo[N], tmp[N], tp;
bool cmp(Peo a, Peo b){
    if(a.worth > b.worth){//> worth½µĞò ´óµÄÍùÇ°ÅÅ
        return 1;
    }else if(a.worth < b.worth){
        return 0;
    }

    if(a.age < b.age){//ageÉıĞò
        return 1;
    }else if(a.age > b.age){
        return 0;
    }
    if(strcmp(a.name, b.name)<0) //×ÖÄ¸Ğò ÉıĞò
        return 1;
    else
        return 0;

}
int main()
{
//    freopen("1.txt", "r", stdin);
//    cout << strcmp("aa", "bb")<<endl;
    scanf("%d %d", &n, &m);
    _for(i,0,n){
        scanf("%s %d %d", tp.name, &tp.age, &tp.worth);
        peo[i] = tp;
        a[tp.age]++;
    }

    sort(peo, peo+n, cmp);

//    _for(i,0,n){
//        tp=peo[i];
//        printf("%s %d %d\n", tp.name, tp.age, tp.worth);
//    }
    _for(i,0,m){
        printf("Case #%d:\n", i+1);

        int amin, amax, cnt=0;
        scanf("%d %d %d", &k, &amin, &amax);

        //not Find fun
        bool f=0;
        _for(i,amin, amax+1){
            if(a[i] != 0){
                f=1;
                break;
            }
        }
        if(!f){
            printf("None\n");
            continue;
        }

        _for(i,0,n){
            tp=peo[i];
            if(amin<=tp.age && tp.age<=amax){
                printf("%s %d %d\n", tp.name, tp.age, tp.worth);
                cnt++;
            }
            if(cnt==k)
                break;
        }


    }


    return 0;
}

