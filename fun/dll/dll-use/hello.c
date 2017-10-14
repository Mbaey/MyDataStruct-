#include<stdio.h>
#include<Windows.h>
//HINSTANCE hDll;
typedef int(*lpGet_id)(void); //定义函数类型
lpGet_id add;
int main(){
	HINSTANCE hdll;
	hdll = LoadLibrary("libdll-test.dll");
	add = (lpGet_id)GetProcAddress(hdll, "say");
	add();
	return 0;	
}
