#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include <iostream>
#include <algorithm>
using namespace std;
//99 999 9999
#define N 1050
#define inf 1<<20
int n, m, k, dis, map[N][N]= {0};

struct Res{
    int id, sht;
    float avg;
};
//floyd
void display(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool cmp(Res a, Res b ){
    if(a.sht != b.sht){
        return a.sht > b.sht;
    }else if(a.avg != b.avg){
        return a.avg < b.avg;
    }else{
        return a.id < b.id;
    }
}
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n>>m>>k>>dis;
    string as, bs;
    //init floyd
    fill(map[0], map[0]+N*N, inf);
    for(int i=1; i<=n+m; i++)
        map[i][i]=0;

    int a, b, d;
    while(k--)
    {
        cin >>as>>bs >> d;
        if(as[0]=='G')
        {
            a= as[1]-'0';
        }
        else   // 1 + 3
        {
            a = as[0] - '0' + m;
        }
        if(bs[0]=='G')
        {
            b= bs[1]-'0';
        }
        else   // 1 + 3
        {
            b = bs[0] - '0' + m;
        }
        map[a][b] = d;
        map[b][a] = d;
    }
//    display(n+m);
//    cout << endl;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=m+n; j++)
            for(int k=1; k<=m+n; k++)
            {
                if(map[i][j] > map[i][k] + map[k][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
//    display(n+m);
//    vector<Res> res;
    Res t, res;
    res.id = 0;
    res.sht = -inf;
    res.avg = 0;
    bool f=false;
    for(int i=1; i<=m; i++){
        f=false;
        t.id = i;
        t.sht = inf;
        t.avg = 0;
        for(int j=m+1; j<=n+m; j++){
            if(t.sht> map[i][j]){
                t.sht = map[i][j];
            }
            if(map[i][j] > dis){
                f=true;
            }
            t.avg += map[i][j];
        }
        t.avg /= n;
        if(!f){
            if(t.sht > res.sht){
                res = t;
            }else if(t.sht == res.sht&&t.avg < res.avg){
                res = t;
            }
        }
    }
    if(res.id==0){
        cout << "No Solution";
    }else
        printf("G%d\n%.1f %.1f\n",res.id,  (float)res.sht, floor(res.avg*10+0.5)/10.0);
//    for(int i=0; i< res.size(); i++){
//        printf("%d: %.1f %.1f\n",res[i].id,  (float)res[i].sht, res[i].avg);
//    }

//    sort(res.begin(), res.end(), cmp);
//    for(int i=0; i< res.size(); i++){
//        printf("%d: %.1f %.1f\n",res[i].id,  (float)res[i].sht, res[i].avg);
//    }

//    if(res.size()==0){
//        cout << "No Solution";
//    }else{
//        res[0].avg = floor(res[0].avg*10+0.5) /10.0;
//        cout << 'G' << res[0].id << endl;
//        printf("%.1f %.1f\n", (float)res[0].sht, res[0].avg);
//    }
//    for(int i=1; i<=m; i++){
//        printf("%.1f %.1f\n", (float)res[i].sht, res[i].avg);
//    }
    return 0;
}

