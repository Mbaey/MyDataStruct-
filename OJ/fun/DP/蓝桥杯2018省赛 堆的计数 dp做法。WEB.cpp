/*˼·������d[i]������ȫ������i��λ��Ϊ�����Ķ����ӶѸ�������������������Ҫ��n������������ȫ���������Ȼ���ڵ��Ѿ���ȷ����ֻ�ܷ���С�ģ�Ȼ������������Ľڵ����Ϊlsize����������Ҫ��n-1���ڵ���ѡ��lsize���ڵ������������ѡ��һ�������C(n-1,lsize)�֣�ʣ��ķ����������У�����d[i]=C(n-1,lsize)*d[i�������]*d[i���Ҷ���]��

ע�⣺���������Ҫ��logn���㷨,��iΪ���ڵ�����������ö�̬�滮�������s[i]=s[i�������]+s[i���Ҷ���];

���㷨��ʱ�临�Ӷ�O(nlongn),�ڱ����������10^5�£�����ʱ������ԣ�
---------------------
���ߣ�heyAmos
��Դ��CSDN
ԭ�ģ�https://blog.csdn.net/yinxiaobao97/article/details/84881317
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
*/
#include <iostream>
#include <cstdio>
#define _for(i,a,b) for(int i=a;i<b;i++)
#define _unfor(i,a,b) for(int i=a;i>=b;i--)
#define mset(a,val,n) for(int i=0;i<n;i++)a[i]=val;

using namespace std;
typedef long long LL;
//d[i] : ����ȫ������i��λ��Ϊ�����Ķ����ӶѸ���
//s[i] : ����ȫ������i��λ��Ϊ������ �����������еĽڵ�ĸ�����
LL d[100005],s[100005],mod=1000000009;
int n;
LL C(int m,int n)
{
    if(!n||!m)
        return 1;
    if(n==1)
        return m;
    return (C(m,n/2)*C(m-n/2,n-n/2)/2)%mod;
}

int main()
{
    cin>>n;
    _unfor(i,n,1)
    s[i]=(i*2<=n?s[i*2]:0)+((i*2+1)<=n?s[i*2+1]:0)+1; //s[i]<=n���Բ���ȡ��
    //��ʼ�������ڵ����
    mset(d,1,n+5);
    _unfor(i,n,1)if(i*2+1<=n)
        d[i]= ((C(s[i]-1,s[i*2+1])*d[i*2])%mod*d[i*2+1])%mod;
    cout<<d[1]<<endl;
}
