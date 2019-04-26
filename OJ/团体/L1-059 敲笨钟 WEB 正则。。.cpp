#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int N;
    cin >> N;
    getchar();  //cin完再使用getline,一定要记得吃回车
    while(N--)
    {
        string str;
        getline(cin,str);
        if(regex_match(str,regex(".*ong,.*ong\\.")))  //对字符串进行模式匹配,true为匹配成功
        {
            cout << regex_replace(str, regex("[[:alpha:]]* [[:alpha:]]* [[:alpha:]]*\\."),"qiao ben zhong.") << endl;
        }
        else
        {
            cout << "Skipped" << endl;
        }
    }
    return 0;
}
