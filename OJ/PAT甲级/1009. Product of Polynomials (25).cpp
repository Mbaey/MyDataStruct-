#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
struct poly{
    int k; //2.5a§Ú§Û k=2 nk=2.5
    float nk;
    poly(int a, float b):k(a),nk(b){}
};

int main()
{
    freopen("1.txt", "r", stdin);
    int n1, n2, a;
    float b;
    vector<poly> p, q, r;
    cin >> n1;
    for(int i=0; i<n1; i++) {
        cin >> a >> b;
        p.push_back(poly(a,b));
    }
    cin >> n2;
    for(int i=0; i<n2; i++) {
        cin >> a >> b;
        q.push_back(poly(a,b));
    }
//    int k[25];
    float nk[2005]={0};
    for(int i=0; i<n1; i++) {
         for(int j=0; j<n2; j++) {
            int tk = p[i].k + q[j].k;
            float tnk = p[i].nk * q[j].nk;
            nk[tk] +=  tnk;
         }
    }
    int cnt=0;
    for(auto i : nk ){
        if(i != 0){
            cnt++;
        }
    }
    cout << cnt;
    for(int i=2004; i>=0; i--){
        if(nk[i] != 0){
            printf(" %d %.1f", i, nk[i]);
//            cout << " " << i <<  " " << nk[i];
        }
    }

    return 0;
}
