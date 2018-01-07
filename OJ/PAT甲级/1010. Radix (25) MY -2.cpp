#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
//int a[36];

long long int  get_dem_by_str_rad(string a, int radix){
    long long int res=0;
    int c = 0, t;
    for(auto i=a.rbegin(); i!=a.rend(); i++){
        if( *i<='9' && *i>=0){
            t = *i-'0';
        }else {
            t = *i- 'a' + 10;
        }
        res += t*pow(radix, c++);
    }
    return res;
}
int find_max_radix(string a){
    int res=2;
    int c = 0, t;
    for(auto i=a.rbegin(); i!=a.rend(); i++){
        if( *i<='9' && *i>=0){
            t = *i-'0';
        }else {
            t = *i- 'a' + 10;
        }
        if(t>res){
            res = t;
        }
    }
    return res;
}
int main()
{

    freopen("1.txt", "r", stdin);
    string n1 , n2;
    int tag, radix, f=1;
    cin >> n1 >> n2>> tag>> radix;
//    for(int i=0; i<36; i++)
//        a[i]=i;
    if(tag==2){
        swap(n1, n2);
    }
    long long int  a = get_dem_by_str_rad(n1, radix);
    int max_r = find_max_radix(n2);
    for(int i=max_r; i<=360; i++){
        long long int b = get_dem_by_str_rad(n2, i);
        if(a==b){
            f=0;
            cout << i;
            break;
        }
    }
    if(f){
        cout << "Impossible";
    }
    return 0;
}
