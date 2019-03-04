#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
const int N=1005;
#define _for(i,a,b) for(int i=a; i<b; i++)

int n,m,k;
int v,cnt=1;

int P[N]= {0};
//int maps[N]={0};
//vector<int> maps[N];

float maps[N][N]= {0};

int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n >> m;
    int t;
    _for(i,0,m)
    {
        scanf("%d", &k);
        //getline(cin, s);
        //s.split(" ");
        string s;
        vector<int> man,woman;
        _for(j,0,k)
        {
//            scanf("%s", &s);
            cin >> s;
            if(s[0] != '-')
            {
                man.push_back(stoi(s));
            }
            else{
//                string ss(s.begin()+1, s.end());
                woman.push_back(-stoi(s));
            }
        }
        float score=1.0/k;
        for(auto ii : man)
            for(auto jj : woman)
            {
                //f[jj][ii] += s;
                maps[ii][jj] += score;
            }

    }
    int a,b;

    string as,bs;
    cin >> as>>bs;
    bool isSwap=0;
    if(bs[0]=='-')
    {
        a=stoi(as);
        b=stoi(bs);
        swap(a,b); // f,m
        isSwap=1;
    }else{
        a=stoi(as);
        b=stoi(bs);
    }
    a = -a;


    vector<int> PA,PB;
    bool ab=0, ba=0;

    float max=0;
    _for(i,0,n)
    {
        if(maps[i][a]>max)
        {
            max=maps[i][a];
            PA.clear();
            PA.push_back(i);
        }
        else if(maps[i][a] == max)
        {
            PA.push_back(i);
        }
    }
    for(auto i : PA)
        if(i == b)
            ab=1;

    max=0;
    _for(i,0,n)
    {
        if(maps[b][i]>max)
        {
            max=maps[b][i];
            PB.clear();
            PB.push_back(i);
        }
        else if(maps[b][i] == max)
        {
            PB.push_back(i);
        }
    }
    for(auto i : PB)
        if(i == a)
            ba=1;

    if(!isSwap)
    {
        if(ab && ba)
        {
            printf("-%d %d\n", a, b);
        }
        else
        {
            for(auto i : PA)
                printf("-%d %d\n", a, i);
            for(auto i : PB)
                printf("%d -%d\n", b, i);

        }
    }else{//a b  m f
        swap(a,b);
        swap(PA,PB);
        if(ab && ba)
        {
            printf("%d -%d\n", a, b);
        }
        else
        {
            for(auto i : PA)
                printf("%d -%d\n", a, i);
            for(auto i : PB)
                printf("-%d %d\n", b, i);

        }

    }



    return 0;
}
