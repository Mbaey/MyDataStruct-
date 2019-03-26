#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
const int N=20,M=20;

int n,m,k;
int dp[N][N];

//vector<int> tmp, next1;
//vector<vector<int> > a, pre;


int main(int argc, char *argv[]) {
	freopen("1.txt", "r", stdin);
	cin>> m>>n;

	for(int i=1;i<N;++i)
    {
        dp[i][0]=1;
        for(int j=1;j<=i;++j)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    
	cout << dp[m][n] << endl;	
	
	return 0;
 }
