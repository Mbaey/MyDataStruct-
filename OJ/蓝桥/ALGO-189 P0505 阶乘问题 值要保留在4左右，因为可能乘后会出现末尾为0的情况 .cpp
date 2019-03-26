#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
const int N=20,M=20;

int n,m,k;
int dp[N][N];


int main(int argc, char *argv[]) {
	freopen("1.txt", "r", stdin);
	while(cin>> n){
	    ll res=1;
	    _for(i,2,n+1){
	    	
	    	res = (res* i);
			while(res % 10 == 0){
				res /= 10;
			}
			res %= 100000; 
		}
		res %= 10;
		cout << res << endl;	
	}
	return 0;
 }
