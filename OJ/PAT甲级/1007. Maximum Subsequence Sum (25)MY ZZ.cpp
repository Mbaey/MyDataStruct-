#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    freopen("1.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> v(n);
    int max = INT_MIN, max_i = -1, max_j=-1;
    bool f=0;//都是负数
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(v[i] > 0){
            f=1;
        }
    }
    if(f==0){
        printf("0 %d %d", v[0], v[n-1]);
        return 0;
    }
    for(int i=0; i<n; i++){
        int cnt=0;
        for(int j=i; j<n; j++){
            cnt += v[j];
            if(cnt > max){
                max = cnt;
                max_i =i;
                max_j =j;
            }
        }
    }
    printf("%d %d %d", max, v[max_i], v[max_j]);

    return 0;
}
