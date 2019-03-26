#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
const int N=105,M=405;

int n,m,k;
int dp[N][N];

//vector<int> maps[N];
int maps[N][N];
int swapF[N]={0}, an=0;
int a[N]={0}, cnt=0, len;
string s;
void track(int n){
	
	if(n==an){
		bool f=1;
		_for(i,0,an){
			if(!swapF[i]){
				int now=a[i];
				char next=s[ (now+1) % len];
				if( next == 'B'){
					f=0;break;
				}
			}
		}
		if(f){		
			cnt++;
			cout << s <<endl;
		}
		return;
	}
	int now=a[n];
	char pre=s[ (now-1 + len) % len];
	if(pre=='B'){
		swap(s[now], s[ (now-1 + len) % len]);
		swapF[n]=1; 
		a[n]--;
		
//		cout << s <<endl;
		track(n+1);
		
		swap(s[now], s[ (now-1 + len) % len]);
		swapF[n]=0; 
		a[n]++;
	}
	
	track(n+1);
}

int main(int argc, char *argv[]) {
	freopen("1.txt", "r", stdin);
	
	cin >>s;
	len = s.length();
	//cout << s;
	_for(i,0,len){
		if(s[i]=='A'){
			a[an++]=i;
		}
	}
	if(an==0){
		cout << 1<<endl; return 0;
	}
	
	
	track(0);
	cout << cnt;
	return 0;
 }
