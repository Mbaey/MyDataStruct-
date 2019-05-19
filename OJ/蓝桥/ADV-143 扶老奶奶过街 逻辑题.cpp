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
1.C(5,2) 依次判断 哪两个人说对的。 可以得到一个结果。 
2.range(5)  依次判断 哪个人做了事情， 可以使得两个人说的话对。 
*/
double x[N], y[N];
double mx=0,my=0;
int main() {
//	freopen("1.txt", "r", stdin);	
	bool a[5];
	vector<int> r;
	_for(i,0,5){
		fill_n(a,5, false);//还是直接在里面 定义比较方便。 
		a[i]=true;
		int sum=0;
		
		if(!a[0] && !a[4]) sum++;
		if(a[2] || a[4]) sum++;
		if(a[2] || a[3]) sum++;
		if(!a[1] && !a[2]) sum++;
		if(!a[4]) sum++;
		
		if(sum==2){
			r.push_back(i);
		}
	}
	_for(i,0,r.size()){
		if(i!= 0){
			printf(" ");
		}
		printf("%c", r[i]+'A');
	}
	
	return 0;
} 
