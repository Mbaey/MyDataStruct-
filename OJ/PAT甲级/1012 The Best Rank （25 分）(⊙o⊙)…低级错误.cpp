#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
//#include <bais/>
#include<algorithm>
using namespace std;
struct stu{
    string id;
    int score[4];
    int ran[4]={0};
    char c[4]={'A', 'C', 'M', 'E'};
};
struct R{
    int r; char c;
};
int j;
bool cmp1(stu a, stu b){
    return a.score[j] > b.score[j];
}
void dis(stu S[], int n){
    printf("id A C M E\n");
    for(int i=0; i<n; i++){
        printf("%s %d %d %d %d\n", S[i].id.c_str(), S[i].score[0], S[i].score[1], S[i].score[2], S[i].score[3]);
    }
}
int main()
{
    freopen("1.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    stu S[n];
    map<string, R> res;
//    set<string> res;
//    char c[4]={'A', 'C', 'M', 'E'};
    stu tmp;
//  fill_n(tmp.ran, 4, 0);
//  tmp.c
    for(int i=0; i<n; i++){
        cin >> tmp.id >> tmp.score[1]>> tmp.score[2]>> tmp.score[3];
//        round
        tmp.score[0] = (tmp.score[1]+ tmp.score[2]+ tmp.score[3])/3.0;
        S[i]=tmp;
    }
    for(j=0; j<4; j++){
        sort(S, S+n, cmp1);
//        dis(S, n);
        S[0].ran[j] = 1;
        for(int i=1; i<n; i++){
            if(S[i].score[j]== S[i-1].score[j]){
                S[i].ran[j] = S[i-1].ran[j];//ÅÅÐò
            }else
                S[i].ran[j] = i+1;//ÅÅÐò
        }
    }
//    dis(S, n);
    R t;
    for(int i=0; i<n; i++){
        t.c='A'; t.r=S[i].ran[0];
        for(int j=1; j<4; j++){
            if(S[i].ran[j] < t.r){
                t.r=S[i].ran[j];
                t.c=S[i].c[j];
            }
        }
        res[S[i].id] = t;
    }

    string id;
    for(int i=0; i<m; i++){
        cin >> id;
        if(res.count(id)){
            //..
            cout << res[id].r <<" "<< res[id].c<< endl;
        }else{
            cout << "N/A"<< endl;
        }
    }

    return 0;
}
