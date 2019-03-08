#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
const int N=1e6+5, M=105;  // ﬁœﬁŒ°££®5°‹N,M°‹100£© “ªø™ º∂®“ÂN = 10 ¡À
const float INF = 1e20;
#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)

int n,m,k;

int P[N]= {0};
//vector<int> maps[N];
//int maps[N][M]= {0};
//int vis[N][M]= {0};

vector<int> s;
vector<int> st;
priority_queue<int> q;
string str;
void dis(vector<int> a){
    for(auto i : a)
        cout << i <<" ";
    cout << endl;
}

void peekMedian(){

    if(s.empty()){
        cout << "Invalid" << endl; return;
    }
    int l = s.size(), ind;
    if(l%2==1){//5 -> 2
        ind =l/2;
    }else{//4 -> 2 a[2]
        ind = l/2-1;
    }
    cout << st[ind] << endl;
    //∂—≈≈–Ú°¢øÏ≈≈°¢Õ∞≈≈–Ú°¢∂˛∑÷≈≈–Ú°¢œ£∂˚≈≈–Ú°£

//    for(auto i : s){
//        sum[i]++;
//    }
//    int cnt=0, pre;
//    _for(i, 0, N){
//        if(cnt > ind){
//            cout << pre<<endl;
//            return;
//        }
//        if(sum[i] != 0){
//            cnt += sum[i];
//            pre=i;
//        }
//    }
}

void pop(){
    if(s.empty()){
        cout << "Invalid" << endl; return;
    }

    cout << s.back() << endl;
    auto it = lower_bound(st.begin(), st.end(), s.back());
    st.erase(it);
    s.pop_back();
}

void push(int k){
    s.push_back(k);
    auto it = lower_bound(st.begin(), st.end(), s.back());
    st.insert(it, k);
}


int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n;
    _for(i,0,n){
        cin >> str;
        if(str=="Pop"){
            pop();
        }else if(str=="PeekMedian"){
            peekMedian();
        }else{
            cin >> m;
            push(m);
        }
//        dis(s);
    }

    return 0;
}
