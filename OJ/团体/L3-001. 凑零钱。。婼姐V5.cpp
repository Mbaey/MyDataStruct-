#include <cstdio>
#include <vector>
#include <algorithm>
#include<cstring>
#include <iostream>
using namespace std;
int dp[10010];
int w[10010];
bool choice[10010][10010];
int cmp1(int a, int b){return a > b;}
int main() {
    int n, m;
	freopen("1.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    sort(w + 1, w + n + 1, cmp1);
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= w[i]; j--) {
            //define d[i][j] = max{d[i-1][j], dp[i-1][j-w[i]] + w[i]}
            //d[i][j]表示把前i个物品装入容量为j的背包 时的最大V
            if(dp[j] <= dp[j-w[i]] + w[i]) {
                choice[i][j] = true;
                dp[j] = dp[j-w[i]] + w[i];
            }
        }
    }
    if(dp[m] != m) printf("No Solution");
    else {
        vector<int> arr;
        int v = m, index = n;
        while(v > 0) {
            if(choice[index][v] == true) {
                arr.push_back(w[index]);
                v -= w[index];
            }
            index--;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", arr[i]);
        }
    }
    return 0;
}
