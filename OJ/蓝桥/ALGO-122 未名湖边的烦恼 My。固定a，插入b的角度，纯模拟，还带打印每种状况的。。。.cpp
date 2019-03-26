#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
const int N=20,M=20;

int n,m,k;

vector<int> tmp, next1;
vector<vector<int> > a, pre;
//void dis(){
//	for(auto i : a){
//		for(auto j : i){
//			cout << j<<" ";
//		}cout << endl;
//	}
//} 
int main(int argc, char *argv[]) {
	freopen("1.txt", "r", stdin);
	cin>> m>>n;
	if(m<n){
		cout << 0<<endl;
		return 0;
	}

	_for(j,0,m){
		tmp.clear();
		tmp.resize(m);
		tmp[j]=1;
		a.push_back(tmp);	
	}
		
	_for(i,1,n){//循环n-1次 第一次已经初始化。 
		pre = a;
		a.clear();
		
		int len = pre.size();
		_for(j, 0, len){
			tmp = pre[j];
			int get=0; 
			int start;
			_for(k, 0, m){
				if(tmp[k] != 0){
					start=k;
				}
			}
			
			_for(k, 0, m){
				next1 = tmp;
				get += tmp[k];
				if(k>=start && get < k +1){//防止重复、借完， 
					next1[k]++;
					a.push_back(next1);
				}		
			}			
		}		
			
	}
	//dis(); cout << endl;

	
	cout << a.size() << endl;	
	
	return 0;
 }
