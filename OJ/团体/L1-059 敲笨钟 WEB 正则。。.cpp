#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int N;
    cin >> N;
    getchar();  //cin����ʹ��getline,һ��Ҫ�ǵóԻس�
    while(N--)
    {
        string str;
        getline(cin,str);
        if(regex_match(str,regex(".*ong,.*ong\\.")))  //���ַ�������ģʽƥ��,trueΪƥ��ɹ�
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
