#include<stdio.h>
#include<Windows.h>
//HINSTANCE hDll;
typedef int(*lpGet_id)(void); //���庯������
lpGet_id add;
int main(){
	HINSTANCE hdll;
	hdll = LoadLibrary("libdll-test.dll");
	add = (lpGet_id)GetProcAddress(hdll, "say");
	add();
	return 0;	
}
