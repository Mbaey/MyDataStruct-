#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define N (1<<20) + 1

int tree[N];
void BST(int a){
    int i=1;
    while(tree[i] != 0){
        if(a > tree[i]){
            i = i*2;
        }else{
            i = i*2+1;
        }
    }
    tree[i]=a;
}
int main()
{
    freopen("1.txt", "r", stdin);
    int n, t;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> t;
        BST(t);
    }
    int cnt=0;
    int i=1, floor=1;
    bool f=true;
    for(; i<N; ){

        bool last_fill=true;
        for(int j=1; j<=floor; j++, i++){
            if(tree[i] != 0){
                if(cnt++ != 0)
                    cout << " ";
                cout << tree[i];
            }else{
                last_fill=false;
            }
            if(cnt == n)    break;
        }
        if(!last_fill){
            f=false;
        }
        floor *=2;

        if(cnt == n)
            break;
    }
    cout << endl;
//    int max = pow(2,ceil(log2(n)));
    if(!f){
        cout << "NO";
    }else{
        cout << "YES";
    }
    return 0;
}
