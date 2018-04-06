#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define N 2005//原来是这里段错误。。
int n, m, k;
double fri[N][N]={0};
int f[505]={0};
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n >>m;
    int a, b;
    while(m--){
        cin >> k;
        for(int i=0; i<k; i++){
                //没考虑 -0 的情况
            cin >> f[i];
        }
        for(int i=0; i<k; i++){
            for(int j=i+1; j<k; j++){
                a = f[i] + 1000;//min is -999
                b = f[j] + 1000;
                fri[a][b] += 1.0 / k;
                fri[b][a] += 1.0 / k;
            }
        }
    }
    cin >>a>>b;
    bool f=false;
    if(a<0){//f=0 a是男的
        f=true;
    }
    a+=1000; b+=1000;
//    for(int i=1000-n; i<1000+n; i++){
//        cout << i-1000 << "\t";
//        for(int j=1000-n; j<1000+n; j++){
//            cout << fri[i][j] <<" ";
//        }
//        cout << endl;
//    }
    double max=0;
    vector<int> PA;
    vector<int> PB;
    for(int i=1000-n; i<1000+n; i++){
        if(!f){//
            if(fri[a][i] > max){
                max = fri[a][i];
                PA.clear();
            }
            if(fri[a][i] == max){
                PA.insert(PA.begin(), i-1000);
            }
        }else{
            if(fri[b][i] > max){
                max = fri[b][i];
                PB.clear();
            }
            if(fri[b][i] == max){
                PB.insert(PB.begin(),i-1000);
            }
        }
        if(i==1000){
            max=0; f= !f;
        }
    }
    for(int i: PA){
        if(i == b-1000){
            for(int j: PB){
                if(j==a-1000){
                    printf("%d %d\n", a-1000, b-1000);
                    return 0;
                }
            }
        }
    }
    for(int i : PA){
        printf("%d %d\n", a-1000, i);
    }
    for(int i : PB){
        printf("%d %d\n", b-1000, i);
    }

    return 0;
}
