#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
struct Peo
{
    string name;
    set<int> zan;
    int cnt=0;//¼ÇÂ¼ÖØ¸´

};
bool cmp(Peo p1, Peo p2){
    if(p1.zan.size()!=p2.zan.size())
       return p1.zan.size()>p2.zan.size();
    else{//may be wrong
        return p1.cnt< p2.cnt;
    }
}
int main()
{
    freopen("1.txt", "r", stdin);
    int n, t, tag;
    cin >> n;
    Peo peos[105];
    for(int i=0; i<n; i++)
    {
        cin >> peos[i].name;
        cin >> t;
        for(int j=0; j<t; j++)
        {
            cin >> tag;
            if(!peos[i].zan.empty() &&peos[i].zan.count(tag)){//faster
                peos[i].cnt++;
            }
            peos[i].zan.insert(tag);
        }
    }
    sort(peos, peos+n, cmp);
    if(n >= 3)
    {
        for(int i=0; i<2; i++)
        {
            cout << peos[i].name<<" ";
        }
        cout << peos[2].name;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            cout << peos[i].name<<" ";
        }
        for(int i=0; i<2-n; i++)
        {
            cout << "-"<<" ";
        }
        cout << "-";

    }


    return 0;
}
