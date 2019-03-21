#include <bits\stdc++.h>

using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)

const int N=5e4+5,M=25, MAX=1<<20+1;
int n,m,k;

//int maps[N][N];
//vector<int> a;
long long  a[N];
int cnt[MAX], vis[MAX];
int main(int argc, char *argv[]) {
	freopen("1.txt", "r", stdin);
	
	cin >> n >> m;
	int t;
	
	_for(i,0,n){
		_for(j,0,m){	
			scanf("%d", &t);
			a[i] = a[i]<<1;
			a[i] |= t;
		}
		cnt[a[i]]++;
	}
	int res=0;

	_for(i,0,n){
		if(!vis[a[i]] && !vis[(1<<m)-1-a[i]] ){
			res += cnt[ a[i] ] * cnt[(1<<m)-1-a[i]];
			vis[a[i]] = vis[(1<<m)-1-a[i]] =1;
		}
		
	}
	cout << res << endl;
	return 0;
}
