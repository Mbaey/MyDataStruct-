#include<bits/stdc++.h>
using namespace std;
#define M 200005
int T,n,m,k;
vector<int>G[M];
int main() {
    scanf("%d",&T);
    while(T--) {
		//m 总边数
		//mx 最大度
		
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0; i<n; i++)G[i].clear();
        int now=n-1,mx=0;
        int f=now-m;
        for(int i=1; i<=m; i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y),G[y].push_back(x);
        }
        for(int i=0; i<n; i++)if(G[i].size()>mx)mx=G[i].size();
        int a=m-mx;
        if(a>=k)printf("%d\n",mx+f+k);
        else printf("%d\n",mx+a+f);
    }
    return 0;
}
