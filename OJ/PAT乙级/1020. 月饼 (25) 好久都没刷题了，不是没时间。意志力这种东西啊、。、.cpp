#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const int N=1005;
int n;
float m;

struct obj{
    float w,v,r;//重量价格密度
}a[N];
bool cmp(obj a, obj b){
    return a.r > b.r;
}
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n>>m;
    for(int i=0; i<n; i++){
        cin >> a[i].w;
    }
    for(int i=0; i<n; i++){
        cin >> a[i].v;
        a[i].r = a[i].v/(float)a[i].w;
    }
    sort(a, a+n, cmp);

//    for(int i=0; i<n; i++){
//        printf("%d: %d/%d %f\n", i, a[i].w ,a[i].v ,a[i].r );
//    }
    float res=0;
    for(int i=0; i<n; i++){
        if(m < a[i].w){
            res += a[i].r*m;
            break;
        }
        res += a[i].v;
        m -= a[i].w;
    }
    printf("%.2f", res);

    return 0;
}
