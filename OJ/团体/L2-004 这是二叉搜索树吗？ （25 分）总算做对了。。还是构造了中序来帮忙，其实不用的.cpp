#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX=1005;
int p[MAX], ir[MAX], a[MAX];
int cnt=0, N;
bool after(int root,int start, int end){ // root : left p , start:left inner, end:right ineer
    if(start>end) return 0;

    int i=start;//左子树有多少孩子。
    while(ir[i] != p[root] && i < end) i++;
    if(i==end && ir[i] != p[root]) return 0;

    int cntL=i-start;

    after(root+1, start, i-1);
    after(root+cntL+1, i+1, end);
    a[cnt++]=p[root];
    return cnt==N;
}

bool after2(int root,int start, int end){ // root : left p , start:left inner, end:right ineer
    if(start>end) return 0;

    int i=end;//左子树有多少孩子。
    while(ir[i] != p[root]  && i > start) i--;
    if(i==start && ir[i] != p[root]) return 0;

    int cntL=i-start;

    after(root+1, start, i-1);
    after(root+cntL+1, i+1, end);
    a[cnt++]=p[root];
    return cnt==N;
}

bool cmp(int a, int b){
    return a>b;
}
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> N;

    for(int i=0; i<N; i++) {cin >> p[i]; ir[i]=p[i];}
    sort(ir, ir+N);
    if(after(0,0,N-1)){
        cout<<"YES"<<endl;
        for(int i=0; i<N-1; i++){
            printf("%d ",a[i]);
        }
        cout<<a[N-1];

        return 0;
    }else{
        cnt=0;
        sort(ir, ir+N, cmp);
        if(after2(0,0,N-1)){
            cout<<"YES"<<endl;
            for(int i=0; i<N-1; i++){
                printf("%d ",a[i]);
            }
            cout<<a[N-1];


            return 0;
        }
    }

    cout <<"NO";

    return 0;
}
