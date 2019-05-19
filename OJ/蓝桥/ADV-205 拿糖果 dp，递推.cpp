//#include <bits/stdc++.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++) 
#define MY_MIN  99999999
#define MY_MAX  -99999999

typedef long long ll;

const int N=1e5+5;
int n,m, h;
int a[N];
int prime[N], cnt=0, vis[N];
/*

*/
int main() {
//	freopen("1.txt", "r", stdin);	
	cin >> n;
	
	_for(i,2, sqrt(N)+1){
		if(!vis[i]){
			prime[cnt++]=i;
			for(int j=i+i; j<N; j+=i){
				vis[j]=1;
			}
		}
	}
	
	_for(i,1, n+1){
		_for(j,0,cnt){
			int tmp=prime[j];
			if(prime[j]*prime[j] > i) break;
			
			if(i % tmp  == 0){
				a[i] = max(a[i], a[i-2*tmp]+tmp);
			}
		} 
	}
	
	cout << a[n];
	
	return 0;
} 
