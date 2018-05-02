#include<cstdio>
#include<iostream>
#include<algorithm>


using namespace std;

const int N=100005, M=10000, inf = 1<<20; //10 6

int n, c;
struct P{
    int id, score;
    string name;
}p[N];
bool cmp(P a, P b){
    if(c==1){
        return a.id < b.id;    }else if(c==2){
        if(a.name != b.name)
            return a.name < b.name;
        else
            return a.id < b.id;
    }else{
        if(a.score != b.score)
            return a.score< b.score;
        else
            return a.id < b.id;
    }
}
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n>>c;
    char tmp[10]={0};
    for(int i=0; i<n; i++){
        scanf("%d %s %d", &p[i].id, tmp , &p[i].score);
        p[i].name = tmp;
//        cin >> p[i].id>> p[i].name>> p[i].score;
    }
    sort(p, p+n, cmp);
    for(int i=0; i<n; i++){
        printf("%06d %s %d\n", p[i].id, p[i].name.c_str() ,p[i].score);
    }
    return 0;
}
