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
1.C(5,2) �����ж� ��������˵�Եġ� ���Եõ�һ������� 
2.range(5)  �����ж� �ĸ����������飬 ����ʹ��������˵�Ļ��ԡ� 
*/
double x[N], y[N];
double mx=0,my=0;
int main() {
//	freopen("1.txt", "r", stdin);	
	bool a[5];
	vector<int> r;
	_for(i,0,5){
		fill_n(a,5, false);//����ֱ�������� ����ȽϷ��㡣 
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
