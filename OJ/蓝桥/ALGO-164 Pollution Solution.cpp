#include<iostream>
#include<math.h>
#include<cstdio>
#include<algorithm>
#include<string>
#include<queue>
#include<cctype>
#include<cstring>
#include<map>
using namespace std;
const int N=1e2+5;
const int M=N/2;
/*
这种题。。。
我真的写得出来吗？
https://blog.csdn.net/lsylvie/article/details/78962444
https://www.cnblogs.com/ruruozhenhao/p/8419734.html

6 10
-8 2
8 2
8 14
0 14
0 6
-8 14
*/
int n,r;
int X[N],Y[N];

struct P{
    double x,y;
    double getlength(){
        return sqrt(x*x+y*y);
    }
    bool incircle(){
        return x*x+y*y<=r*r;
    }
    double cross(P &b){
        return x*b.y-y*b.x;
    }
};
double getArea(P &a,P &b){
    double degree=a.cross(b)/a.getlength()/b.getlength();
    if(degree<-1)degree=-1;
    if(degree>1)degree=1;
    degree=asin(degree);
    return r*r*degree/2;
}
double cal(P &a,P &b){
    bool in1 = a.incircle();
    bool in2 = b.incircle();
    if(in1&&in2){
        return a.cross(b)/2;
    }else if(in1!=in2){
        P l=a;
        P r=b;
        P mid;
        for(int i=0;i<40;i++){
            mid=P{(l.x+r.x)/2,(l.y+r.y)/2};
            if(mid.incircle()==in1){
                l=mid;
            }else{
                r=mid;
            }
        }
        if(in1){
            return a.cross(mid)/2+getArea(mid,b);
        }else{
            return getArea(a,mid)+mid.cross(b)/2;
        }
    }else{
        P l=a;
        P r=b;
        P mid;
        P midr;
        for(int i=0;i<40;i++){
            mid=P{(l.x+r.x)/2,(l.y+r.y)/2};
            midr=P{(l.x+r.x)/2+(r.x-l.x)*0.0001,(l.y+r.y)/2+(r.y-l.y)*0.0001};
            if(mid.getlength()<midr.getlength()){
                r=mid;
            }else{
                l=mid;
            }
        }
        if(mid.incircle()){
            return cal(a,mid)+cal(mid,b);
        }else{
            return getArea(a,b);
        }
    }
}

int main() {
    freopen("1.txt", "r", stdin);
    cin>>n>>r;
    for(int i=0;i<n;i++){
        cin>>X[i]>>Y[i];
    }
    X[n]=X[0];
    Y[n]=Y[0];
    double ans=0;
    for(int i=0;i<n;i++){
        P a=P{X[i],Y[i]};
        P b=P{X[i+1],Y[i+1]};
        ans+=cal(a,b);

        printf("%f\n", ans);
    }
    printf("%f\n", ans);

    return 0;
}
