#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<cstdio>
#include<stdlib.h>
using namespace std;

const int N=1005;
int  n, a[N];



int main()
{
    freopen("1.txt", "r", stdin);
    while(cin >> n){
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int maxLen=-1;
        for(int i=n-1; i>=2; i--){
            if(a[i]< a[i-1] + a[i-2]){
                maxLen  =a[i] + a[i-1] + a[i-2];
                break;
            }
        }
        printf("%d\n", maxLen);
    }

    return 0;
}
/*

*/
