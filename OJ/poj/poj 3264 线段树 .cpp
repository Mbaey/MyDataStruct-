//#include <bits/stdc++.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++) 
#define MY_MIN  99999999
#define MY_MAX  -99999999

typedef long long ll;

const int N=50050;
/*
线段树适用于和区间统计有关的问题。
比如某些数据可以按区间进行划分，
按区间动态进行修改，而且还需要按区
间多次进行查询，那么使用线段树可以
达到较快查询速度。
*/
int n,m, h;
int a[N];
struct CNode{
	int L,R; //区间起点和终点
	int nMin,nMax;//本区间里的最大最小值
	CNode * pLeft, * pRight;
};
int nMax, nMin;
CNode Tree[1000000];
int nCount = 0;
void BuildTree(CNode * pRoot, int L,int R)
{
    pRoot->L = L;
    pRoot->R = R;
    
    pRoot->nMin = MY_MIN;
    pRoot->nMax = MY_MAX;

    if ( L != R) {
        nCount ++;
        pRoot->pLeft = Tree + nCount;
        nCount ++;
        pRoot->pRight = Tree + nCount;
        BuildTree( pRoot->pLeft, L, ( L + R )/2);
        BuildTree( pRoot->pRight, (L + R) / 2 + 1,R);
    }
}
void Insert( CNode * pRoot , int i,int v)
{
    if( pRoot->L == i &&  pRoot->R == i ) {
        pRoot->nMin = pRoot->nMax = v;
        return;
    }
    pRoot->nMin = min(pRoot->nMin,v);
    pRoot->nMax = max(pRoot->nMax,v);
    if( i <= (pRoot->L + pRoot->R )/2 )
        Insert( pRoot->pLeft,i,v);
    else
        Insert( pRoot->pRight,i,v);
}
void Query(CNode * pRoot, int s, int e)
{
    if( pRoot->nMin >= nMin && pRoot->nMax <= nMax )//不存在 
        return;
    if( s == pRoot->L && e == pRoot->R) {
        nMin = min(pRoot->nMin,nMin);
        nMax = max(pRoot->nMax,nMax);
        return ;
    }
    if( e <=  (pRoot->L + pRoot->R) / 2 )//左区间 
        Query(pRoot->pLeft, s,e);
    else if( s >= (pRoot->L + pRoot->R) / 2 + 1)//右区间
        Query(pRoot->pRight, s,e);
    else {//查询区间，横跨两个儿子 
        Query(pRoot->pLeft, s,(pRoot->L + pRoot->R) / 2);
        Query(pRoot->pRight, (pRoot->L + pRoot->R) / 2 + 1 ,e);
    }
}
int main() {
	freopen("1.txt", "r", stdin);
	
	scanf("%d %d", &n, &m);
	nCount = 0;
    BuildTree(Tree,1,n);    
    
    for(int i = 1;i <= n;i ++ ) {
        scanf("%d",&h);
        Insert( Tree,i,h);
    }
    for(int i = 0;i < m;i ++ ) {
        int s,e;
        scanf("%d%d", &s,&e);
        nMax = MY_MAX;
        nMin = MY_MIN;
        Query(Tree,s,e);
        printf("%d\n",nMax - nMin);
    }
    	
	return 0;
}
