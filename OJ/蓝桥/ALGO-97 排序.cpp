#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
const int N=1e2+5,M=105;

int n,m,k, cnt=0, tmp=0;

//vector<int> maps[N];
//int maps[N][N];
int a[N]={0};

bool cmp(int a,int b){
	return a>b;
}

int main() {
	freopen("1.txt", "r", stdin);
	
	_for(i,0,3)
		cin >> a[i];
		
	sort(a, a+3, cmp);
	
	_for(i,0,3)
		if(i==0)
			cout << a[i];
		else
			cout << " "<<a[i];
		
		
	return 0;
 }
