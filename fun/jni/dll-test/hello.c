#include<stdio.h>
#include<conio.h>
#include"windows.h"
#include"com_jni_demo_JNIgetch.h"
JNIEXPORT jchar JNICALL Java_com_jni_demo_JNIgetch_getch (JNIEnv *env, jobject obj){
  	jchar c;
  	c = getch(); 
  	
  	return c;
 }