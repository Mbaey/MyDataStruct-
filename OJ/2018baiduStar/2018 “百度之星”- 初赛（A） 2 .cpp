#include<iostream>
#include<algorithm>
#include<cstring>
#include<list>
#include<cstdio>
#include<stdlib.h>
using namespace std;

const int N=150002;
int  n, q, Q;
int  u, v, w, val;


void read(int &x)
{
    char ch = getchar();
    x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >='0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
}
int main()
{
    //freopen("1.txt", "r", stdin);
    while (cin >> n >> Q)
    {
        list<int> deq[n+1];
        while(Q--)
        {
            //q = getchar()-'0';
            read(q);
            switch(q)
            {
//①11 uu ww valval 在编号为 uu 的队列里加入一个权值为 valval 的元素。（w=0w=0 表示加在最前面，w=1w=1 表示加在最后面）。
            case 1:
                read(u);
                read(w);
                read(val);
                if(w)
                {
                    deq[u].push_back(val);
                }
                else
                {
                    deq[u].push_front(val);
                }
                break;
//②22 uu ww 询问编号为 uu 的队列里的某个元素并删除它。（ w=0w=0 表示询问并操作最前面的元素，w=1w=1 表示最后面）
            case 2:
                read(u);
                read(w);
                if(deq[u].empty())
                {
                    printf("-1\n");
                    break;
                }
                else
                {

                    if(w)
                    {
                        val = deq[u].back();
                        deq[u].pop_back();
                    }
                    else
                    {
                        val = deq[u].front();
                        deq[u].pop_front();
                    }
                    printf("%d\n", val);
                }
                break;
//③33 uu vv ww 把编号为 vv 的队列“接在”编号为 uu 的队列的最后面。w=0w=0 表示顺序接
//（队列 vv 的开头和队列 uu 的结尾连在一起，队列vv 的结尾作为新队列的结尾）, w=1w=1 表示逆序接（先将队列 vv 翻转，再顺序接在队列 uu 后面）。且该操作完成后，队列 vv 被清空。
            case 3:
                read(u);
                read(v);
                read(w);

                if(w)
                {
                     while(!deq[v].empty()) {
                        deq[u].push_back(deq[v].back());
                        deq[v].pop_back();
                    }
//                    deq[v].reverse();
//                    deq[u].merge(deq[v]);
                }
                else
                {
//                    deq[u].merge(deq[v]);
                    while(!deq[v].empty()) {
                        deq[u].push_back(deq[v].front());
                        deq[v].pop_front();
                    }
                }

                break;
            }

        }
//        printf("deq 2 size : %d", deq[2].size());
    }
    return 0;
}
/*

*/
