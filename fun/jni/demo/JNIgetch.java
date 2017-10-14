package com.jni.demo;  
public class JNIgetch {  
    //定义一个本地方法  
    public native char getch();  
    
    public static void main(String[] args){  
        //调用动态链接库  
        System.loadLibrary("libdll-test");  
        JNIgetch jnigetch = new JNIgetch();
        while(true){
        	char i = jnigetch.getch();
        	System.out.println(i);        	
        }
    }  
}