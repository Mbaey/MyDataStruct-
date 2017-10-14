#include<stdio.h>
#include<Windows.h>
//HINSTANCE hDll;
typedef int (*lpGet_id)(void); //定义函数类型
lpGet_id say;
int main() {
	HINSTANCE hdll;
	hdll = LoadLibrary("libdll-test.dll");
	if (hdll == NULL) {
		FreeLibrary(hdll);
	}
	say = (lpGet_id) GetProcAddress(hdll, "say");
	say();
	return 0;
}
