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


int n, k, tmp,h;

//int a[N], vis[N];
int a[100005][35], b[35], sum[100005][35];
/*
http://poj.org/problem?id=3274
 
*/

bool j(int m){

	_for(i, 1, n-m+1){
		fill_n(b,k,0);
//		_for(j, i, i+m){//ßÀßÀ£¬O£¨n^2£© -> O(n)
//			_for(ii, 0, k){
//				b[ii] += a[j][ii];
//			}
//		}
		_for(j, 0, k)
			b[j] = sum[i+m-1][j]-sum[i-1][j];
		bool res=1;
		_for(j, 1, k){
			if(b[j] != b[j-1]){
				res=0;
				break;
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
	
	_for(i, 1, n+1){
		scanf("%d", &tmp);	
		_for(j, 0, k){
			if(tmp >>j & 1){
				a[i][j]=1;
			}
		}
	}

	_for(i, 1, n+1)
		_for(j,0,k)
			sum[i][j] = sum[i-1][j] + a[i][j];
	
//	printf("a:\n");
//	_for(i, 0, n){
//		_for(j,0,k)
//			printf("%d ", a[i][j]);
//		printf("\n");
//	}
//	printf("sum:\n");
//	_for(i, 0, n){
//		_for(j,0,k)
//			printf("%d ", sum[i][j]);
//		printf("\n");
//	} 
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
