#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int book[1005]={-1};
int main()
{
    freopen("1.txt", "r", stdin);
    int day, b, h, m;
    char ch, c;
    cin >> day;

    fill_n(book, 1005, -1);
    for(int i=0; i<day; i++){
        fill_n(book, 1005, -1);//额，，没有隔天借书的情况。。

        for(int &time_pre : book)
            if(time_pre != -1)
                time_pre -= 24 * 60;

        int cnt=0;
        long long res=0, time=0;
        while(cin >> b >> ch >> h>> c >> m){
            if(b==0){
                if(cnt >= 1){
                    res= floor(time / (float)cnt + 0.5);
                }
                cout << cnt <<" "<< res << endl;

                break;
            }

            if(ch=='E' && book[b]==-1){//only have E
                continue;
            }else if(ch=='E'){ //have too many S ，则最后一个是有效的。
                cnt++;
                time += 60*h+m - book[b];

                book[b] = -1; // reset!!
            }else if(ch=='S'){
                book[b] = 60*h+m;
            }
        }
    }

    return 0;
}
