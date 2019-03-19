#include<cstdio>
//#include<cstdio>
const int MAX=1001;
int a[MAX];
int lis(int x)
{
    int num[MAX];
    for(int i=0;i<x;i++)
    {
        num[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i]&&num[j]+1>num[i])
                   num[i]=num[j]+1;
        }
    }
    int maxx=0;
    for(int i=0;i<x;i++)
        if(maxx<num[i])
            maxx=num[i];
    return maxx;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    return !printf("%d\n",lis(n));
}

const int MAX=1001;
int a[MAX];
int lis(int x)
{
    int num[MAX];
    for(int i=0;i<x;i++)
    {
        num[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i]&&num[j]+1>num[i])
                   num[i]=num[j]+1;
        }
    }
    int maxx=0;
    for(int i=0;i<x;i++)
        if(maxx<num[i])
            maxx=num[i];
    return maxx;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    return !printf("%d\n",lis(n));
}
