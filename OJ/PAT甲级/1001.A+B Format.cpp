#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
using namespace std;
string itos(int i){
    stringstream s;
    string str;
    s << i;
    s >> str;
    return str;
}
int main()
{
//    freopen("1.txt", "r", stdin);
    int a, b;
    cin >> a >> b;
    string s = itos(a+b);
    if(s[0] == '-'){
        cout << '-';
        s.erase(s.begin());
    }
    int l = s.length(), c=0;

    while(l != 1){
        l--;
        ++c;
        if(c%3==0){
            s.insert(l,",");

        }

    }
    cout << s  << endl;
    return 0;
}
