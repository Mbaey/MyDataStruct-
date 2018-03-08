#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
//#include <cmath>

using namespace std;

vector<int> a(1000);
int n, m;

void adj(int i){
    int t;
    while(i != 1 && a[i] < a[i/2]){//就这么暴力
        swap(a[i], a[i/2]);
        i/=2;
    }
}
int get(int num){
    for(int i=1; i<=n; i++){
        if(a[i] == num)
            return i;
    }
}
void check1(int i){
    if(a[1]==i){
        cout << 'T' << endl;
    }else
        cout << 'F' << endl;
}

void check2(int i, int j){//siblings
    i = get(i);
    j = get(j);
    if(j/2==i/2){
        cout << 'T' << endl;
    }else
        cout << 'F' << endl;
}

void check3(int i, int j){//parent
    i = get(i);
    j = get(j);
    if(j/2==i){
        cout << 'T' << endl;
    }else
        cout << 'F' << endl;
}

void check4(int i, int j){//child
    i = get(i);
    j = get(j);
    if(j == i/2){
        cout << 'T' << endl;
    }else
        cout << 'F' << endl;
}
int main()
{

    freopen("1.txt", "r", stdin);
    cin >> n >> m;
    a.resize(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
        adj(i);
    }
//    for(int i=1; i<=n; i++){/test true
//        cout << a[i] << endl;
//    }


    getchar();
    for(int k=1; k<=m; k++){
        string str;
        getline(cin, str);
//        cout << str<< endl;
        unsigned int pos1 = str.find("root");
        unsigned int pos2 = str.find("siblings");
        unsigned int pos3 = str.find("parent");
        unsigned int pos4 = str.find("child");
        int i, j;
        if(pos1 != string::npos){
            sscanf(str.c_str(), "%d is the root", &i);
            check1(i);
        }else if(pos2 != string::npos){
            sscanf(str.c_str(), "%d and %d are siblings", &i, &j);
            check2(i,j );
        }else if(pos3 != string::npos){
            sscanf(str.c_str(), "%d is the parent of %d", &i, &j);
            check3(i,j );
        }else if(pos4 != string::npos){
            sscanf(str.c_str(), "%d is a child of %d", &i, &j);
            check4(i,j );
        }
    }

    return 0;
}
