#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

void dis(vector<int> &res){
    for(int d : res)
        cout << "1/"<< d<< "+";
}
int main()
{
    freopen("1.txt", "r", stdin);
    int a=1, b, t;
    string s;
    cin >> b;
    while(a%b != 0){//除不尽 的话就加一位。

        t = a/b;
        a -= t*b;

        s += t+'0';
        a = a*10 + 1;
    }
    s+= a/b+'0';
    t = s.size();
    if(s.find_first_not_of('0') != string::npos)
        s.erase(s.begin(), s.begin()+ s.find_first_not_of('0'));
    cout << s<< " "<< t ;
    return 0;
}

