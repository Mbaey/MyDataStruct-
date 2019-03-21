#include <bits\stdc++.h>

using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)

const int N=5e4+5,M=25;
int n,m,k;

//int maps[N][N];
//vector<int> a;
long long  a[N];

int main(int argc, char *argv[]) {
//	freopen("1.txt", "r", stdin);
	
	cin >> n >> m;
	int t;
	_for(i,0,n){
		_for(j,0,m){	
			scanf("%d", &t);
			a[i] = a[i]<<1;
			a[i] |= t;
		}
	}
	int cnt=0;

	_for(i,0,n){
		_for(j,i+1,n){
			if((1<<m) ==1+ (a[i] ^ a[j])){//11  01 10
				cnt++;
			}
		}	
	}
	cout << cnt;
	
	return 0;
}