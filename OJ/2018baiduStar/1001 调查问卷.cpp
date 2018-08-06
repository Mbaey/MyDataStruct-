#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<cstdio>
#include<stdlib.h>
using namespace std;

const int N=1005;
int t, n, m, kk;
int  res=0;
vector<int> a(N);
set<int> s;
int Cn2(int n){
    if(n < 2) return 0;
    return n*(n-1)/2;
}

void gen_sub(){
    res=0;
    int cir = 1<<m;
    for(int sets=0; sets <cir; sets++){
        s.clear();
        vector<int> repeat(n+1);
        for(int i=1; i<=n; i++){
            int tmp = sets & a[i];
            repeat[i]=tmp;
        }
        sort(repeat.begin()+1, repeat.end());

        int counts=0, pre=1, sizes=0;
        for(int i=1; i<=n; i++){
            if(!s.count(repeat[i])){
                s.insert(repeat[i]);
                counts += Cn2(pre);
                pre=1;
            }else{
                pre++;
            }
        }

        counts += Cn2(pre);
        sizes = s.size();
        if( Cn2(n) -  counts >= kk){
            //debug
//            cout << sets << "**************************"<<endl;
//            for( auto i : repeat){
//                cout << i << endl;
//            }
            res += 1;
        }
    }
}

int main()
{
    freopen("1.txt", "r", stdin);
    scanf("%d", &t);
    for(int k=1; k<=t; k++){
        scanf("%d %d %d", &n, &m, &kk);
        char c;
        for(int i=1; i<=n; i++){
            getchar();// \n
            a[i]=0;
            for(int j=0; j<m; j++){
                scanf("%c", &c);
                a[i] = a[i]*2+ c-'A';
            }
        }
        //test in
        gen_sub();
        printf("Case #%d: %d\n", k, res );
    }
    return 0;
}
/*

*/
