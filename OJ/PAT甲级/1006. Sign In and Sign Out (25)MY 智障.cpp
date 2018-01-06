#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct time {
    int h,m,s;
};

struct peo
{
    string id;
    time s,e;
};

bool cmp1(peo a, peo b){
    if(a.s.h < b.s.h){
        return true;
    }else if( a.s.m < b.s.m){
        return true;
    }else if( a.s.s < b.s.s){
        return true;
    }
    return false;
}
bool cmp2(peo a, peo b){
     if(a.e.h > b.e.h){
        return true;
    }else if( a.e.m > b.e.m){
        return true;
    }else if( a.e.s > b.e.s){
        return true;
    }
    return false;
}

int main()
{
    freopen("1.txt", "r", stdin);
    int n;
    cin >> n;
    vector<peo> peolist;
    for(int i=0; i<n; i++){
        peo tp;
        string s, e;
        cin >> tp.id >> s >> e;
        sscanf(s.c_str(), "%d:%d:%d", &tp.s.h,&tp.s.m,&tp.s.s);
        sscanf(e.c_str(), "%d:%d:%d", &tp.e.h,&tp.e.m,&tp.e.s);
        peolist.push_back(tp);
    }
//    for(peo i : peolist)
//        cout << i.id << endl;
    sort(peolist.begin(), peolist.end(), cmp1);
    cout << peolist[0].id;
    sort(peolist.begin(), peolist.end(), cmp2);
    cout << " " <<  peolist[0].id;

    return 0;
}
