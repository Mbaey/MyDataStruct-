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
		m = s.find("ong,");
		k = s.find("ong.");
//&& s.substr(m-3, 3) == "ong" && s.substr(k-3, 3) == "ong"
		if( m!= string::npos&& k!= string::npos){
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
			//_for(i,0,tmp)
//				cout << s[i];
			cout << s.substr(0, tmp)<<" qiao ben zhong."<<endl;			
		}else{
			cout<<"Skipped"<<endl; 
		} 
		
	}
	return 0;
 }
