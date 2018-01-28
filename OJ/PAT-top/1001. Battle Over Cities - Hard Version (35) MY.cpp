#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
�Ҹ��˸о�����ͼ�������ͨ��-1
�����Ҽǵ���һ����Ȩ�ص� ����prim����
*/
int w[506][506] = {0}, vis[506]= {0}, cost[506]= {0};
int n, m, k;
void dfs(int j, int occupied){
    vis[j] = 1;
    for(int i=1; i<=n; i++){
        if(i!=occupied&& !vis[i] && w[j][i] != 0){
            dfs(i, occupied);
        }
    }
}

int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n >> m ;
    for(int i=0; i<m; i++){
        int a, b, wight, status;
        cin >>a >> b >> wight >> status;
        if(status == 1){
            w[a][b] = wight;
            w[b][a] = wight;
        }
    }
    for(int i=1; i<=n; i++){
        int cnt = -1, occupied=i;//��¼ ��ͨ��֧��-1��
//        cin >> occupied;
        fill_n(vis, n+1, 0);
        for(int j=1; j<=n; j++){
            if(!vis[j] && j != occupied){
                cnt++;
                dfs(j, occupied);
            }
        }
        cost[i] =  cnt;
    }
    int max=cost[1], max_index=1;
    for(int i=2; i<=n; i++){
        if(max <= cost[i]){
            max = cost[i];
            max_index = i;
        }
    }
    if(max == 0){
        cout << 0 ;
    }else{
        for(int i=1; i<max_index; i++){
            if(cost[i]== max){
                cout << i <<" ";
            }
        }
        cout << max_index;
    }
}
