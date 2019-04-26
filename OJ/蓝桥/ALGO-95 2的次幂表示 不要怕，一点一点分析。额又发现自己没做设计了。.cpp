#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=a; i<b; i++)
#define _ufor(i,a,b) for(int i=a-1; i>=b; i--)
typedef long long ll;
const int N=1e2+5,M=105;

int n,m,k, cnt=0, tmp=0;

//vector<int> maps[N];
//int maps[N][N];
//int a[N]={0};

stack<int> s;
void toBinary(int n)
{
    vector<int> a;
    while(n>=2)
    {
        a.push_back(n%2);
        n /=2;
    }
    a.push_back(n%2);

//    _ufor(i, a.size(), 0)
//    printf("%d\t%d\n", i, a[i]);

	bool first=0;

    _ufor(i, a.size(), 0)
    {
    	
        if(a[i] != 0)
        {
        	if(first){
	    		putchar('+');
	    	}
	    	
        	if(i == 1){
        		cout << 2;
        	}else{        	
	            cout <<"2(";
	            
	            if(i!=2 && i!=0)//2 or 0²Å´òÓ¡ 
	            	toBinary(i);
	            else
	            	cout << i;
	            
	            cout << ')';
	            
            }
            
            first=1;
        }
    }



}

int main()
{
    freopen("1.txt", "r", stdin);
    cin>>n;

    toBinary(n);

    return 0;
}


