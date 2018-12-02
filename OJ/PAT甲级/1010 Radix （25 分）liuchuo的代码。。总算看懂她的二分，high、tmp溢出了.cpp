#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;
//int a[36];

long long get_dem_by_str_rad(string a, long long radix){

    long long res=0;
    int c = 0, t;
    for(auto i=a.rbegin(); i!=a.rend(); i++){
        if( *i<='9' && *i>=0){
            t = *i-'0';
        }else {
            t = *i- 'a' + 10;
        }
        res += t * pow(radix, c++);
    }
    return res;
}
long long find_red(string a, long long tag){
    long long res=0;

    char lowCh = *max_element(a.begin(), a.end());
    long long low = (isdigit(lowCh) ? lowCh-'0' : lowCh - 'a'+10 ) + 1;
    long long high =  max(low,tag);//比如说10进制, high=9, low=10这就尴尬了...

    while(low<=high){
        long long mid = (low+high)/2;

        long long temp = get_dem_by_str_rad(a,mid);
        /*
        cout<<"mid = "<<mid<<endl;
        cout<<"temp = "<<temp<<endl;
        cout<<"low = " <<low<<endl;
        cout<<"high = "<<high<<endl;
        */
        if(temp<0||temp>tag){//溢出了
            high = mid - 1;
        }else if(temp<tag){
            low = mid + 1;
        }else{
            res = mid;
            break;
        }
    }
    return res;
}
int main()
{
//    printf("%f", 1.545e-2);

    freopen("1.txt", "r", stdin);
    string n1 , n2;
    int tag, radix;
    long long f=1;
    cin >> n1 >> n2>> tag>> radix;
//    for(int i=0; i<36; i++)
//        a[i]=i;
    if(tag==2){
        swap(n1, n2);
    }

    long long a = get_dem_by_str_rad(n1, radix);
    f = find_red(n2, a);

    if(f != 0){
        cout << f;
    }else{
        cout << "Impossible";
    }
    return 0;
}
