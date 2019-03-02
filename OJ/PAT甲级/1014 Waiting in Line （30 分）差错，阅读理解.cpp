#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
//#include <climits>

using namespace std;
int w[1005], res[1005]={0};
int main()
{
//    freopen("1.txt", "r", stdin);
    int n, m, k, q;
    cin >> n >> m >> k >>q;

    fill(res, res + k + 1, 0);
    queue<int> win[n];
    for(int i=1; i<=k; i++) cin >> w[i];
//    for(int i=0; i<q; i++) ;

    for(int i=1; i<=n*m && i<=k; i++){//init
        int a = (i-1) % n;
        if(win[a].empty()){
            win[a].push(w[i]);
        }else{
            if(win[a].back() >= 540){
                res[i] = 1;
            }else{
                w[i] = w[i]+ win[a].back();
                win[a].push(w[i]);
            }
        }
    }

//    for(auto i : win){//test init
//        while(!i.empty()){
//            cout << i.front() << " ";
//            i.pop();
//        }
//        cout << endl;
//    }
    for(int i=n*m+1; i<=k; i++){//ģ����ʵ�� ��ӳ��Ӱѡ���
//        in(i, win, w);
//        int min = INT_MAX, index_min=-1;
        int min_t = win[0].front(), index_min=0;

        for(int j=1; j<n; j++){//��N�������У�J��С��
            if(min_t > win[j].front()){
                min_t = win[j].front();
                index_min = j;
            }
        }

        if(win[index_min].back() >= 540){
            res[i] = 1;
        }

        w[i] = w[i]+ win[index_min].back();
        win[index_min].push(w[i]);

        win[index_min].pop();
    }

//    for(auto i: w){ test in
//        cout << i << " ";
//    }
    for(int i=0; i<q; i++){
        int que=0;
        cin >> que;
        int t = w[que];
        if(res[que] == 1){
            cout << "Sorry" << endl;
        }else {
            int h = t / 60 + 8;
            int m = t % 60;
            printf("%02d:%02d\n", h, m);
        }
    }
    return 0;
}
