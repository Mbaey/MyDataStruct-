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

字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
*/
        if(out){
            printf("NO\n"); continue;
        }else if(s.find("PAT") != string::npos){//只有P、A、T，且有连续的
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
        if(t_pos-1<=p_pos){//P和T中间至少有一个A
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
