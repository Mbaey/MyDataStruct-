#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 65535*1024

using namespace std;

//struct Edge{
//    int i,j,w;
//    Edge(int a, int b, int c):i(a),j(b),w(c){}
//};
/* 返回最大聚集人数 */
//int find_path_MAX(int s, int e, int w, int ren, int &c){
//    if(w == 0){
//        ren += W[e] + W[s];
//        c++;
//        return ren;
//    }else{
//        int mm=0, t=0;
//        for(int i=0; i<n; i++){
//            if(i!=s && i!= e && N[s][i] + N[i][e] == N[s][e]){
//                ren += W[e];
//                t= find_path_MAX(s, i, w-N[i][e],ren, c);
//                mm=max(mm, t);
//                ren -= W[e];
//            }
//
//        }
//        if(N[s][e] == N2[s][e]){
//           t = find_path_MAX(s, e, 0, ren, c);
//           mm=max(mm, t);
//        }
//        return mm;
//    }
//}
int N[505][505] = {INF},W[505]={0};
int peo[505]={0}, c[505]={0}, vis[505]= {0}, F[505]= {0};
int n,m, s, e;
int main()
{
    freopen("1.txt", "r", stdin);

//    memset(N2, 0, sizeof(N));
    cin >> n >> m>> s>> e;
    fill(N[0], N[0] + 505*505, INF);
    for(int i=0; i<n; i++) { cin >>W[i]; }
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a>> b>> c;
        N[a][b] =c;
        N[b][a] =c;
    }
    fill(F, F+505, INF);
    c[s]=1;
    peo[s]=W[s];
//    vis[s] = 1;
    F[s] = 0;
    for(int i=0; i<n; i++){
        int f=-1, min=INF;
        for(int j=0; j<n; j++){
            if(!vis[j] && F[j] < min){
                f=j; min = F[j];
            }
        }
        if(f==-1) break;
        vis[f] = 1;
//        peo[f] = peo[Father[f]] + W[f];
//        c[f] = c[s];
        for(int j=0; j<n; j++){
            if(!vis[j] && N[f][j] != INF)
            if(F[f] + N[f][j] < F[j]){
                F[j] = F[f] + N[f][j];
//                Father[j] = f;
                c[j] = c[f];//
                peo[j]=  peo[f] + W[j];//
            }else if(F[f] + N[f][j] == F[j]){
                c[j] = c[f] + c[j];
                if(peo[j] < peo[f] + W[j]){
                    peo[j] = peo[f] + W[j];
                }
            }
        }
    }
//    int peo=0, c=0;
//    peo = find_path_MAX(s, e, N[s][e],0, c);
    cout << c[e] <<" "<<peo[e];
    return 0;
}
