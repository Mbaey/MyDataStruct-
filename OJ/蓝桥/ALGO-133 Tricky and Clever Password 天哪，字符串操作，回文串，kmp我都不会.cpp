//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++) 
typedef long long ll;

const int N=2e2+5;


int n,m,k, tmp,h;

int a[N], vis[3];
int res[3][2];
string s;

//判断俩字符串是不是 前缀和 后缀 
bool Requeal(string a, string b){
	tmp =a.size();
	_for(i,0, tmp){
		if(a[i] != b[tmp-i])
			return false;
	}
	return true;
}
//判断最大的 中缀 奇数 
void findM(string a){
	tmp =a.size();
	_for(i, 1, tmp){
		
	}
}
// Manacher 算法 https://segmentfault.com/a/1190000003914228
// 题解。 http://www.voidcn.com/article/p-pwmwjfsk-m.html 
// 由于只需找出奇数长度的回文串。 便没有插值。 
int main() {
	freopen("1.txt", "r", stdin);
	cin >> s;
	
	n=s.size();

	
	_for(i,0,n){
		_for(j,0,i+1){
			if(i+j >= n || s[i+j] != s[i-j])
				break;		
		
			if(2*j + 1 > res[1][1]){
				res[1][1]= 2*j + 1;
				res[1][0]= i-j+1;
			}
		
		}
	}//最大中缀已找到。 只要len>1 即不可变了。因为对于sum_len来说，消了等于没消 
	if(res[1][0]+res[1][1]-1 == n){
		printf("1\n%d %d\n", res[1][0], res[1][1]);
		return 0;
	}
		
	
	//string pre=s.substr(0, res[1][0]-1);
//	string next=s.substr(res[1][0]+res[1][1]-1);
//	cout << pre << " " <<next;

	_for(i, 1, n){
		string suffix, prefix, Rsuffix;
		suffix=s.substr(n-i, i);
		for(string::reverse_iterator  it = suffix.rbegin(); it != suffix.rend(); it++){
			Rsuffix.push_back(*it);
		}
//		cout << Rsuffix << endl;//debug		
		
		tmp = s.find(Rsuffix);
		if(tmp==-1 || tmp+1+i > n-i+1){// 未考虑前后重叠的情况。 
			break;
		}
		
		res[0][0] = tmp+1, res[0][1] = i;
		res[2][0] = n-i+1, res[2][1] = i;
	}
	if(res[1][1] > 1){
		printf("3\n");
		
		bool preOK = res[0][0]+res[0][1] <= res[1][0];
		bool sufOK = res[1][0]+res[1][1] <= res[2][0];
		
		if(preOK && sufOK){
			printf("%d %d\n", res[0][0], res[0][1]);
			printf("%d %d\n", res[1][0], res[1][1]);
			printf("%d %d\n", res[2][0], res[2][1]);
		}
			
	}else if(res[0][0]+res[0][1] + 1 < res[2][0]){
		printf("3\n");
		printf("%d %d\n", res[0][0], res[0][1]);
		printf("%d %d\n", res[0][0]+res[0][1], 1);
		printf("%d %d\n", res[2][0], res[2][1]);
	}else{
		printf("3\n");
		printf("%d %d\n", res[0][0], res[0][1]-1);
		printf("%d %d\n", res[0][0]+res[0][1]);
		printf("%d %d\n", res[2][0]+1, res[2][1]-1);
	}
	 
	return 0;
}
