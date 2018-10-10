#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N=300;//ms
int c[N][N]={0};
int n,m;
int x, y, minLen=INT_MAX, minId;


void check(int index){
    cin >> y;
    set<int> s;
    vector<int> a(y);
    for(int i=0; i<y; i++){
        scanf("%d", &a[i]);
        s.insert(a[i]);
    }
    int now=0, pre=0, cnt=0, sum=0;
    for(int i=0; i<y-1; i++){
        if(c[a[i]][a[i+1]] == 0){
            printf("Path %d: NA (Not a TS cycle)\n",index);
            return;
        }
        sum+=c[a[i]][a[i+1]];
    }
//    cout << s.size()<<endl;
    if(a[0] == a[y-1] && s.size() == n) {
        if (sum < minLen) {
            minLen = sum;
            minId = index;
        }

        if(y == n+1){
            printf("Path %d: %d (TS simple cycle)\n", index, sum);
        }else{
            printf("Path %d: %d (TS cycle)\n", index, sum);
        }
    } else {
        printf("Path %d: %d (Not a TS cycle)\n", index, sum);

    }

//    string res;
//    if(s.size()==n && b==now ){
//        if(n==y-1)
//            res="TS simple cycle";
//        else
//            res="TS cycle";
//        if(minLen>len){
//            minLen=len;
//            minId=i;
//        }
//    }else{
//        res="Not a TS cycle";
//    }
//
//    printf("Path %d: %d (%s)\n",i, len,res.c_str());

}

int main(){
	freopen("1.txt", "r" ,stdin);
    cin >>n>>m;
    int u, vi, w;

    for(int i=0;i<m; i++){
        scanf("%d %d %d", &u, &vi, &w);
        c[u][vi]=c[vi][u]=w;
    }
//    int v[N]={0};


    cin>>x;
    for(int i=1;i<=x; i++){
        check(i);
    }

    printf("Shortest Dist(%d) = %d\n", minId, minLen);


    return 0;
}
