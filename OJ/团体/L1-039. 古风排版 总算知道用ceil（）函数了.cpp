#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	freopen("1.txt", "r", stdin);
	int column=0;
	string s;
    cin >> column;
    getchar();
    getline(cin, s);
    int all = s.length();
    int r = ceil(all / (float)column );
    char a[column][r], ch;
    int ci=0, ri=r-1;
    for(int i=0; i<column*r; i++){
        if(i < s.length()){
            ch = s[i];
        }else{
            ch = ' ';
        }

        a[ci++][ri] = ch;
        if(ci == column){
            ci = 0;
            ri--;
        }
    }
    for(int i=0; i<column; i++){
        for(int j=0; j<r; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
	return 0;
}
