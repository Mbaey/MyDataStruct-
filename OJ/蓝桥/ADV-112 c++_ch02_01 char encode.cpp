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
	string s="AEIOUaeiou";
	
	_for(i,0,10){
		cout << (int)s[i]<<endl;
	} 
	return 0;
} 
