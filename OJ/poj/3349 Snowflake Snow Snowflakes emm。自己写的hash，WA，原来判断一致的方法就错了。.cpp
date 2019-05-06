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


int n,m,k, tmp,h;

//int a[N], vis[N];
int a[100005][N],b[N], c[N];
/*
http://poj.org/problem?id=3349
难道是tire树？ 
和二分查找有什么关系啊。。。
对了，，还可以hash。。 但咋哈呀。。 
*/
bool flag=1;

map<int, vector<int> > hash2id;
bool equal(int s1[], int s2[]){
	_for(i,0,6){
		if(s1[i] != s2[i])
			return false;
	}
	return true;
}
int MOD=19999;
int main() {
	freopen("1.txt", "r", stdin);
	cin >> n;
	
	int sum;
	
	_for(j,0,n){
		sum=0;
		int min=INT_MAX, id=0;
		_for(i,0,6){
			scanf("%d", b+i);
			if(b[i]<min){
				min=b[i];
				id=i;
			}
			sum += b[i];
		}
		sum %= MOD; 
		_for(i,0,6){//从小开始 从右到左 -> 
			tmp= id % 6;
			a[j][i]= b[tmp];
			id++;
		}
		
		if(hash2id.count(sum)){
			
			_for(i,0,6){//从小开始 从左到右 <-
				tmp= (id+6) % 6;
				c[i]= b[tmp];
				id--;
			}
			
			vector<int> &seem=hash2id[sum]; 
			_for(k,0, seem.size()){
				if(equal(a[seem[k] ], a[j]) || equal(a[seem[k]], c)){
					cout << "Twin snowflakes found."<<endl;
					return 0;
				}
			}	
		}
		hash2id[sum].push_back(j);
	}
//	map<int, vector<int> >::iterator it;
//	for(it=hash2id.begin(); it!= hash2id.end(); it++){
//		vector<int> seem=(*it).second; 
//		_for(i,0, seem.size()){
//			cout << seem[i] <<" ";
//		}
//	}
	
	
	
	
	cout << "No two snowflakes are alike."<<endl;
		
	 
	return 0;
}
