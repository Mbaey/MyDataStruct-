#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
const int N=3002;
#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,b,a) for(int i=b-1; i>=a; i--)

int n,m,k;
int v,cnt=1;

int P[N]= {0};
//int maps[N]={0};
//vector<int> maps[N];

double  maps[N][N]= {0};
vector<double > a,b,q(N);//a b q r

int clearZero(vector<double > &out)
{
    int s = out.size();

    _ufor(i, s, 0)
    {
        if(fabs(out[i]) >= 5e-2)
        {
            s = i+1;
            break;
        }
    }
    out.resize(s);
//    s = out.size();
    int res=0;
    _ufor(i, s, 0){
        if(fabs(out[i]) < 5e-2)
            res++;
    }
    return res;

}
void dis(vector<double > out)
{
    int cnt = clearZero(out);
    int s = out.size();
    if(s-cnt==0)
    {
        cout << "0 0 0.0"<<endl;
        return;
    }
    cout << s-cnt;
    _ufor(i, s, 0)
    {
        if(fabs(out[i]) >= 0.05)
        {
            printf(" %d %.1f", i, out[i]);
        }
    }
    cout << endl;
}
int p;
double  w;
void input(vector<double > &poly)
{
    cin >> n;

    _for(j,0,n)
    {
//            scanf("%d %d", )
        cin >> p >> w;
        if(j==0)
        {
            poly.resize(p+1);
        }
        poly[p]=w;
    }
}
int main()
{
    freopen("1.txt", "r", stdin);

    input(a);
    input(b);

    int pa=a.size(), pb = b.size();

    int ql=pa - pb+1;

    _ufor(i, ql,  0) // 11100 / 10
    {
        q[i] = a[i+pb-1] / b.back();
        _ufor(j, pb, 0){
            a[i+j] -= q[i]*b[j];
        }
    }

    dis(q);
    dis(a);

    return 0;
}
