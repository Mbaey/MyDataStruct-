#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define N 105
int all[N]= {0}, res[N][11]= {0}, n;
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
        int cnt=0;
    while(id < all[n]*10)
    {
        for(int j=0; j<10; j++)
        {
            for(int i=0; i<n; i++)
            {
                if(all[i]+cnt < all[i+1]){
                    if(res[all[i]+cnt][j] == 0)
                        res[all[i]+cnt][j] = id++;
                    else
                        id++;
                }else if(all[i]+cnt < all[n]){
                    id++;
                }
            }
        }
//        out();
//        cout << cnt <<"             ****************************"<<endl;
        cnt++;
    }

    out();
    return 0;
}
