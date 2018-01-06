#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
string itos(long i){
    stringstream ss;
    string res;
    ss << i;
    ss >>res;
    return res;
}
int main()
{
    freopen("1.txt", "r", stdin);
    string str;
    long cnt=0;

    cin >> str;
    int len=str.length();
    for(auto i=0; i < len; i++){
        cnt += str[i] - '0';
    }


    str = itos(cnt);
//    cout << str;
    len =  str.length();
    string s[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(auto i=0; i < len; i++){
        if(i!=0)
            cout << " ";
        cout<< s[str[i] - '0'];
//        switch(str[i]){
//            case '0':cout << "zero"; break;
//            case '1':cout << "one"; break;
//            case '2':cout << "two"; break;
//            case '3':cout << "three"; break;
//            case '4':cout << "four"; break;
//            case '5':cout << "five"; break;
//            case '6':cout << "six"; break;//            case '7':cout << "seven"; break;//            case '8':cout << "eight"; break;
//            case '9':cout << "nine"; break;
//        }
    }
//    cout << str << endl;

    return 0;
}
