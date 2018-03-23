#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int f[10005]= {0};//not init
bool vis[10005]= {0};
int find(int i){
    return f[i]==i ? i : f[i] = find(f[i]);
}
void Union(int a, int b){
    a =find(a);
    b = find(b);
    if(a != b){
        f[a] = b;
    }
}
int main()
{
    freopen("1.txt", "r", stdin);
    int n, tn, t;
    cin >> n;
    for(int i=0; i<10005; i++)
        f[i] =i;
    for(int i=0; i<n; i++)
    {
        cin >> tn;
        int max=0;

        vector<int> array(tn);
        for(int j=0; j<tn; j++)
        {
            cin >> array[j];
            vis[array[j]]=1;
            if(array[j] > max){
                max=array[j];
            }
        }
        for(int j=0; j<tn; j++){
            Union(array[j], max);
//            f[array[j]] = max;
        }
    }
    set<int> res;
    int cnt=0;
    for(int i=0; i<10005; i++){
        t = find(i);
        if(vis[i]){
            res.insert(t);
            cnt++;
        }
    }
    cout << cnt << " "<<res.size()<< endl;

    cin >> n;
    int a,b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        a = find(a);
        b = find(b);
        if(a == b){
            cout << "Y"<< endl;
        }else
            cout << "N"<< endl;
    }

    return 0;
}
