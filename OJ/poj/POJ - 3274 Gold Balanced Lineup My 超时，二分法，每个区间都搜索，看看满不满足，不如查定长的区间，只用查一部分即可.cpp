//#include <bits/stdc++.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++) 
typedef long long ll;

const int N=6;


int n,m,k, tmp,h;

//int a[N], vis[N];
int a[100005][35], b[35];
/*
http://poj.org/problem?id=3274
 
*/

bool j(int m){
	_for(i, 0, n-m){
		fill_n(b,k,0);
		_for(j, i, i+m){
			_for(ii, 0, k){
				b[ii] += a[j][ii];
			}
		}
		bool res=1;
		_for(j, 1, k){
			if(b[j] != b[j-1]){
				res=0;
			}		
		}		
		if(res){
			return true; 
		}
	}
	
	return false;
} 
 


int main() {
//	freopen("1.txt", "r", stdin);
	cin >> n >> k;
	
	_for(i, 0, n){
		scanf("%d", &tmp);	
		_for(j, 0, k){
			if(tmp >>j & 1){
				a[i][j]=1;
			}
		}
	}
	
	int l,r,m;
	l=1, r=n;
	while(l<r){//[,) ??
		m=l+(r-l)/2;
		if(j(m)) l=m;
		else r=m-1;
	}
	cout << l;	
	 
	return 0;
}
