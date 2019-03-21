#include <bits/stdc++.h>

using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)

const int N=1e4+5, INF=1e9;
int n,m,k;

int a[N], vis[N];

vector<int> maps[N];
int cnt,start;
void dfs(int node, int h){
	
	if(h>=3){
		cnt++;
		//cout << endl;
		return;
	}
	
	int len=maps[node].size();
	_for(ii, 0, len){
		int i = maps[node][ii];
		if(h==2 && i==start){
			cnt++;
		}
		if(!vis[i]){
			vis[i]=1;
			//cout << i;
			dfs(i, h+1);			
			vis[i]=0;
		}	
	}	
}
int main(int argc, char *argv[]) {
	freopen("1.txt", "r", stdin);
	
	cin >> n>>m;
	int u,v;
	_for(i, 0, m){
		scanf("%d %d", &u, &v);
		maps[u].push_back(v);
		maps[v].push_back(u);
	}	
	
	int res=0;
	_for(i, 1, n+1){
		cnt=0;
		start=i;
		vis[i]=1;
		dfs(i, 0);
		vis[i]=0;
		res+=cnt;
	}
	cout << res;		
	
	return 0;
}
