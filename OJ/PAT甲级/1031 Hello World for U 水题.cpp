#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N=300;//ms

/*
it must be satisfied that n​1​​ =n​3​​ =max { k | k≤n​2​​  for all 3≤n​2​​ ≤N } with n​1​​ +n​2​​ +n​3​​ −2=N.
*/
int main(){
	freopen("1.txt", "r" ,stdin);
	string str;
    cin >> str;
    int n = str.length();
    int n1=0, n2=0;// H, W
    int maxN=0;

    for(int i=3; i<=n; i++){

        if((n+2-i)%2){//==1是奇数
            continue;
        }
        n1 = (n+2-i)/2;
        if(n1 <= i)
            maxN = max(maxN, n1);
    }
    n1=maxN;
    n2=n-2*n1+2;

    char res[n1][n2]={0};
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            res[i][j]=' ';
        }
    }

    int i=0, j=0, cnt=0;
    for(; i<n1; i++){
        res[i][j]=str[cnt++];
    }i--; j++;

    for(; j<n2; j++){
        res[i][j]=str[cnt++];
    }j--; i--;

    for(; i>=0; i--){
        res[i][j]=str[cnt++];
    }

    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            cout<< res[i][j];
        }
        cout<<endl;
    }
    //vector<int> arr;
//    str.

    return 0;
}
