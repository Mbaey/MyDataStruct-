#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 65535*1024

using namespace std;
int N[505][505] = {INF}, N2[505][505] = {0}, W[505]={0}, F[505]= {0};
int n,m, s, e;
//struct Edge{
//    int i,j,w;
//    Edge(int a, int b, int c):i(a),j(b),w(c){}
//};
/* 返回最大聚集人数 */
int find_path_MAX(int s, int e, int w, int ren, int &c){
    if(w == 0){
        ren += W[e] + W[s];
        c++;
        return ren;
    }else{
        int mm=0, t=0;
        for(int i=0; i<n; i++){
            if(i!=s && i!= e && N[s][i] + N[i][e] == N[s][e]){
                ren += W[e];
                t= find_path_MAX(s, i, w-N[i][e],ren, c);
                mm=max(mm, t);
                ren -= W[e];
            }

        }
        if(N[s][e] == N2[s][e]){
           t = find_path_MAX(s, e, 0, ren, c);
           mm=max(mm, t);
        }
        return mm;
    }
}

int main()
{
    freopen("1.txt", "r", stdin);

    memset(N2, 0, sizeof(N));
    cin >> n >> m>> s>> e;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            N[i][j]=INF;
    for(int i=0; i<n; i++) { cin >>W[i]; N[i][i]=0; }
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a>> b>> c;
        N[a][b] =c;
        N[b][a] =c;
        N2[a][b] =c;
        N2[b][a] =c;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(N[s][j]+N[j][i] < N[s][i]){
                N[s][i] = N[s][j]+N[j][i];
                F[i] = j;
            }

        }
    }
    int peo=0, c=0;
    peo = find_path_MAX(s, e, N[s][e],0, c);
    cout << c <<" "<<peo;
    return 0;
}
