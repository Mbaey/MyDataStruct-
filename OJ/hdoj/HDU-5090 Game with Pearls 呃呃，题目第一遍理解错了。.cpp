//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++) 
typedef long long ll;

const int N=2e2+5;


int n,m,k, tmp,h;

int a[N], v[N];
int main() {
	freopen("1.txt", "r", stdin);
	
	cin >> m;
	while(m--){
		
		cin >> n>>k;
		fill_n(v, n+1, 0);
		
		_for(i,0,n)
			cin >> a[i];
		
		sort(a,a+n);
		
		_for(i,0,n){
			int &now = a[i];
			while(v[now] && now <= n+1){
				now+=k;
			}
			v[now]=1;
		}
		bool f=0;
		_for(i,1,n+1){
			if(!v[i])
				f=1;
		}
		if(f){
			cout <<"Tom"<<endl;
		}else{
			cout <<"Jerry"<<endl;
		}
	}
	 
	return 0;
}
