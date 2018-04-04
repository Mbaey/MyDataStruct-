#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
/*
思路：就是模拟从每个队依次挑出一个人，模拟的时候就给其赋值
同时会记录当前是这个队的第几个人，如果超过这个队的人数就不再

赋值，如果最后只剩下一个队，那么编号就要依次加2.
https://blog.csdn.net/moonlighttlj/article/details/79777016
*/
using namespace std;
#define N 1005//原来是这里段错误。。
int all[N]= {0}, cntEach[N]= {0}, res[N][100]= {0}, n;
bool vis[N]= {0};//还是用标记法，标记每队是否凑满才行。。 以前那个确实太狭隘了， 缺乏泛型
void out()
{
    for(int i=1; i<=n; i++)
    {
        printf("#%d\n", i);
        for(int k=all[i-1]; k<all[i]; k++)
        {
            for(int j=0; j<10; j++)
            {
                if(j!=0)
                    printf(" ");

                printf("%d", res[k][j]);
            }
            printf("\n");
        }
    }
}
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin>>all[i];
        all[i] += all[i-1];
    }
    int id=1;
    int cnt=0,len=0;
    while(1)
    {
        for(int j=0; j<10; j++)
        {
            for(int i=0; i<n; i++)
            {
                if(all[i]+cnt < all[i+1]){
                    if(len < n-1){
                        res[all[i]+cnt][j] = id++;
                    }else{
                        res[all[i]+cnt][j] = id;
                        id+=2;
                    }
                        cntEach[i]++;
                }

                if(!vis[i] &&cntEach[i] == (all[i+1]- all[i])*10){
                    len++;
                    vis[i] = 1;
                }
            }
        }
        if(len == n){
            break;
        }
//        out();
//        cout << cnt <<"             ****************************"<<endl;
        cnt++;
    }

    out();
    return 0;
}
