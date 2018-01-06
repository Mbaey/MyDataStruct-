#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 65535*1024

using namespace std;
int N[105][105]={0}, count1=0;
int main()
{
    freopen("1.txt", "r", stdin);
    int n,m,id,k;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin >> id >> k;
        int t;
        for(int j=0; j<k; j++){
            cin >> t;
            N[id][t] = 1;
        }
    }
    int rear=0, front=0, que[105]={0}, first=1, leaf=1, level=0, lest=0;
    /*  lest总是指向访问层的最后一个结点在队列的位置  */

    que[rear++]=1;
    lest = rear;
    while(rear > front){
        int child=que[front++];
        for(int i=1; i<=n; i++){
            if(N[child][i] != 0){
                que[rear++] = i;
                leaf=0;
            }
        }
        if(leaf)
            count1++;
        leaf=1;

        if(lest == front){
            level++; lest = rear;
            if(first) first=0;
            else cout <<" ";

            cout << count1;
            count1=0;
        }

    }

    return 0;
}
