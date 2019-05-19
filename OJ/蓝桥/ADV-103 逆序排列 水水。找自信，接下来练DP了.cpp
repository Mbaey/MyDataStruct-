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
//int a[N][N], bits[N];
/*

*/
double x[N], y[N];
double mx=0,my=0;
int main() {
//	freopen("1.txt", "r", stdin);	
	int a[N], cnt=0;
	do{
		cin >> a[cnt++];		 
	}while(a[cnt-1]!=0);
	_for(i,0,cnt-1){
		if(i!=0) cout <<" ";
		cout << a[cnt-i-2];
	}
	return 0;
} 
