#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,a,b) for(int i=a-1; i>=b; i--)
typedef long long ll;
const int N=5000+5,M=5000+5;

int n,m,k, cnt=0, tmp=0;

//vector<int> maps[N];
//int maps[N][N];
int a[N][M]={0};

bool cmp(int x, int y){
	return a[x][0] < a[y][0];
}
int main()
{
    freopen("1.txt", "r", stdin);
    cin>>n;
    int index[N];
	_for(i,0,n){
		index[i]=i;
		
		int x,y,mod;
		cin >> m >> a[i][0] >> x>>y>>mod;
		_for(j,1,m){
			a[i][j] = (a[i][j-1]*x+y)%mod;
		}
		sort(a[i], a[i]+m);
	} 
	
	sort(index, index+n, cmp);
	
	//_for(i,0,n){
//		_for(j,0,m){
//			cout << a[i][j]<<" ";
//		} 
//		cout << endl;
//	}
	_for(i,1,n){
		int peo= index[i];
		int prePeo= index[i-1];
		if(a[peo][0]< a[prePeo][0])
			cnt++; 
	} 
	cout <<cnt<<endl;
	_for(i,0,n){
		int peo= index[i];
		_for(j,0,m){	
			cout << a[peo][j]<<" " << peo+1<<endl;
		} 
	}
	

    return 0;
}


