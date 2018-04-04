#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define N 10005//原来是这里段错误。。
struct Stu{
    string name;
    int score;
    int rank;
}stus[N];

bool cmp(Stu a, Stu b){
    if(a.score != b.score)
        return a.score > b.score;
    else
        return a.name < b.name;
}
int n, g, k;
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n >>g >>k;
    int sum=0;
    for(int i=0; i<n; i++){
        cin >> stus[i].name >> stus[i].score;
        if(stus[i].score >= g){
            sum += 50;
        }else if(stus[i].score >= 60){
            sum += 20;
        }
    }

    cout << sum<< endl;
    sort(stus, stus + n, cmp);
    int cnt=2;
    stus[0].rank = 1;
    for(int i=1; i<n; i++){
        if(stus[i].score == stus[i-1].score  )
            stus[i].rank = stus[i-1].rank ;
        else
            stus[i].rank = cnt;

        cnt++;
    }

    for(int i=0; i<n; i++){
        if(stus[i].rank > k){
            break;
        }
        cout << stus[i].rank <<" "<< stus[i].name <<" "<< stus[i].score<< endl;
    }


    return 0;
}
