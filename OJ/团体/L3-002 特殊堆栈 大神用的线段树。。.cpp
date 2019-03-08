#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<sstream>
#include<cstring>
#include<bitset>
#include<string>
#include<deque>
#include<stack>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define LC(x) (x<<1)
#define RC(x) ((x<<1)+1)
#define MID(x,y) ((x+y)>>1)
typedef pair<int,int> pii;
typedef long long LL;
const double PI=acos(-1.0);
const int N=1e5+10;
struct seg
{
    int l,mid,r;
    int cnt;
};
seg T[N<<2];
void pushup(int k)
{
    T[k].cnt=T[LC(k)].cnt+T[RC(k)].cnt;
}
void build(int k,int l,int r)
{
    T[k].l=l;
    T[k].r=r;
    T[k].mid=MID(l,r);
    T[k].cnt=0;
    if(l==r)
        return ;
    build(LC(k),l,T[k].mid);
    build(RC(k),T[k].mid+1,r);
    pushup(k);
}
void update(int k,int x,int val)
{
    if(T[k].l==T[k].r&&T[k].l==x)
        T[k].cnt+=val;
    else
    {
        if(x<=T[k].mid)
            update(LC(k),x,val);
        else
            update(RC(k),x,val);
        pushup(k);
    }
}
int query(int rt,int k)
{
    if(T[rt].l==T[rt].r)
        return T[rt].r;
    else
    {
        if(k<=T[LC(rt)].cnt)
            return query(LC(rt),k);
        else
            return query(RC(rt),k-T[LC(rt)].cnt);
    }
}
int st[N];
int main(void)
{
    int n,top,val;
    char ops[15];
    while (~scanf("%d",&n))
    {
        top=0;
        build(1,1,N-5);
        while (n--)
        {
            scanf("%s",ops);
            if(ops[1]=='o')
            {
                if(!top)
                    puts("Invalid");
                else
                {
                    update(1,st[top-1],-1);
                    printf("%d\n",st[top-1]);
                    --top;
                }
            }
            else if(ops[1]=='u')
            {
                scanf("%d",&val);
                update(1,val,1);
                st[top++]=val;
            }
            else if(ops[1]=='e')
            {
                if(!top)
                    puts("Invalid");
                else
                    printf("%d\n",query(1,(top+1)>>1));
            }
        }
    }
    return 0;
}
