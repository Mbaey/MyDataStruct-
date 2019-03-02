#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
const int MAX=1005;

int main()
{
    freopen("1.txt", "r", stdin);
    int N, K;
    cin >> N;
//    cout <<INT_MAX;
    set<int> s[52];
    for(int i=1; i<=N; i++){
        int t; cin >> t;
            int tt;
        for(int j=0; j<t; j++){
            cin >> tt;
            s[i].insert(tt);
        }
    }
    cin >> K;

    for(int i=1; i<=K; i++){
        int a,b; cin >> a>>b;
//        union()
//        vector<int> all(100);
//        set_union(s[a].begin(), s[a].end(), s[b].begin(), s[b].end() , all.begin() );
//        set<int> all;
//        all.insert(s[a].begin(), s[a].end());
//        all.insert(s[b].begin(), s[b].end());

        float t=s[b].size();
        float c=0;
        for(auto j : s[a]){
            if(s[b].count(j)){
                c++;
            }else{
                t++;
            }
        }

        printf("%.2f%\n", c/t *100);
    }
    return 0;
}
