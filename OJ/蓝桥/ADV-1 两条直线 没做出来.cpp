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
1.�Ȱ�ÿ��������� �������Ա任��ת90�ȣ������ֵ������С�� ���پ��롣 
//	true 12129.0
//	my 13866.8 �ҵĲ���ʧ���ˣ�	�ǵģ��������ֵ�� ����  .. ������������ĵ�����ơ� 

2.Ҫ��Ĵ��������ģ������ö��ַ��ѡ�
https://www.cnblogs.com/mypsq/p/4410081.html
 
*/
double x[N], y[N];
double mx=0,my=0;
int main() {
	freopen("1.txt", "r", stdin);	
	scanf("%d", &n);
	int u,v;
	u=M_SQRT2;
	_for(i,0,n){
		scanf("%d %d", &u, &v);
		x[i] = M_SQRT2*(u+v)/2;
		y[i] = M_SQRT2*(v-u)/2;
		mx+=x[i];
		my+=y[i];
	}
	mx/=n; my/=n;
	double res=MY_MAX, xmax=MY_MAX,ymax=MY_MAX, xmin=MY_MIN, ymin=MY_MIN;
	_for(i,0,n){
		xmax = max(xmax, x[i]);
		xmin = min(xmin, x[i]);
		
		ymin = min(ymin, y[i]);
		ymax = max(ymax, y[i]);
		
	}
	mx=(xmax-xmin)/2;
	my=(ymax-ymin) / 2;
	
	_for(i,0,n){
		double dist = max(fabs(x[i]-mx), fabs(y[i]-my));
		res = max(res, dist);
	}
	
	
	printf("%.1f", res*M_SQRT2); 
	
	return 0;
} 
