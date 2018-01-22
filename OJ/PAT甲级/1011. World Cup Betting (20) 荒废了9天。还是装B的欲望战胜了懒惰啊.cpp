#include <iostream>
#include <cstdio>

using namespace std;
char cs[]= { 'W', 'T', 'L'};
int main()
{
    freopen("1.txt", "r", stdin);
    float sum=1;
    for(int i=0; i<3; i++){
        int ind=0;
        float max=0, t=0;
        for(int j=0; j<3; j++){
            cin >> t;
            if(t > max){
                max = t;
                ind = j;
            }
        }
        sum *= max;
        cout << cs[ind] << ' ';
    }
    printf("%.2f", (sum*0.65-1)*2);
    return 0;
}
