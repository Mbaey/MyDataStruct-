#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)
typedef long long ll;
const int N=1e4+5,M=105;

int n,m,k, cnt=0, tmp=0;

//vector<int> maps[N];
//int maps[N][N]; 81*4
int a[N]={0}, no[N]={0};

int powE(int k){
	int res=0;
	while(k != 0){
		tmp = k %10;
		res += tmp*tmp;
		k/=10;
	}
	return res;
}
bool isPrime(int p){
	_for(i, 2, sqrt(p)+1){
		if(p % i == 0){
			return false;
		}
	}
	return true;
} 
struct res{
	int i, w;
}r1;
int main(int argc, char *argv[]) {
	freopen("1.txt", "r", stdin);
	cin >> n >> m ;
	vector<res> ans;
	_ufor(i,m+1, n){		
		k=i;
		bool f=0;
		cnt=0;
		fill_n(a, N, 0);//a[i]: i经过几次能到1 
		while(k != 1){
			if(a[k]){//已经有啦，表示要么有环，要么不独立 
				f=1;
				break;
			}
			a[k]=1;
			
			k = powE(k);
			cnt++;
			
			no[k] = 1;
		}
		if(!f && no[i]==0){
			if(isPrime(i))
				r1.i=i, r1.w=cnt*2;
			else
				r1.i=i, r1.w=cnt;
			ans.push_back(r1);
		}
	}
	_ufor(j, ans.size(), 0){
		cout << ans[j].i <<" " << ans[j].w<< endl;
	}
	if(ans.empty()){
		cout <<"SAD" <<endl;
	}
	
	return 0;
}
