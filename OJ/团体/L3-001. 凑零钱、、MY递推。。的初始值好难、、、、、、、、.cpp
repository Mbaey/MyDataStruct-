#include <cstdio>

#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N =10005;
const int M =105;
int n, m;
int a[N]={0};
bool vis[N];
void dis(vector<int> a);
bool f=false;
void dongTai(int curV, vector<int> &res); //这是 有限的硬币问题。 回溯法的解法。

//define d(i, x) 表示第i个阶段 还剩余x的钱没凑够
/*
1.如果是无限硬币，求最长最短路（最多/少的硬币凑值）
则可定义d(i) 表示还剩余i的钱没凑够时所需的最多或最少的硬币 初识状态为m， 目标为0
则该问题变为DAG上最长路的求解
d(S) = max(d(S-a[j])+1)  //这是最长路的状态转移方程
*/
/*2.当前需求是 最长路径 有限硬币！
//注：我们说序列{A[1], A[2], ...}比{B[1], B[2], ...}“小”，
是指存在 k >= 1 使得 A[i]=B[i] 对所有 i < k 成立，并且 A[k] < B[k]。
eg. 1 2 6 < 1 3 5 < 1 8 < 9

*/
int dmax[N]= {0}, dmin[N]={0}; //
int dp2(int s)//黑人问号.jpg
{
    if(s==0){
        return 0;
    }
    if(vis[s]) return dmin[s];
    vis[s]=1;
    int &ans=dmin[s];
    ans= 1<<20 ;//？？？.jpg
    for(int i=0; i<n; i++) if(s>=a[i])
    {
        ans = min(dp2(s-a[i])+1, ans);
    }
    return ans;
}
int dp1(int s)//黑人问号.jpg
{
    if(s==0){
        return 0;
    }
    int &ans=dmax[s];
    if(ans != -1) return dmax[s];

    ans= -1<<10;//？？？.jpg
    for(int i=0; i<n; i++) if(s>=a[i])
    {
        ans = max(dp1(s-a[i])+1, ans);
    }
    return ans;
}
void test_d(int *d)
{
    for(int i=0; i<=m; i++)
    {
        cout << d[i] << " ";
    }
}


void print_ans(int d[], int s){
    for(int i=0; i<n; i++)if(s>=a[i] && d[s] == d[s-a[i]]+1){
        printf("%d ", a[i]);
        print_ans(d, s-a[i]);
        break;
    }
}
void print_ans2(int d[], int s){
    while(s){
        printf("%d ", a[d[s]]);
        s -= a[d[s]];
    }
}
/*
定义：d(i,j) 表示第i,i+1,i+2,…,n个硬币组合为j的价值
d(i,j) = max{d(i+1, j), d(i+1, j-a[i]) + 1}
边界是i=n-1时 j==0;
则答案为d(0,m);
*/
int cnt=0, maxpath[N][M]={0};//O(n*m)
int dynamicPlanning(int i, int j){
    int &ans = maxpath[i][j];
    if(j == 0){
        f=1;
        return 0;
    }else if( i==n){
        return -1<<20;
    }else{
        for(; i<n; i++){
            cnt++;
            if(j >= a[i]){
                int i1= dynamicPlanning(i+1, j);
                int i2= dynamicPlanning(i+1, j-a[i])+1;
                if(i1 > i2){
                    ans = 0;
                }
                else
                    ans = i;//选了i;
                return max(i1, i2);
            }
            else
                return -1<<20;
        }
    }
    return 0;
}
void dis_twoDim(int fd[][M], int n, int m){
    cout << "   ";
        for(int j=1; j<=m; j++)
            cout << j << " ";
        cout <<endl;
    for(int i=0; i<n; i++) {
             cout << i<< ": ";

        for(int j=1; j<=m; j++){
            cout << fd[i][j]<< " ";
        }cout << endl;
    }
}
int fd[N][M]={0};

int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n >> m;
    for(int i=0; i<n; i++){        cin >> a[i];    }
    sort(a, a+n);
//    dis(a); //test

/*trace
    vector<int> res;
    dongTai(0,res);
    if(f)
        dis(res);
    else
        cout << "No Solution";
*/

/*硬币无限数量下求最大消耗硬币数 的递归
  memset(dmax, -1, sizeof(dmax));
    dp1(m);
	memset(dmin, -1, sizeof(dmin));
    dp2(m);
    test_d(dmax);
    cout << "max" << endl;
    test_d(dmin);
*/
/*无限
    for(int i=1; i<=m; i++) { dmin[i] = 1<<10; dmax[i] = -1<<10;}
    int min_coin[N]={0}, max_coin[N]={0};
    for(int i=1; i<=m; i++){
        for(int j=0; j<n; j++){
            if(i >= a[j]){
//                dmax[i] = max(1 +dmax[i-a[j]] , dmax[i]);//求最大路
//                dmin[i] = min(1 +dmin[i-a[j]] , dmin[i]);
                if(1 +dmax[i-a[j]] > dmax[i]){
                    dmax[i] = 1 +dmax[i-a[j]] ;
                    max_coin[i] = j;
                }
                if(1 +dmin[i-a[j]] < dmin[i]){
                    dmin[i] = 1 +dmin[i-a[j]];
                    min_coin[i] = j;
                }
            }
        }
    }
    test_d(dmax);cout <<"test_dmax" << endl;

    test_d(dmin);cout <<"test_dmin" << endl;

//    print_ans(dmax, m);循环
//    print_ans(dmin, m);
    print_ans2(max_coin, m);
    print_ans2(min_coin, m);
*/

//    cout << dynamicPlanning(0, m)<<endl;
//    cout << cnt << " "<<f << endl;
    //O(n*m) f[0][m];
/*d(i,j) = max{d(i+1, j), d(i+1, j-a[i]) + 1}*/
//    for(int i=n-1; i>=0; i--) {
//        for(int j=a[i]; j<=m; j++){
//            fd[i][j] = i==n-1? 0 : fd[i+1][j];
//            if(fd[i][j] < fd[i+1][j-a[i]]+1){
//                choice[i][j] = true;
//                fd[i][j] = fd[i+1][j-a[i]]+1;
//            }
//        }
//    }
//    cout << fd[0][m]<<endl;
/*d(i,j) = max{d(i-1, j), d(i-1, j-a[i]) + 1}  答案为 d(n, m)
才发现这个定义是 在价值<m的情况下的最大硬币数
本题应该是 价值=m的情况下的 字典序最小的最大硬币数
*/
    for(int i=0; i<n; i++) {
        for(int j=a[i]; j<=m; j++){
            fd[i][j] = (i==0?0:fd[i-1][j]);
            if(fd[i][j] < fd[i-1][j-a[i]]+1)
                fd[i][j] = fd[i-1][j-a[i]]+1;
        }
    }
    cout << fd[n-1][m]<<endl;
    dis_twoDim(fd, n, m);
    return 0;
}
void dongTai(int curV, vector<int> &res) //这是 有限的硬币问题。 回溯法的解法。
{
    if(curV == m)
        f=true;
    else
    {
        for(int i=0; i<n; i++)
        {
            if(!vis[i] && a[i]+curV <= m) //有点像生成全排列。。3月22日 13:57
            {
                vis[i] = true;//嘿，以前的我你咋那么聪明 2018.3.26 T(n) = O(n!)
                res.push_back(a[i]);
//                dis(res);
                dongTai(a[i]+curV, res);
                if(f)
                {
                    break;
                }
                vis[i] = false;
                res.erase(res.end()-1);
            }
        }
    }
}

void dis(vector<int> a)
{
    for(int i=0; i<a.size()-1; i++)
    {
        cout << a[i]<<" ";
    }
    cout << a[a.size()-1]<<endl;
}
