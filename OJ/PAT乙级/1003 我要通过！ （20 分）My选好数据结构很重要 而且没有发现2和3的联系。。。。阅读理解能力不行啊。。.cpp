#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#define N 101

using namespace std;
int main()
{
//	char a[N];
	int n;
	freopen("1.txt", "r", stdin); //!!!!!!!!!
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
        bool out=false;

        string s;
        cin >>s;
        int p=0,t=0, len=s.length();
        for(auto c : s){
            if(c != 'P' && c!='A' && c!='T')
                out=1;
        }
        /*

�ַ����б������ P�� A�� T�������ַ��������԰��������ַ���
�������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a�� b�� c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
*/
        if(out){
            printf("NO\n"); continue;
        }else if(s.find("PAT") != string::npos){//ֻ��P��A��T������������
            printf("YES\n"); continue;
        }

        int p_pos=s.find("P");
        int t_pos=s.find("T");

        if(p_pos==string::npos || p_pos !=s.rfind("P")){//P=1
            out=true;
        }
        if(t_pos==string::npos || t_pos !=s.rfind("T")){//T=1
            out=true;
        }
        if(t_pos-1<=p_pos){//P��T�м�������һ��A
            out=true;
        }

        int a=p_pos, b = t_pos-p_pos-1, c=len-t_pos-1;



        if( !out && c == b*a){//2
            printf("YES\n");
        }else
			printf("NO\n");
	}

    return 0;
}
