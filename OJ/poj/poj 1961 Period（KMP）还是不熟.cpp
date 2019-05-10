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

int n,m,k, cnt=0,tmp;
char s[N];
int next[N];
/*
T、P字符串 
*/
//next[i] : 当匹配当第i个字符，失配时，P该向前回溯多少， P[0~next[i]] == P[i-next[i]-1~i-1]
void getNext(){
	int i=0,j=-1;
	
	next[0]=-1;
	while(i<n){
		if(j ==-1 || s[i]==s[j]){
			next[++i]=++j;
		}else{
			j=next[j]; 
		}
	}	
	
}

int main() {
	freopen("1.txt", "r", stdin);
	
	while(~scanf("%d", &n) && n){
		scanf("%s", s);
		getNext();
		
		printf("Test case %d\n", ++cnt);
		_for(i,1,n+1){
			if(next[i] && i%(i-next[i]) == 0)
				printf("%d %d\n", i, i/(i-next[i]));
		}
		puts("");
	}
	return 0;
}
