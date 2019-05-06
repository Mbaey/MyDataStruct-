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
	bool res=0;
	_for(j,0,6){
		res=1;
		_for(i,0,6){
			if(s1[i] != s2[ (i+j)%6 ]){
				res=0; 
				break;
			}
				
		}
		if(res) return true;
	}
		
	
	_for(j,0,6){
		res=1;
		_for(i,0,6){
			if(s1[i] != s2[ (j+6-i)%6 ]){
				res=0; 
				break;
			}
				
		}
		if(res) return true;
	}
	return false;
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
			a[j][i] = b[i];
			if(b[i]<min){
				min=b[i];
				id=i;
			}
			sum += b[i];
		}
		sum %= MOD; 
//		_for(i,0,6){//从小开始 从右到左 -> 
//			tmp= id % 6;
//			a[j][i]= b[tmp];
//			id++;
//		}
		
		if(hash2id.count(sum)){
			
//			_for(i,0,6){//从小开始 从左到右 <-
//				tmp= (id+6) % 6;
//				c[i]= b[tmp];
//				id--;
//			}
//			
			vector<int> &seem=hash2id[sum]; 
			_for(k,0, seem.size()){
				if(equal(a[seem[k] ], a[j])){
					cout << "Twin snowflakes found."<<endl;
					return 0;
				}
			}	
		}
		hash2id[sum].push_back(j);
	}	
	
	cout << "No two snowflakes are alike."<<endl;
		
	 
	return 0;
}
