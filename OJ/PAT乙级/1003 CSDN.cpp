#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
int main()
{
   // freopen("C:\\Users\\Public\\code\\datain.txt","r",stdin);
    int count_a,count_p,count_t,pos_p,pos_t;
    int n;
    char str[101];
    while(~scanf("%d",&n)){
        while(n--){
            scanf("%s",str);
            count_a=count_p=count_t=pos_p=pos_t=0;
            int m=strlen(str);
            for(int i=0;i<m;i++){
                if(str[i]=='P'){
                    count_p++;
                    pos_p=i;
                }
                else if(str[i]=='A'){
                    count_a++;
 
                }
                else if(str[i]=='T'){
                    count_t++;
                    pos_t=i;
                }
            }
            //cout<<"a"<<count_a<<endl<<"p"<<count_p<<endl<<"t"<<count_t<<endl<<"pos_p"<<pos_p<<endl<<"pos_t"<<pos_t<<endl;
 
            if(count_a+count_p+count_t!=m||count_a!=m-2||pos_t<=pos_p+1||pos_p*(pos_t-pos_p-1)!=m-1-pos_t)
                printf("NO\n");
            else
                printf("YES\n");
        }
 
    }
    return 0;
}
