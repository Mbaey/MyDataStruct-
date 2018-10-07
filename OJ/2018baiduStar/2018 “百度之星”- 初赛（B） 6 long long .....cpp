#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
using namespace std;

const int N=10002;


struct P{
    int x,y;
};
bool cmp(P a, P b){
    return a.x<b.x;
}
int main()
{
    freopen("1.txt", "r", stdin);
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int nx, my, k;
//        cin >> nx >> my>>k;
         scanf("%d %d %d", &nx, &my, &k);
//        P pit[k];
        int x[4];
        long long res=0;
        for(int i=0; i<k; i++){
//            scanf("%d %d", &pit[i].x, &pit[i].y);
            scanf("%d %d", &x[0], &x[1]);
//            x[0]=pit[i].x;
//            x[1]=pit[i].y;
            x[2]=nx-x[0];
            x[3]=my-x[1];
            sort(x, x+4);
            res+=x[0];
        }
        cout<< res<<endl;
//        sort(pit, pit+n, cmp);

//        for(int i=0; i<k; i++){
//
//        }
    }

    return 0;
}
