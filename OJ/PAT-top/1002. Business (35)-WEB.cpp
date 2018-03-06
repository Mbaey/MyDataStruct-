#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

struct sion
{
    int v, c, d;
}a[100];

int cmp(sion a, sion b)
{
    if(a.d!= b.d)
        return a.d < b.d;
    else 
        return a.c < b.c;
}


int dp[55][100000];
int main()
{
    int n;
    int sum ,ma ;
    while(cin >> n)
    {
        sum = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i].v >> a[i].c>> a[i].d;
            sum += a[i].c;
            dp[i][0] = 0;    
        }
        sort(a + 1, a + n + 1, cmp);
        ma = 0;
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++ )
        {
            for(int j = 1; j <= sum; j++)
            {
                if(j <= a[i].d)
                {
                    dp[i][j] = max(dp[i-1][j-a[i].c]+a[i].v, dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = a[i].v;
                }
                ma = max(ma, dp[i][j]);
            }
        }
        
        printf("%d\n", ma);
        
    }
}