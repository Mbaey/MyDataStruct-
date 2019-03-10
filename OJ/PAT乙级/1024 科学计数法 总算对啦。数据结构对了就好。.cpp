#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
const int N=10000 , M=105;  // 尴尬。（5≤N,M≤100） 一开始定义N = 10 了
const int INF = 1e8;
#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)

int n,m,k;

int a[N]= {0};
//vector<int> maps[N];
int maps[N][N]= {0};
//int vis[N][M]= {0};
struct Float{
    char posC;
    char str[N];
    int E;
}myF;

int main()
{
//    float ff = -1.2E+1000;

    freopen("1.txt", "r", stdin);
//+1.23400E-03
    char c; int len=1;
    myF.posC = getchar();
    myF.str[0] = getchar();
    c =getchar();// .
    while((c =getchar()) != 'E'){
        myF.str[len++] = c;
    }
    myF.str[len] = 0;

    scanf("%d", &myF.E);

    //output;
    if(myF.posC == '-')
        putchar('-');

    if(myF.E < 0){

        printf("0.");
        _for(i, 1, -myF.E)
            putchar('0');
        puts(myF.str);
    }else{
        if(myF.E >= len-1){
            printf("%s", myF.str);
            _for(i, 0, myF.E - len + 1)
                putchar('0');
        }else{
            _for(i, 0, myF.E + 1)
                putchar(myF.str[i]);
            putchar('.');
            _for(i, myF.E + 1,  len)
                putchar(myF.str[i]);
        }


    }






//    float i = stof(s);
//    int Epos = s.find("E");
//
//    int E = stoi(s.substr(Epos+1));//带 + - 的
//    int dot = Epos - 2;//带 + - 的
//    char fmt[10];
////    printf("%%.%df", E+dot-1);
////    cout << fmt << endl;
//    if(fabs(i - floor(i))>= 1e-8){//小数
//        sprintf(fmt,"%%.%df", abs(E)+dot-1);
//        printf(fmt, i);
//    }else{//整数
//        sprintf(fmt,"%%%d.f", E+dot-1);
//        printf(fmt, i);
//    }


    return 0;
}
