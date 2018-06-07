#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
const int N=26;
int main()
{
    freopen("1.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int sum = pow((double)N, n);
    m = sum- m;
    string res;
    for(int i=0; i<n; i++){
        res += m%N+'a';
        m/=N;
    }
    for(auto i = res.rbegin(); i!= res.rend(); i++){
        cout << *i;
    }

    return 0;
}
