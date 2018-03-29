#include<cstdio>
#include<cstring>
#include <iostream>
using namespace std;
#define maxv 10010
#define maxn 110
int n, C, v[maxn], f[maxn][maxv]={0};
void dis_twoDim(int fd[][maxv], int n, int m)
{
    cout << "   ";
    for(int j=1; j<=m; j++)
        cout << j << " ";
    cout <<endl;
    for(int i=0; i<=n; i++)
    {
        cout << i<< ": ";
        for(int j=1; j<=m; j++)
        {
            cout << fd[i][j]<< " ";
        }
        cout << endl;
    }
}
int main()
{
    freopen("1.txt", "r", stdin);
    scanf("%d %d",  &n, &C);
    for(int i = 1; i <= n; ++i) scanf("%d", v+i);
    /*
    f[i][j] = max ( f[i-1][j] ,f[i-1][j-v[i]] + 1)
        如果是定义f[i][j] 为第i个物品之前 背包最大容量v为j时 所能装的最大重量w。
        则初始化时 全为0
    for(int i = 1; i <= n; ++i){
        f[i][0] = 0;
        for(int j = C; j >= 1; --j)
        {
            f[i][j] = i == 1 ? 0 :f[i-1][j];
            if(j>=v[i] && f[i-1][j-v[i]] + 1>f[i][j]) f[i][j] = f[i-1][j-v[i]] + 1;
        }
    }

    */

    /*
    如果是定义f[i][j] 为第i个物品之前的所有物品 背包总容量v must为j时 所能装的最大重量w。
    则初始化时 全为 -inf f[i][0] = 0;
    这样j从c往1递推时，一开始都会为 -inf + 1， 只有符合条件的会变成 0 + 1;
    */
    fill(f[0], f[0]+maxn*maxv, -1<<10);
    for(int i = 0; i <= n; ++i)
        f[i][0] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = C; j >= 1; --j)
        {
            f[i][j] = i == 1 ? -1<<10 :f[i-1][j];
            if(j>=v[i] && f[i-1][j-v[i]] + 1>f[i][j]) f[i][j] = f[i-1][j-v[i]] + 1;
        }
    }
    /*现在还不会逆序打印*/
    dis_twoDim(f, n, C);
    printf("%d\n", f[n][C]);
    //while(1);
    return 0;
}

