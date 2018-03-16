#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <string>  
#include <algorithm>  
#include <cmath>  
#include <map>  
#include <set>  
#include <stack>  
#include <queue>  
#include <vector>  
#include <bitset>  
  
using namespace std;  
  
#define LL long long  
const int INF = 0x3f3f3f3f;  
  
struct node  
{  
    int a, nt;  
}x[100090];  
int s, n;  
int ans1[100090], ans2[100090];  
  
int main()  
{  
    while (~scanf("%d%d", &s, &n))  
    {  
        int a, xx, nt;  
        for (int i = 0; i < n; i++)  
        {  
            scanf("%d%d%d", &xx, &a, &nt);  
            x[xx].a = a, x[xx].nt = nt;  
        }  
        int cnt = 0;  
        while (s != -1)  
        {  
            ans1[cnt++] = s;  
            s = x[s].nt;  
        }  
        int cnt1 = 0,l=0,r=cnt-1;  
        while (l <= r)  
        {  
            if(l==r) ans2[cnt1++] = ans1[r--];  
            else  
            {  
                ans2[cnt1++] = ans1[r--];  
                ans2[cnt1++] = ans1[l++];  
            }  
        }  
        for (int i = 0; i < cnt-1; i++) printf("%05d %d %05d\n", ans2[i], x[ans2[i]].a, ans2[i+1]);  
        printf("%05d %d -1\n", ans2[cnt - 1], x[ans2[cnt-1]].a);  
    }  
    return 0;  
}  