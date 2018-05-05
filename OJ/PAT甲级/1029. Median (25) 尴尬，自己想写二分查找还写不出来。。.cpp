#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int N=1000005;
int n, m;
long int a[N]={0}, b[N]={0};
long int c[2*N]={0};
long int logn(long int al,long int ar,long int bl,long int br){
    int am=(ar-al)/2+al;
    int bm=(br-bl)/2+bl;
    if(al+1==ar &&bl+1==br){
        return min(a[al], b[bl]);
    }

    if(a[am]>b[bm]){
        if((al+ar)%2==1) am++;
        return logn(al, am, bm, br);
    }else if(a[am] <b[bm]){
        if((bl+br)%2==1) bm++;
        return logn(am, ar, bl, bm);
    }else{
        return a[am];
    }
}
int main()
{
    freopen("1.txt", "r", stdin);
    cin >>n;
    for(int i=0; i<n; i++){
        scanf("%ld", a+i);
    }
    cin >>m;
    for(int i=0; i<m; i++){
        scanf("%ld", b+i);
    }

//        c[i]=a[i];
    //bf
    memcpy(c, a, n*sizeof(long int));
    memcpy(c+n, b, m*sizeof(long int));
    sort(c, c+n+m);
    int mid=(n+m-1)/2;
    printf("%d\n", c[mid]);

    //折半,似乎不适用与两者长度不等？

//    int midd = logn(0,n-1,0,m-1);
//    printf("%d", midd);
    return 0;
}
