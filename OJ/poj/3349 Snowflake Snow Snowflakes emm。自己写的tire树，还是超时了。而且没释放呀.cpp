//#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <limits.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++) 
typedef long long ll;

const int N=6;


int n,m,k, tmp,h;

int a[N], b[N], vis[N];

string s;
struct Tnode{
	int d;
	vector<Tnode*> s;
}root;
/*
http://poj.org/problem?id=3349
难道是tire树？ 
和二分查找有什么关系啊。。。
对了，，还可以hash。。 但咋哈呀。。 
*/
bool flag=1;
void insert(Tnode &now, int id){
	if(id >= 6){
		return;
	}
	vector<Tnode*>::iterator it=now.s.begin();
	for(; it != now.s.end(); it++){
		if((*(*it)).d == b[id]){
			insert( *(*it), id+1);
			return;
		}
	}
	Tnode *n = new Tnode();
	n->d=b[id]; n->s.clear();
	now.s.push_back(n);
	flag=1;
	insert(*n, id+1);
}
void dfs(Tnode &now){
	cout << now.d << " ";
	vector<Tnode*>::iterator it=now.s.begin();
	for(; it != now.s.end(); it++){
		dfs(*(*it));
	}
}
int main() {
	freopen("1.txt", "r", stdin);
	cin >> n;
	root.d = -1;
	root.s.clear();
	
	while(n--){
		int min=INT_MAX, id=0;
		_for(i,0,6){
			scanf("%d", a+i);
			if(a[i]<min){
				min=a[i];
				id=i;
			}
		}
		
		_for(i,0,6){
			tmp= id % 6;
			b[i]= a[tmp];
			id++;
		}
		flag=0;
		insert(root, 0);
		
		if(!flag){
			cout << "Twin snowflakes found."<<endl;
			return 0;
		}
		
		_for(i,0,6){
			tmp= (id+6) % 6;
			b[i]= a[tmp];
			id--;
		}
		flag=0;
		insert(root, 0);
		if(!flag){
			cout << "Twin snowflakes found."<<endl;
			return 0;
		}
//		dfs(root);
//		cout << endl;
	}
	cout << "No two snowflakes are alike."<<endl;
		
	 
	return 0;
}
