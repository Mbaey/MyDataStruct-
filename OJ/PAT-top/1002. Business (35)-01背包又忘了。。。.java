import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
	
	public static int max=0;
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new FileInputStream(new File("1.txt")));
//		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
//		P, L, and D where P is the profit, L the lasting days of the project, and D the deadline.
		int[]P = new int[n];
		int[]L = new int[n];
		int[]D = new int[n];
		boolean[]vis = new boolean[n];
		for (int i = 0; i < n; i++) {
			P[i]= s.nextInt();
			L[i] = s.nextInt();
			D[i] = s.nextInt();
		}
		getMax(P, L, D, vis, n, 0, 0);
		System.out.println(max);
	}
	private static void getMax(int[] p, int[] l, int[] d, boolean[] vis, int n, int value, int date) {
		if(value>max)
			max = value;
		for(int i = 0; i < n; i++){
			if(!vis[i] && date+l[i] <= d[i]){
				vis[i] = true;
				getMax(p, l, d, vis, n, value+p[i], date+l[i]);
				vis[i] = false;
			}
		}
		
	}

}
