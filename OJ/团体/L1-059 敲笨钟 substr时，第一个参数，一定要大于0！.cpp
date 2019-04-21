#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
const int N=1e2+5,M=105;

int n,m,k, cnt=0, tmp=0;

//vector<int> maps[N];
//int maps[N][N];
int a[N]={0};


int main() {
	freopen("1.txt", "r", stdin);
	cin >> n ;
	getchar();
	
	string s;
	while(n--){
		getline(cin, s);
		m = s.find(",");
		k = s.find(".");

		if( m>2 && k>2 && s.substr(m-3, 3) == "ong" && s.substr(k-3, 3) == "ong"){
			cnt=0;
			for(int i=s.length()-1; i>=0; i--){
				if(s[i] == ' '){
					cnt++;		
				}
				if(cnt == 3){
					tmp=i;
					break;
				}
			}
			cout << s.substr(0, tmp+1) <<"qiao ben zhong."<<endl;			
		}else{
			cout<<"Skipped"<<endl; 
		} 
		
	}
	return 0;
 }
