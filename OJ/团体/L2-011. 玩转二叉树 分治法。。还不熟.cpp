#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
//#include <climits>

using namespace std;
int lch[31]={0}, rch[31]={0}, pre[31]={0}, in[31]={0};
int get_index(int data, int a[], int n){
    for(int i=0; i<n; i++){
        if(a[i]==data)
            return i;
    }
    return -1;
}
int creat_tree(int l1, int r1, int l2, int r2){//L1,R1是指in   L2,R2是指pre 分治法
    if(l1 > r1) return 0;
    int root = pre[l2];
    int p = l1;
    while(in[p] != root)   p++;
    int cnt = p-l1;//左子树有cnt个孩子
    lch[root] = creat_tree(l1, p-1, l2+1, l2+cnt);
    rch[root] = creat_tree(p+1, r1, l2+cnt+1, r2);

    return root;
}
void bfs(int root){
    queue<int> Q;
    int temp;
    int flag = 0;
    Q.push(root);
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();

        if(flag)    cout<<" ";
        cout<<temp;
        flag = 1;

        if(rch[temp])   Q.push(rch[temp]);
        if(lch[temp])   Q.push(lch[temp]);
    }
    cout<<endl;
}
int main()
{
    freopen("1.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> in[i];
    for(int i=0; i<n; i++) cin >> pre[i];
    //构造树
    creat_tree(0,n-1,0,n-1);
    //翻转
    //反着输出
     bfs(pre[0]);

    return 0;
}
