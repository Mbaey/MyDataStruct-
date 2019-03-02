#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <windows.h>
using namespace std;

const int N=1005;
typedef long long ll;

int n,m,k;
int v,cnt=1;

int P[N]= {0};
int maps[N]={0};
//vector<int> maps[N];

bool OK(int r){

    for(int i=1;i<r; i++){
        if(maps[i] == maps[r] || maps[i]-i == maps[r]-r ||  maps[i]+i == maps[r] +r)
            return false;
    }

    return true;
}
void show(int r){
    for(int i=0;i<=n; i++)
        printf("%d ", i);
    putchar('\n');
    for(int i=1;i<=r; i++){
        printf("%d ", i);
        for(int j=1; j<=n; j++){
            if(maps[i]==j)
                printf("* ");
            else
                printf("o ");
        }
        putchar('\n');
    }
    Sleep(1000/v);
}
void dis(int r){
    system("cls");
    printf("移动步数%d\n", cnt++);
    if(r == n && OK(r)){
        printf("方案为:\n");
        show(r);
        system("pause");
    }
    show(r);
}

void track(int r,int c){
    if(r==1 && c>n){
        puts("无解");
        exit(0);
    }else if(c>n){
        return;
    }
    maps[r]=c;
    dis(r);
    if(OK(r)){
        track(r+1, 1);
    }

    track(r,c+1);



}

int main()
{
//    freopen("1.txt", "r", stdin);
    cout <<"请输入棋盘大小n、速度v"<<endl;
    cin >> n >> v;
    track(1, 1);

    return 0;
}
