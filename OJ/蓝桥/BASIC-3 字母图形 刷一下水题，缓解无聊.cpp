#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
const int N=1e2+5,M=105;

int n,m,k, cnt=0, tmp=0;

//vector<int> maps[N];
//int maps[N][N];
int a[N][N]={0};


int main() {
	freopen("1.txt", "r", stdin);
	cin >> n>> m;
	
	_for(i,0, n){
		_for(j,0, m){
			putchar(abs(i-j)+'A');
		}		
		printf("\n");
	}
	return 0;
 }
