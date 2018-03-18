#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> t){
    for(auto i : t){
        printf("%d ", i);
    }
    printf("\n");
}
int main()
{
    //freopen("1.txt", "r", stdin);

    int a, t;
    scanf("%d", &a);
    vector<int> min;
//    8 4 2 5 3 9 1 6 7
// 如果t没有大于所有队列的末尾 则找差距最小的队列，加入进去
// 如果t大于所有队列的末尾 则新加一个队列
    for(int i=0; i<a; i++)
    {
        int cha=a, ind=-1, n=min.size();
        scanf("%d", &t);
        for(int i=0; i< n; i++)
        {
            int t_cha = min[i]-t;
            if( t_cha > 0  &&  t_cha < cha)
            {
                ind = i;
                cha=t_cha;
            }
        }
        if(ind == -1)
        {
            min.push_back(t);
        }else{
            min[ind] = t;
        }
//        display(min);
    }
    cout << min.size();
    return 0;
}
