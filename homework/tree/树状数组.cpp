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

const int N=100050;
/*
���ԣ���״�����ʺϵ���Ԫ�ؾ����޸Ķ���
������Ҫ�󲿷ֵ�����ĺ͵������
����������ȻҲ�������߶��������������
��״�������������Ч�ʺͳ�������Ч�ʶ�
���ߡ�
���ÿ��Ҫ�޸ĵĲ��ǵ���Ԫ�أ�����
һ�����䣬�ǾͲ�������״������(Ч�ʹ��ͣ�
*/
int n,m, h;
int a[N];
int lowbit(int x){
	return x&-x;
}
//emm.. ������a[0]����Ϊ0+lowbit(0) = 0 
void add(int idx, int data){
	while(idx<=n){
		a[idx] += data;
		idx += lowbit(idx);
	}
}

int sum(int idx){
	int res=0;
	while(idx > 0){
		res += a[idx];
		idx -= lowbit(idx);
	}
	return res;
}
int main() {
//	freopen("1.txt", "r", stdin);
	
//	scanf("%d", &n);
//	int u,v;
//	_for(i,0,n-1){
//		scanf("%d %d", &u, &v);
//	}	
//	
//	scanf("%d", &m);
//	char op;
//    _for(i,0,m-1){
//		scanf("%c %d", &op, &u);		
//	}	
	n=15;
	_for(i,1,n+1){
		add(i,i);
	}

	_for(i,1,n+1){
		printf("No.%d Sum: %d\n", i, sum(i));
	}
	
	
	return 0;
} 
