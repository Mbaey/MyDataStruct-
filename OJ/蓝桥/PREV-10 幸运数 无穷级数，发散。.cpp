#include<iostream>
using namespace std;
const int L=1000050;
int a[L];
/*
��Ŀ��˼�ж�  û�����  "���ʣ�µ�����"  

ɾѡһ�βŲ���һ�������� 

����� ������ʱ�� 100��  ���ǲ�֪��  ����ȥAC��

��Ϊ����� p���� 1+1/2+1/3+...+1/n+... ��ɢ�����¾�ûֵ�ˡ� 
*/
void filter(int s,int e,int b[])  
{
    int k=s;            //  ��k����������
    int t=b[s];         //  ��k����������ֵ��
    for(int i=s;i<e;i++){
        if((i+1)%t){            //  �����������t�ı�������ɾ����
            b[k]=b[i];
            k++;
        }
    }
    if(t<e)
    	filter(s+1,e,b);     //  �ݹ����ɾ����
}
int main()
{
    int m,n,cnt=0;
    cin>>m>>n;
    for(int i=0;i<n;i++)
        a[i]=i*2+1;             //  ��������г�ʼ����
    filter(1,n,a);          //  ���1��n֮�����������
    for(int i=0;i<n;i++){
        if(a[i]>=n) break;
        if(a[i]>m) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
