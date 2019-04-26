#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
const int N=1e2+5,M=105;

int n,m,k, cnt=0, tmp=0;

//vector<int> maps[N];
//int maps[N][N];
int a[N][N]={0};

bool cmp(int a,int b){
	return a>b;
}

int main() {
	freopen("1.txt", "r", stdin);
	cin>>n;
	
	_for(i,0,n)
		_for(j,0,i+1)
			cin >> a[i][j];
		
	for(int i=n-1; i>=0; i--){
		_for(j,0,i+1){
			a[i][j] += max(a[i+1][j], a[i+1][j+1]);	
		}
		
	}
	cout << a[0][0] <<endl;
			
		
	return 0;
 }
