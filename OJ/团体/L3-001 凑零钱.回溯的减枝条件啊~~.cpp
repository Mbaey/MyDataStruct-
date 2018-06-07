#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
//��0/1��������
const int N=10005, M=31;
int w[N]={0}, v=0, n, m, cnt=0;
bool vis[N]={0}, flag=false;
void dis(int cnt){
    int c=0;
    for(int i=0; i<n; i++){
        if(vis[i] && ++c<cnt)
            cout << w[i]<<" ";
        else if(vis[i] && c==cnt)
            c = w[i];
    }

    cout << c<<endl;
}
bool leftIsNotEnough(int h){
    int sum=v;
    for(; h<n; h++){
        sum+=w[h];
    }
    return sum < m;
}
void backtrack(int h){
    if(v==m && h<=n){//�ɹ�������
        dis(cnt); flag=true; return;
    }
    if(h>=n || flag || leftIsNotEnough(h)) return;//ʧ�ܣ�����

    if(v+w[h] <= m && !flag){
        vis[h]=1; v+=w[h]; cnt++;
        backtrack(h+1);
        if(flag) return;
//        if(flag)
        vis[h]=0; v-=w[h]; cnt--;
    }
    if(v+w[h] > m ){//��֦
        return;
    }
    backtrack(h+1);
}

int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> w[i];
    }
    sort(w, w+n);

    backtrack(0);
    if(!flag)
//        dis(cnt);
//    else
        cout << "No Solution";
    return 0;
}
