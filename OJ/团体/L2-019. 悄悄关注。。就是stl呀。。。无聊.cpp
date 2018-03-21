#include <cstdio>
#include <iostream>
#include <set>
#include <map>
using namespace std;
int n,m;
set<string> cares;
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n;
    string t;
    for(int i=0; i<n; i++){
        cin >> t;
        cares.insert(t);
    }
    cin >> m;
    long sum=0, zan;
    map<string, int> favour;
    for(int i=0; i<m; i++){
        cin >> t >> zan;
        if(!cares.count(t)){// can be faster
            favour[t] = zan;
        }
        sum += zan;
//        cout << zan <<" " << sum<<endl;
    }
    float z = sum / (float) m;
    bool f = false;
    for(auto i=favour.begin(); i != favour.end(); i++){
        if( (*i).second > z){//bug
            f=true;
            cout << (*i).first << endl;
//            cout << (*i).first <<"     "<< (*i).second << "   "<< z<< endl;
        }
    }
    if(!f){
            cout << "Bing Mei You"<< endl;
    }
    return 0;
}
