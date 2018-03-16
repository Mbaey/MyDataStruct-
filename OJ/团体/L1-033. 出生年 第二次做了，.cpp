#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
//#include <climits>
bool diff(int y,int n)
{
    int vis[10] = {0};
    if(y < 1000){
        vis[0]++;
    }
    int cnt = 0;
    while( y  != 0)
    {
        int c = y%10;
        y /=10;
        vis[c]++;
    }
    for(int i=0; i<10; i++)
    {
        if(vis[i] != 0)
        {
            cnt ++;
        }
    }
    return cnt == n;

}
using namespace std;
int main()
{
    freopen("1.txt", "r", stdin);

    int y, n;
    cin>>y>>n;
    for(int i=0; ; i++)
    {
        if(diff(y+i, n))
        {
            printf("%d %04d", i, y+i);
            return 0;
        }
    }
    return 0;
}
