#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
const int N=25,M=405;

int n,m,k;
int dp[N][N];

//vector<int> maps[N];
int maps[N][N], viss[N][N];
int vis[M]={0}, fa[N]={0};

struct E{
	int u,v,d;
}e[M];

bool cmp(E a,E b){
	return a.d < b.d;
}
int find(int a){
	return fa[a]==a? a: fa[a]=find(fa[a]);
} 

bool f=0;
int sum=0;
vector<int> myA;
void dfs(int pre, int root, int to, int dist){
	if(root==to || f){
		f=1;
		sum+=dist; 
		return;
	}
	_for(i,1,n+1){
		if(pre!=i && maps[root][i]!=0){
			myA.push_back(i);
			if(!viss[root][i]){
				viss[root][i]=1;
				dfs(root, i, to, dist+maps[root][i]);
				if(f) return; 
						
				viss[root][i]=0;	
			}else{
				dfs(root, i, to, dist);
			}
			if(f) return; 
			myA.pop_back();
		}
		
	}
}
int main(int argc, char *argv[]) {
	freopen("1.txt", "r", stdin);
	cin >> n >> m >> k;//city num, to m city, k edge;
	int u,v,dis;
	_for(i,0,k){
		scanf("%d %d %d", &u,&v,&dis);
		e[i].u=u, e[i].v=v, e[i].d=dis; 
	}
	
	sort(e, e+k, cmp);
//	_for(i,0,k){
//		cout << e[i].d << endl;
//	}
	_for(i,1,n+1) fa[i]=i;
	
	int cnt=0;
	_for(j,0,k){
		u=e[j].u, v=e[j].v;
		u=find(u), v=find(v);
		if(u != v){
			vis[j]=1;
			fa[u] = v;
			cnt++;			 
		}	
		if(cnt == n-1) break;
	
	}
	
	_for(i,0,k){
		if(vis[i]){
			u=e[i].u, v=e[i].v, dis=e[i].d; 
			maps[u][v]=dis;
			maps[v][u]=dis;
		}
	} 
	
	cin >> k;
	int from[k];
	vector<int> res[k];
	
	_for(i,0,k){
		cin >> from[i];	
	}
	
	_for(i,0,k){
		f=0; myA.clear();
		dfs(0, m, from[i], 0);
		res[i] = myA;
	}
	
	cout << "distance = "<<sum<< endl;
	_for(i,0,k){
		int len=res[i].size();
		
		for(int j=len-1; j>=0;j--){
			cout << res[i][j] <<"-";
		}
		cout<< m <<endl;
	}
	return 0;
 }
