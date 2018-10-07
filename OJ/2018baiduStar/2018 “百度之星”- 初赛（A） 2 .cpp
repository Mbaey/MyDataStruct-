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
//��11 uu ww valval �ڱ��Ϊ uu �Ķ��������һ��ȨֵΪ valval ��Ԫ�ء���w=0w=0 ��ʾ������ǰ�棬w=1w=1 ��ʾ��������棩��
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
//��22 uu ww ѯ�ʱ��Ϊ uu �Ķ������ĳ��Ԫ�ز�ɾ�������� w=0w=0 ��ʾѯ�ʲ�������ǰ���Ԫ�أ�w=1w=1 ��ʾ����棩
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
//��33 uu vv ww �ѱ��Ϊ vv �Ķ��С����ڡ����Ϊ uu �Ķ��е�����档w=0w=0 ��ʾ˳���
//������ vv �Ŀ�ͷ�Ͷ��� uu �Ľ�β����һ�𣬶���vv �Ľ�β��Ϊ�¶��еĽ�β��, w=1w=1 ��ʾ����ӣ��Ƚ����� vv ��ת����˳����ڶ��� uu ���棩���Ҹò�����ɺ󣬶��� vv ����ա�
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
