#include <bits/stdc++.h>
#include <sstream>
using namespace std;
#define _for(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int N=1e4+5,M=10, INF=1e9;

int n,m,k, tmp,len;

int a[N], vis[N];
//int maps[N][N];
//vector<int> maps[N];
struct Fruit{
    int x,y1,y2;
}F[N];

int main()
{
//    freopen("1.txt", "r", stdin);
    cin >> n;
    int minX=INF, maxX=-INF, minId,maxId;
    _for(i,0,n){
        scanf("%d %d %d", &F[i].x, &F[i].y1, &F[i].y2);
        if(minX>F[i].x){
            minX=F[i].x; minId=i;
        }
        if(maxX<F[i].x){
            maxX=F[i].x; maxId=i;
        }
    }


    double maxK=-INF, minK=INF;//����С�� б��
    int x1,y1,x2,y2,xt,ytt, yt, tk1, tk2;

    x1=F[maxId].x, y1=F[maxId].y1;//����
    _for(i,0,n){
        if(i==maxId) continue;
        xt=F[i].x;
        ytt=F[i].y2; yt=F[i].y1; //y1>y2
        tk1=(ytt-y1)*1.0/(xt-x1);  //��
        tk2=(yt-y1)*1.0/(xt-x1); //С

        if(minK > tk1){//�������С��
            minK = tk1;
            x2=xt, y2=ytt;//����
        }

        if(maxK < tk2){//С��������
            maxK=tk2;

        }
    }
    if(maxK <= minK){
        printf("%d %d %d %d\n", x1,y1,x2,y2);//
        return 0;
    }

    maxK=-INF, minK=INF;
    x1=F[minId].x, y1=F[minId].y2;//����
    _for(i,0,n){
        if(i==minId) continue;
        xt=F[i].x;
        ytt=F[i].y2; yt=F[i].y1; //y1>y2
        tk1=(ytt-y1)*1.0/(xt-x1);//С
        tk2=(yt-y1)*1.0/(xt-x1);//��
        if(minK > tk2){
            minK = tk2;
            x2=xt, y2=yt;//����
        }

        if(maxK < tk1){
            maxK=tk1;
//            x2=xt, y2=ytt;
        }
    }
    if(maxK <= minK){
        printf("%d %d %d %d\n", x1,y1,x2,y2);
        return 0;
    }


    maxK=-INF, minK=INF;
    x1=F[minId].x, y1=F[minId].y1;//����
    _for(i,0,n){
        if(i==minId) continue;
        xt=F[i].x;
        ytt=F[i].y2; yt=F[i].y1; //y1>y2
        tk1=(ytt-y1)*1.0/(xt-x1);//С
        tk2=(yt-y1)*1.0/(xt-x1);//��
        if(minK > tk2){
            minK = tk2;
        }

        if(maxK < tk1){
            maxK=tk1;
            x2=xt, y2=ytt;//����??
        }
    }
    if(maxK <= minK){
        printf("%d %d %d %d\n", x1,y1,x2,y2);
        return 0;
    }


    maxK=-INF, minK=INF;
    x1=F[maxId].x, y1=F[maxId].y2;//����
    _for(i,0,n){
        if(i==maxId) continue;
        xt=F[i].x;
        ytt=F[i].y2; yt=F[i].y1; //y1>y2
        tk1=(ytt-y1)*1.0/(xt-x1);//��
        tk2=(yt-y1)*1.0/(xt-x1);//С
        if(minK > tk2){
            minK = tk2;
            x2=xt, y2=yt;//����
        }

        if(maxK < tk1){
            maxK=tk1;
//            x2=xt, y2=ytt;
        }
    }
    if(maxK <= minK){
        printf("%d %d %d %d\n", x1,y1,x2,y2);
        return 0;
    }
    return 0;
}
