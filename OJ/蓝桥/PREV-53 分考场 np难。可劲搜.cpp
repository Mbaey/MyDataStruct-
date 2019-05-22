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

const int N=1e3+5;
int n,m, h, res=N;
int a[N][N], cnt=0; 
vector<int> clrs[N];
/*
�������� �ֿ���
ѽ��һ��ʼ��Ϊ�ǲ��鼯��
���Լ�����ô�����ҵ���С�Ŀ�������
û�뵽һ�ٶȣ���Ȼ��ͼ��ɫ���⣬np�ѡ���������С��ֱ���ѡ��� 
https://www.cnblogs.com/looeyWei/p/10439834.html
*/
bool ok(int idx, int c){
	int len = clrs[c].size();
	_for(i,0,len){
		int idx2= clrs[c][i];
		if(a[idx][idx2])
			return 0;
	}
	return 1;
}
void dfs(int now, int color){
	if(color >= res)return;
	if(now>n){
		res = min(res, color);
		return;
	}
	
	_for(i,1,color+1){
		if(ok(now, i)){
			
			clrs[i].push_back(now);
			dfs(now+1, color);
			clrs[i].pop_back();
		}
	}

	clrs[color+1].push_back(now);
	dfs(now+1, color+1);
	clrs[color+1].pop_back();	
}

int main() {
//	freopen("1.txt", "r", stdin);	
	cin >> n>> m;
	int u,v;
	_for(i,0,m){
		scanf("%d %d", &u, &v);
		a[u][v]=1;
		a[v][u]=1;
	}
//	_for(i,1,n+1) {
//		_for(j,1,n+1) {	
//			cout << a[i][j]<<" ";
//		}
//		cout << endl;
//	}
	
	//emmm,���һ��ʼ����1,1�������һ�����лᱻ������ɫ��1��2 ���Ӷȶ���һ���� 
	dfs(1, 0);
	
	cout << res;
	
	return 0;
} 
