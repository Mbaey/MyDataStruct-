#include <bits/stdc++.h>
#include <sstream>
using namespace std;
#define _for(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int N=1e4+5,M=10, INF=1e9;

int n,m,k, tmp,len;

int a[N], vis[N];
//int maps[N][N];
//vector<int> maps[N];

struct line
{
    int x, y1, y2;//y1 > y2
} l[10005], id[10005];

struct vec
{
    int x, y;
    vec(int a = 0, int b = 0):x(a), y(b) {};
};

inline int cross(vec a, vec b)  //α���������0�ͷ���1��С�ڷ���-1�����ڷ���0
{
    ll temp = (ll)(a.x)*(ll)(b.y) - (ll)(a.y)*(ll)(b.x);
    if (temp > 0)
        return 1;
    else if (temp == 0)
        return 0;
    return -1;
}
//int n;
vec krmax, krmin, klmax, klmin;

inline bool cmp(const line& a, const line& b)
{
    return a.x < b.x;
}
inline bool cmp2(const line& a, const line& b)
{
    return (a.y1 - a.y2) < (b.y1 - b.y2);
}

int main()
{
    freopen("1.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &l[i].x, &l[i].y1, &l[i].y2);

    sort(l + 1, l + n + 1, cmp);//�ȸ���x�����С�����Ÿ���
    for (int i = 1; i <= n; i++)
    {
        id[i].x = i;//�����x���Ǽ�¼����ID�ˣ�����¼�Ǵ����ҵĵڼ������ߣ�
        id[i].y1 = l[i].y1;
        id[i].y2 = l[i].y2;
    }
    sort(id + 1, id + n + 1, cmp2);//�ٸ���y1-y2��С�����Ÿ������ȳ����á��̡��������·��Ķ˵��������ӡ�
    for (int idx = 1; idx <= n; idx++)
    {
        int i = id[idx].x;//�����Դ����ҵĵ�i�������·��Ķ˵��������ӡ�
        krmax = vec(1, INF);
        krmin = vec(1, -INF);
        klmax = vec(-1, -INF);
        klmin = vec(-1, INF);
        for (int j = i + 1; j <= n; j++)  //��������������б�ʺ���Сб��
        {
            vec v1(l[j].x - l[i].x, l[j].y1 - l[i].y2);
            vec v2(l[j].x - l[i].x, l[j].y2 - l[i].y2);
            if (cross(krmax, v1) < 0)
                krmax = v1;
            if (cross(krmin, v2) > 0)
                krmin = v2;
        }
        for (int j = i - 1; j >= 1; j--)  //��������������б�ʺ���Сб��
        {
            vec v1(l[j].x - l[i].x, l[j].y1 - l[i].y2);
            vec v2(l[j].x - l[i].x, l[j].y2 - l[i].y2);
            if (cross(klmin, v1) > 0)
                klmin = v1;
            if (cross(klmax, v2) < 0)
                klmax = v2;
        }
        //�ж��Դ����ҵĵ�i�������·��Ķ˵��������ӡ����Ƿ���У�������ֱ��continue
        if (cross(krmax, krmin) > 0)
            continue;
        if (cross(klmax, klmin) > 0)
            continue;
        if (cross(krmax, klmin) < 0)
            continue;
        if (cross(klmax, krmin) < 0)
            continue;
        //���У����������
        if (cross(klmax, krmax) * cross(klmax, krmin) <= 0)
            printf("%d %d %d %d", l[i].x + klmax.x, l[i].y2 + klmax.y, l[i].x, l[i].y2);
        else if (cross(klmin, krmax) * cross(klmin, krmin) <= 0)
            printf("%d %d %d %d", l[i].x + klmin.x, l[i].y2 + klmin.y, l[i].x, l[i].y2);
        else if (cross(klmax, krmax) > 0 && cross(klmin, krmin) < 0)
            printf("%d %d %d %d", l[i].x + krmax.x, l[i].y2 + krmax.y, l[i].x, l[i].y2);
        else if (cross(krmax, klmax) > 0 && cross(krmin, klmin) < 0)
            printf("%d %d %d %d", l[i].x + klmin.x, l[i].y2 + klmin.y, l[i].x, l[i].y2);
        break;
    }
    return 0;
}
//�Ż�1����б��ȫ����ʾΪ����int��ɵ�������б��֮��ȴ�С�ò�����ɣ�������߾���+��ʡʱ�䡣
//�Ż�2������ö�١��̡���ˮ������y1-y2С��ˮ������ֱ������̡���ˮ����Ϊ�����ӡ��ļ��ʸ���һЩ��
//�������Ż�1����ʱ�����Ż�1��200ms���������Ż�2��95ms����
//
//AC���룺
//---------------------
//���ߣ�foreyes_1001
//��Դ��CSDN
//ԭ�ģ�https://blog.csdn.net/foreyes_1001/article/details/52208749
//��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
