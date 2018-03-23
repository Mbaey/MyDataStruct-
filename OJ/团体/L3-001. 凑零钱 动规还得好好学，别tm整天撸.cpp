#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int a[10005];
bool vis[10005];
void dis(vector<int> a){
    for(int i=0; i<a.size()-1; i++){
        cout << a[i]<<" ";
    }

    cout << a[a.size()-1]<<endl;
}
bool dongTai(int curV, vector<int> &res){
    if(curV == m)
        return true;
    else{
        for(int i=0; i<n; i++){//有点像生成全排列。。
            if(!vis[i] && a[i]+curV <= m){
                vis[i] = true;
                res.push_back(a[i]);
//                dis(res);
                if(dongTai(a[i]+curV, res)){
                    return true;
                }
                vis[i] = false;
                res.erase(res.end()-1);
            }else if(!vis[i] && a[i]+curV > m){
                return false;
            }
        }
    }
    return false;
}
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
//    dis(a);
    vector<int> res;

    if(dongTai(0,res))
        dis(res);
    else
        cout << "No Solution";

    return 0;
}
