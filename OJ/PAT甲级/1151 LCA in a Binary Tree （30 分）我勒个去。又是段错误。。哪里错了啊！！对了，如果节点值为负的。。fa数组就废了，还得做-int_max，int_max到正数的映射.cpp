#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N=10005;//ms
set<int> s;
int in[N]={0}, pre[N]={0};
long long fa[N];
int n,m;
void createFa(int l, int r, int left_in, long long father){//[l,r)
    if(l>=r) return;
    int root = pre[l];
    fa[root] = father;

    int left_count=0;
    for(int i=left_in; i<left_in+r-l; i++, left_count++){
        if(in[i] == root){
            break;
        }
    }
    createFa(l+1, l+left_count+1, left_in, root);
    createFa(l+left_count+1, r, left_in+left_count+1, root);
}
int main(){
	freopen("1.txt", "r" ,stdin);
    cin >>m>>n;
    for(int i=0; i<n; i++)
        cin>>in[i];
    for(int i=0; i<n; i++){
        cin>>pre[i];
        s.insert(pre[i]);
    }

    fill(fa, fa+N, LLONG_MAX);
    createFa(0, n, 0, LLONG_MAX);

	int u, v;
	for(int i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        if(!s.count(u) && !s.count(v)){
            printf("ERROR: %d and %d are not found.\n", u, v);
        }else if(!s.count(u)){
            printf("ERROR: %d is not found.\n", u);
        }else if(!s.count(v)){
            printf("ERROR: %d is not found.\n", v);
        }else{
            set<int> ufa;
            long long utmp = u, vtmp = v;
            while(utmp != LLONG_MAX){
                ufa.insert(utmp);
                utmp = fa[utmp];
            }
            if(ufa.count(v)){//
                printf("%d is an ancestor of %d.\n", v, u);
                continue;
            }
            while(vtmp != LLONG_MAX){
                if(vtmp == u){//
                    printf("%d is an ancestor of %d.\n", u, v);
                    break;
                }else if(ufa.count(vtmp)){
                    printf("LCA of %d and %d is %d.\n", u, v, (int)vtmp);
                    break;
                }
                vtmp= fa[vtmp];
            }
        }
	}
    return 0;
}
