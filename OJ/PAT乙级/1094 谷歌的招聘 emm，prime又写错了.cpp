#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e8;
const int N=3e5+5, L=1e4+5;

#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)


//vector<int> a(N);
//vector<int> maps[N];
//int maps[N][N]= {0}, target[N][N]= {0};
//int vis[N][N]= {0};
//int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int mod = 998244353;
int n,m,t,k;
int a[N]= {0}, vis[N];

//int stoi(string s){
//    stringstream ss;
//    ss << s;
//    int res;
//    ss >> res;
//    return res;
//}
bool isprime(int n){
    if( n < 2)
        return false;
    _for(i,2,sqrt(n)+1   ){
        if(n%i == 0){
            return false;
        }
    }
    return true;

}
bool isPrime(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
int main(){
//    freopen("1.txt", "r", stdin);
    int L, k;
    bool findFlag=false;
    string str;
    scanf("%d %d", &L, &k);

    cin >> str;
//    k 4
//    L 5
//    2
//    i=4, i=5?
    int j=0;
    _for(i,k,L+1){

        string sub = str.substr(j,k);
//        cout << sub << endl;
        n = stoi(sub);
        if(isprime(n)){
            findFlag=1;
            cout << sub << endl;
            break;
        }

        j++;
    }

    if(!findFlag)
        printf("404\n");

    return 0;
}
