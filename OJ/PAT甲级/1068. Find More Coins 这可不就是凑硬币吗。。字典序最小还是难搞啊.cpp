#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
const int N=1e4+5,M=105;

int n,m,k;

//vector<int> maps[N];
//int maps[N][N];
int a[N]={0}, cnt=0;
int d[N][M]={0}, choice[N][M]={0};
void dis(){
	_for(i,0,n+1){
		_for(j,0,m+1){
			cout << d[i][j] <<" ";
		}		cout << endl;
	}
	
	_for(i,0,n+1){
		_for(j,0,m+1){
			cout << choice[i][j] <<" ";
		}		cout << endl;
	}
}

int cmp1(int a, int b){return a > b;}
int main(int argc, char *argv[]) {
	freopen("1.txt", "r", stdin);
	cin >> n >> m;
	_for(i,1,n+1){
		scanf("%d", a+i);
	}
	
	sort(a+1, a+n+1, cmp1);
	//d[i][j]: 前i个硬币，能凑出价值==j 的 最大数量。
	//d[i][j]: 前i个硬币，能凑出价值==j 的 价值。。 
	d[0][0]=0;
	int fa[M]={0};
	_for(i,1,n+1){
		_for(j,a[i],m+1){
			d[i][j]=d[i-1][j];
			//liuchuo 是dp[i][j]: 前i个硬币，价值j约束下，能凑出的最大价值
//			dp[j] <= dp[j-w[i]] + w[i]
			if(j>=a[i] && j == a[i]+d[i-1][j-a[i]]){
				d[i][j]=j; //通过a[i] 走到了价值j 
//				fa[j] = i;
				choice[i][j]=1;
			}				
		}
	}
	dis();
	if(d[n][m]==0){
		cout << "No Solution"<<endl;
	}else{
		vector<int> arr;
        int v = m, index = n;
        while(v > 0) {
            if(choice[index][v] == true) {
                arr.push_back(a[index]);
                v -= a[index];
            }
            index--;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", arr[i]);
        }
	} 
	
	//_for(i,1,n+1){
//		fill_n(d[i]+1, m+1, -1);
//		d[i][0]=0;
//		_for(j,0,m+1){
//			d[i][j]=d[i-1][j];
//			//不要第i个，要 
//			if(j>=a[i] && d[i-1][j-a[i]]+1 > d[i][j])	{
//				d[i][j] = d[i-1][j-a[i]]+1;
////				fa[j]=i;
//			}
////				d[i][j] = max(d[i-1][j], d[i-1][j-a[i]]+1 );
//		}
//	}
//	
//	print_ans(m);
//	dis();
	//int tmp=m;
//	while(tmp){
//		cout << fa[tmp] << " ";
//		tmp -= a[fa[tmp]];
//	}
//	cout << d[n][m];
	return 0;
 }
