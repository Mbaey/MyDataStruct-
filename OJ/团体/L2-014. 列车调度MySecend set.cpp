#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
void display(set<int> t){
    for(auto i : t){
        printf("%d ", i);
    }
    printf("\n");
}
int main()
{
   // freopen("1.txt", "r", stdin);

    int a, t;
    scanf("%d", &a);
    set<int> min;
//    8 4 2 5 3 9 1 6 7
// 如果t没有大于所有队列的末尾 则找差距最小的队列，加入进去
// 如果t大于所有队列的末尾 则新加一个队列
    for(int i=0; i<a; i++)
    {
        scanf("%d", &t);
        for(set<int>::iterator  i=min.begin(); i != min.end(); i++)
        {
            if(*i>t){
                min.erase(*i);

                break;
            }
        }
        min.insert(t);
//        display(min);
    }
    cout << min.size();
    return 0;
}
