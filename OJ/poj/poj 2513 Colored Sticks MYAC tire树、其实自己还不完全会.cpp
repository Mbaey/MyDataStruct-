//#include <bits/stdc++.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++) 
typedef long long ll;

const int N=1000010;
/*
坑啊，得自己建tire树。
http://www.voidcn.com/article/p-gkeuxoam-sg.html
1.因为我懒得动态申请内存。直接开了个数组。但这样的话鬼知道N设置成多大啊。
2.这个是无向图，stick可以翻转的。不能用in、out数组，
3.还得判断连通分支数。
*/

int n, m, k, tmp,h, cnt=1;

//int a[N], vis[N];
int deg[N],father[N];

char stick[2][12];
//map<string, int> color2id;
//int c2id(string h, bool ht){
//	int res;
//	if(color2id.count(h)){
//		res=color2id[h];
//	}else{
//		color2id[h]=cnt;
//		res=cnt;
//		cnt++;
//	}
//	return res;
//}
struct trie{
    bool Isword;
    int next[26];
}node[N];

void Init(){
    cnt = 1;
    for(int i=0; i<N; i++){
    	father[i] = i;
        memset(node[i].next, 0, sizeof(node[i].next));
        node[i].Isword = false;
    }
}
int Insert(char *s){
    int p = 0, n = strlen(s);
    
    for(int i=0; i<n; i++){
        if(node[p].next[s[i]-'a'] == 0){
        	node[p].next[s[i]-'a'] = cnt++;
		}
        p = node[p].next[s[i]-'a'];
    }
    node[p].Isword = true;
    return p;
}

int Find(int i){	return i==father[i] ? i : father[i]=Find(father[i]);} 

int main() {
//	freopen("1.txt", "r", stdin);
	
	Init();
	
	while(scanf("%s %s", &stick[0], &stick[1]) == 2){
//		printf("%s %s\n", stick[0] , stick[1]);
		int u,v;
//		string h(stick[0]), t(stick[1]);		
//		u = c2id(h, 1);
//		v = c2id(t, 0);
		
		u = Insert(stick[0]);
		v = Insert(stick[1]);
		
		if(u>=N || v>=N){
			printf("aaaa\n");
			return 0;
		}
		
		father[Find(u)] = Find(v);
		deg[u]++;
		deg[v]++;	
	}
	int num=0;
	for(int i=0; i<N; i++){
        if(!node[i].Isword ) continue;
        if(father[i] == i) num++;
    }
	if(num > 1) puts("Impossible");
	else{	
		int single=0;
		_for(i, 1, cnt){
			if(!node[i].Isword ) continue;
			if( deg[i] & 1){//(in[i]+out[i])%2 == 1 			
				single++;
			}
		}
		if(single!=2 && single!=0){
			printf("Impossible\n");
		}else{
			printf("Possible\n");
		}
	}		
	
	return 0;
}
