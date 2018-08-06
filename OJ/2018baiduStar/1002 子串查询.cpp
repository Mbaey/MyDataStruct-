#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

const int N=100005;
int t, n, q;
int l, r;
int c;
int a[26][N]={0};
string ss;

int main()
{
    freopen("1.txt", "r", stdin);
    scanf("%d", &t);
    for(int k=1; k<=t; k++){
        printf("Case #%d:\n", k);
        scanf("%d %d", &n, &q);
        //1. BF 直接超时
        // 2.DP define a[i][j] 表示 【i,j】的答案 数组开不下
        //3.https://blog.csdn.net/bobo1356/article/details/71105934 前缀和
        char cn;
        scanf("%c", &cn);
        for(int j=0; j<26; j++){
            a[j][0]=0;
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<26; j++){
                a[j][i] = a[j][i-1];
            }
            scanf("%c", &cn);
            a[cn-'A'][i]++;
        }
        for(int i=0; i<q; i++){
            scanf("%d %d", &l, &r);
            if(l==r){
                printf("1\n");
                continue;
            }
            for(int j=0; j<26; j++){
                int end=a[j][r];
                int begin=a[j][l-1];
                if(end - begin != 0){
                    printf("%d\n",end-begin);
                    break;
                }

            }
        }
    }
//    cout << CHAR_MAX;
    return 0;
}
/*
3
3 3
ABA
1 2
1 3
2 3
2 3
AB
1 1
1 2
2 2
4 3
DCBA
1 2
1 3
1 4
*/
