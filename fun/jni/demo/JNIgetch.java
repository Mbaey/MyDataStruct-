package com.jni.demo;  
public class JNIgetch {  
    //����һ�����ط���  
    public native char getch();  
    
    public static void main(String[] args){  
        //���ö�̬���ӿ�  
        System.loadLibrary("libdll-test");  
        JNIgetch jnigetch = new JNIgetch();
        while(true){
        	char i = jnigetch.getch();
        	System.out.println(i);        	
        }
    }  
}