#include <iostream>
using namespace std;
//https://blog.csdn.net/qq_42835910/article/details/86714857?tdsourcetag=s_pctim_aiomsg
int main(int argc, char** argv) {
	long long n, p = 1;
	cin>> n;
	for(long long i = 2; i*i <= n ; i++){
		if(n%i == 0 ){
			p *= i;
			while( n%i == 0 ) n /= i;
		}
	} 	 
	cout<< p*n<< '\n';
	return 0;
}