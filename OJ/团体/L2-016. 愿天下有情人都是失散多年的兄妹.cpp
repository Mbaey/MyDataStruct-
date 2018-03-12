#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int fa[100005]= {0} ,ma[100005]= {0};
map<int, char> peos;
void dfs(int root, int h, set<int> &res){
    if(h > 5 || root == 0 ){
        return;
    }
    res.insert(root);
    dfs(fa[root], h+1, res);
    dfs(ma[root], h+1, res);
}

void display(set<int> a){
    for(auto i : a){
        printf("%d ", i);
    }
    putchar('\n');
}

bool is_bs(int a, int b)//brother & sister
{
    set<int> b_p, a_p, c;
    dfs(a, 1, a_p);
    dfs(b, 1, b_p);
//    display(a_p);
//    display(b_p);
    set_intersection(a_p.begin(),a_p.end(), b_p.begin(), b_p.end(), inserter(c, c.begin()) );
//    display(c);
    if(c.empty()){
        return false;
    }
        return true;
}
int main()
{
    freopen("1.txt", "r", stdin);
    int n, id, m, f;
    char ch;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> id >> ch >> f >> m;
        peos[id]=  ch;
        if(f != -1){
            fa[id] = f;
            peos[f] = 'M';
        }
        if(m != -1){
            ma[id] = m;
            peos[m] = 'F';
        }
    }
    cin >> n;
    int id1;
    for(int i=0; i<n; i++)
    {
        cin >> id >> id1;
        if(peos[id] == peos[id1])
        {
            cout << "Never Mind" << endl;
        }
        else
        {
            if(is_bs(id, id1))
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
    return 0;
}
