#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
const int N=1e2+5,M=105;

int n,m,k, cnt=0, tmp=0;

//vector<int> maps[N];
//int maps[N][N];
int a[N]={0};

stack<int> s;
string maps[16]={
	"0000", "0001", "0010", "0011", 
	"0100", "0101", "0110", "0111", 
	"1000", "1001", "1010", "1011", 
	"1100", "1101", "1110", "1111"			
};

//map<string, int> people{{"Ann", 25}, {"Bill", 46},{"Jack", 32},{"Jill", 32}};
//map<string, int> b2o = {
//	"000":0, "001":1, "010":2, "011":3, 
//	"100":4, "101":5, "110":6, "111":7 
//};

int x2d(char c){
	int res=0;
	if(isdigit(c)){
		res=c-'0';	
	}else
		res=c-'A'+10;	
		
	return res;
}
vector<int> v;
// https://www.liuchuo.net/archives/1278
int main() {
	freopen("1.txt", "r", stdin);
	map<string, string> b2o;
    b2o["000"] = "0"; b2o["001"] = "1"; b2o["010"] = "2"; b2o["011"] = "3"; b2o["100"] = "4";
    b2o["101"] = "5"; b2o["110"] = "6"; b2o["111"] = "7";
    
	cin >> m ;
	getchar();

	ll n;
	string str, binary;
	while(m--){
//		scanf("%x", &n);
		getline(cin, str);
		binary = "";
		
		_for(i,0,str.size()){
			int index=x2d(str[i]);
			binary.append(maps[index]);
		}
		
		int lenb = binary.length();
        if(lenb % 3 == 1) {
            binary = "00" + binary;
        } else if(lenb % 3 == 2) {
            binary = "0" + binary;
        }
        
        int flag = 0;
		for(int j = 0; j < lenb; j += 3) {
            string temp = binary.substr(j, 3);
            string t = b2o[temp];
            if(j == 0 && t == "0") {
                flag = 1;
                continue;
            }
            if(flag == 1 && j == 3 && t == "0") {
                continue;
            }
            cout << t;
        }
        cout << endl;
	}
	
	
		
	return 0;
 }
