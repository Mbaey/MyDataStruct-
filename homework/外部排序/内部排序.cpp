#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <sstream>

using namespace std;
/*
 ������ں�2^15�η������ݵ��ļ�
 �ٶ��ڴ�Ϊ2^14�Σ�


*/
 string itos(int i)   // ��int ת����string
     {
         stringstream s;
         s << i;
         return s.str();
     }
int main()
{
    for(int i=1; i<=5; i++){
        string file = "in\\time" + itos(i)+ ".txt";
        vector<int> a(1<<14);
        freopen(file.c_str(), "r", stdin);
        for(int j=0; j< 1<<14; j++){
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        string file_out = "out\\R" + itos(i * 2 - 1);
        freopen(file_out.c_str(), "w", stdout);
        for(auto i : a){
            cout << i << " ";
        }

        //
        for(int j=0; j< 1<<14; j++){
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        file_out = "out\\R" + itos(i * 2);
        freopen(file_out.c_str(), "w", stdout);
        for(auto i : a){
            cout << i << " ";
        }

    }

    return 0;
}

