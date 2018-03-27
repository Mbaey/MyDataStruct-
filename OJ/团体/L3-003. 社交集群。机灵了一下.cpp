#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define N 2005
#define C 1005
int f[N]={0}, cnt[N]={0};
int find(int i){
    return i==f[i]? i: f[i] = find(f[i]);
}
void Union(int a, int b){
    a= find(a);
    b= find(b);
    if(a != b){//此处真是运气好， a是兴趣，b是人。 刚好让人变成了根（小的在上）
        f[a] = b;
    }
}
bool cmp(int a, int b){
    return a>b;
}
void dis(int a[], int s, int e){
    for(int i=s; i<e; i++){
        cout <<a[i] << " ";
    }
    if(e>=0){
        cout <<a[e];
    }
}
int main()
{
    for(int i=0; i<N; i++)
        f[i]=i;
    freopen("1.txt", "r", stdin);
    int n, k, like;
    cin >> n;
    for(int i=1; i<=n; i++){
        scanf("%d:", &k);
        for(int j=0; j<k; j++){
            cin >> like;
            Union(like+1000, i);//使性情与人分开。
        }
    }
//    dis(cnt, n+1); putchar('\n');
    //集群个数， 群内人数
    for(int i=1; i<=n; i++){
        int a = find(i);
//        cout << i<<":"<<a << endl;
        cnt[a]++;
    }

    sort(cnt, cnt+n+1, cmp);
    int count=0;
    for(int i=1; i<=n; i++){
        if(cnt[i])
            count++;
    }
    cout << count+1<< endl;
    dis(cnt, 0, count);



    return 0;
}

