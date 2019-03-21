#include<bits/stdc++.h>
using namespace std;
#define N 2^20 //1048576
int n,m,a[1048576],ans;
int main()
{
    cin>>n>>m;
    int xx=(1<<m)-1;//定义变量所有位全为1
    for(int i=0; i<n; i++)
    {
        int  num=0,x;
        for(int j=0; j<m; j++)
        {
            cin>>x;
            num=num*2+x; //转换成十进制
        }
        ans+=a[xx^num]; //当前num与xx异或，表示当前num和xx^num组成一队完全相反的数，累加到ans上
        a[num]++;		//当前num个数+1
    }
    cout<<ans<<endl;
    return 0;
}
