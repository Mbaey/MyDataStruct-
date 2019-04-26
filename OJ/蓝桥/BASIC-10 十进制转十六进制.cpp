#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
const int N=1e2+5,M=105;

int n,m,k, cnt=0, tmp=0;

//vector<int> maps[N];
//int maps[N][N];
int a[N]={0};

int main() {
//	freopen("1.txt", "r", stdin);
	cin >> n ;
	stack<int> s;
	 
	while(n>=16){
		s.push(n % 16 );		
		n = n / 16;
	}
	s.push(n);		
	
	while(!s.empty()){
		
		tmp = s.top(), s.pop();
		if(tmp < 10)
			cout << tmp ;
		else{
			char c='A' + tmp-10 ;
			cout << c ;
		}
			
	}
	
		
	return 0;
 }
