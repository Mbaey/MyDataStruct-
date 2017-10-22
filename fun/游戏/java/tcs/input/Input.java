package com.tcs.input;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Input {
	/**
	 * 如何实现监听。。
	 * @return
	 */
	public static String input;
	public static char key;
	public static Thread thread;
	public static void startControl() {
		Scanner scanner = new Scanner(System.in);
		
		thread = new Thread(){

			public void run() {
				while(scanner.hasNext()){
					input = scanner.next();					
				}
			}
		};
		thread.start();		
	}
	
	public static char getControl1(){
		input = "hello ";
		startControl();
		while(true){
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			key = input.charAt(input.length()-1);
			System.out.println(key);
			return key;
		}
	}
}
