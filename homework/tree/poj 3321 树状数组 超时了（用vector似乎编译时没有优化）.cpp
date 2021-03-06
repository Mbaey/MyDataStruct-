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
所以，树状数组适合单个元素经常修改而且
还反复要求部分的区间的和的情况。
上述问题虽然也可以用线段树解决，但是用
树状数组来做，编程效率和程序运行效率都
更高。
如果每次要修改的不是单个元素，而是
一个区间，那就不能用树状数组了(效率过低）
*/
int n,m, h;
int a[N], bits[N];
int lowbit(int x){
	return x&-x;
}
//emm.. 不能用a[0]，因为0+lowbit(0) = 0 
void add(int idx, int data){
	while(idx<=n){
		bits[idx] += data;
		idx += lowbit(idx);
	}
}

int sum(int idx){
	int res=0;
	while(idx > 0){
		res += bits[idx];
		idx -= lowbit(idx);
	}
	return res;
}

vector<int> G[N];
int vis[N], s[N], e[N], num=0; 
void dfs(int now){
	vis[now]=1;
	s[now]= ++num;
	
	_for(i,0,G[now].size()){
		if(!vis[G[now][i]]){
			dfs(G[now][i]);
		}
	}
	e[now]=num;
}
int main() {
//	freopen("1.txt", "r", stdin);	
	scanf("%d", &n);
	int u,v;
	_for(i,0,n-1){
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}	
	dfs(1);
	
	_for(i,1,n+1){
//		add(i, 1);
		bits[i] = lowbit(i);
	}
	
	scanf("%d", &m);
	char op;
	
    _for(i,0,m){
    	getchar();
		scanf("%c %d", &op, &u);		
		if(op=='C'){
			a[s[u]] = 1 - a[s[u]];
			if(a[s[u]]==1){
				add(s[u], -1);
			}else
				add(s[u], 1);
		}else{
			printf("%d\n", sum(e[u]) - sum(s[u]-1));
		}
	}	
//	n=15;
//	_for(i,1,n+1){
//		add(i,i);
//	}
//
//	_for(i,1,n+1){
//		printf("No.%d Sum: %d\n", i, sum(i));
//	}
	
	
	return 0;
} 
