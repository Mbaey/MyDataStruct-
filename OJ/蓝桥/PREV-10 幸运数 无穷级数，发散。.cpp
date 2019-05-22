#include<iostream>
using namespace std;
const int L=1000050;
int a[L];
/*
题目意思有毒  没讲清楚  "最后剩下的序列"  

删选一次才产生一个幸运数 

这道题 铁定超时的 100万啊  但是不知道  交上去AC了

因为无穷级数 p级数 1+1/2+1/3+...+1/n+... 发散，几下就没值了。 
*/
void filter(int s,int e,int b[])  
{
    int k=s;            //  第k个幸运数；
    int t=b[s];         //  第k个幸运数的值；
    for(int i=s;i<e;i++){
        if((i+1)%t){            //  将所有序号是t的倍数的数删除；
            b[k]=b[i];
            k++;
        }
    }
    if(t<e)
    	filter(s+1,e,b);     //  递归进行删除；
}
int main()
{
    int m,n,cnt=0;
    cin>>m>>n;
    for(int i=0;i<n;i++)
        a[i]=i*2+1;             //  对数组进行初始化；
    filter(1,n,a);          //  求出1到n之间的幸运数；
    for(int i=0;i<n;i++){
        if(a[i]>=n) break;
        if(a[i]>m) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
