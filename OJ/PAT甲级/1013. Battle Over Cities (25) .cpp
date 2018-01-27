#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
�Ҹ��˸о�����ͼ�������ͨ��-1
�����Ҽǵ���һ����Ȩ�ص� ����prim����
*/
int w[1006][1006] = {0}, vis[1006]= {0};
int n, m, k;
void dfs(int j, int occupied){
    vis[j] = 1;
    for(int i=1; i<=n; i++){
        if(i!=occupied&& !vis[i] && w[j][i]==1){
            dfs(i, occupied);
        }
    }
}

int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n >> m >> k;
    for(int i=0; i<m; i++){
        int a, b;
        cin >>a >> b;
        w[a][b] = 1;
        w[b][a] = 1;
    }
    for(int i=0; i<k; i++){
        int cnt = -1, occupied=-1;//��¼����ͨ��֧����
        cin >> occupied;
        fill_n(vis, n+1, 0);
        for(int j=1; j<=n; j++){
            if(!vis[j] && j != occupied){
                cnt++;
                dfs(j, occupied);
            }
        }
        cout << cnt << endl;
    }
}
