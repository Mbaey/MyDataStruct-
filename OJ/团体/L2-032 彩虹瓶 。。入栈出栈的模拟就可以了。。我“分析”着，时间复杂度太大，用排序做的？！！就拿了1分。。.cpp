#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)
typedef long long ll;
const int N=1e4+5,M=105;

int n,m,k, cnt=0, tmp=0;

//vector<int> maps[N];
//int maps[N][N]; 81*4
int a[N]={0}, no[N]={0};

stack<int> st;
int s[2000];
int main() {
	freopen("1.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    while (k--) {
        while (!st.empty())st.pop();
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        int now = 1;
        int yes = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == now) {
                now++;
                while (st.empty()==false && st.top() == now) {
                    st.pop();
                    now++;
                }
            }
            else {
                st.push(s[i]);
                if (st.size() > m) {
                    yes = 0;
                }
            }
        }
        if (yes == 0 || st.size() > 0) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}
