#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include<algorithm>

using namespace std;
bool isP(int t){
    int i=2, j=sqrt(t)+1;
    for(; i < j; i++)
        if(t % i ==0)
            return false;
    return true;
}
const int N = 10005;
int tab[N]={0};
int s, n, m;
void in(){
    int t;
    scanf("%d", &t);
    int f=0;
    for(int i=0; i<s; i++){
        int k = (t + i*i) % s;
        if(tab[k]==0){
            tab[k] = t;
            f=1;
            break;
        }
    }
    if(!f){
        cout << t <<" cannot be inserted."<<endl;
    }
}

int sea(){
    int t;
    scanf("%d", &t);
    int cnt=0;
//https://en.wikipedia.org/wiki/Quadratic_probing#C_function_for_key_searching
    for(int i=0; i<=s; i++){
        int k = (t + i*i) % s;
        cnt++;
        if(tab[k]==0 || tab[k] == t){
            break;
        }
    }
    return cnt;
}
int main()
{
    freopen("1.txt", "r", stdin);

    cin >> s>>n>>m;

    while( !isP(s)) s++;

    while( n-- ) in();

    int sum=0, tm=m;
    while( tm-- ) sum += sea();

    printf("%.1f", sum*1.0 / m);
    return 0;
}
