#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
const int N=1e4+5,M=105;

int n,m,k, cnt=0, tmp=0;

//vector<int> maps[N];
//int maps[N][N];
int a[N]={0};

int main(int argc, char *argv[]) {
//	freopen("1.txt", "r", stdin);
	cin >> n ;
	string s;
	char str[N];
	getchar();
	
	_for(iii, 0, n){
		getline(cin, s);
		m = s.find(",");
		k = s.find(".");
		
		if( m!= string::npos&& k!= string::npos &&s.substr(m-3, 3) == "ong" && s.substr(k-3, 3) == "ong"){
			cnt=0;
			for(int i=s.size()-1; i>=0; i--){
				if(s[i] == ' '){
					cnt++;			
				}
				if(cnt == 3){
					tmp=i;
					break;
				}
			} 
			if(tmp>m)
				cout << s.substr(0, tmp) <<" qiao ben zhong."<<endl;
			else
				cout << s.substr(0, m) <<" qiao ben zhong."<<endl;
			
		}else{
			cout<<"Skipped"<<endl; 
		} 
		
	}
	return 0;
 }
