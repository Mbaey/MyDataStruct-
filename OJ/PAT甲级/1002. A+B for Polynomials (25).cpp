#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
struct poly{
    int k; //2.5a·½ k=2 nk=2.5
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
    int i,j;
    for(i=j=0; i<n1&&j<n2; ){
        if(p[i].k > q[j].k){
            r.push_back(poly(p[i].k, p[i].nk));
            i++;
        }else if(p[i].k < q[j].k){
            r.push_back(poly(q[j].k, q[j].nk));
            j++;
        }else{
            if( p[i].nk + q[j].nk != 0)
            r.push_back(poly(p[i].k, p[i].nk + q[j].nk));
            i++;j++;
        }
    }
    while(i<n1){
        r.push_back(poly(p[i].k, p[i].nk));
        i++;
    }
    while(j<n2){
        r.push_back(poly(q[j].k, q[j].nk));
        j++;
    }
    cout << r.size();
    for(auto it : r){
        printf(" %d %.1f", it.k ,it.nk );
    }
    return 0;
}
