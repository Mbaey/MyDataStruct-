import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	private static int N;
	private static final int Len = 10005;
	private static int height = 0;
	private static ArrayList[] maps = new ArrayList[Len];
	private static boolean[] vis = new boolean[Len];

	public static void main(String[] args) throws FileNotFoundException {

		Scanner scanner = new Scanner(new File("1.txt"));
//		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		for (int j = 1; j <= N; j++) {
			maps[j] = new ArrayList<Integer>();
		}
		for (int i = 0; i < N - 1; i++) {
			int a = scanner.nextInt();
			int b = scanner.nextInt();
			maps[a].add(b);
			maps[b].add(a);
		}

		int hei[] = new int[N+4];
		boolean flag = false;
		for (int i = 0; i <= N - 1; i++) {
			int cnt = 0;// recording the number of connected components in the graph.
			height = 0;//recorde tree's hei
			Arrays.fill(vis, false);
			
			for (int j = 1; j <= N; j++) {
				int start = (i + j) % N;
				start = start == 0 ? N : start;
				if (!vis[start]) {
					dfs(start, 0);// recording tree's hei when dfs the tree;
					hei[start] = height;
					cnt++;
				}
			}
			if (cnt > 1) {
				System.out.printf("Error: %d components", cnt);
				flag = true;
				break;
			}
		}
		if (!flag) {
			int max = 0;
			for (int i = 1; i <= N; i++) {
				if (hei[i] > max) {
					max = hei[i];
				}
			}
			for (int i = 1; i <= N; i++) {
				if (hei[i] == max)
					System.out.println(i);
			}
		}

	}

	private static void dfs(int start, int hei) {
		vis[start] = true;
		for(Object i : maps[start]){
			int ind = (int) i;
			if(!vis[ind]){
				height = Math.max(height, hei);
				dfs(ind, hei+1);
			}
		}
//		for (int i = 0; i < maps[start].size(); i++) {
//			int index = (int) maps[start].get(i);
//			if(!vis[index]){
//				return dfs(index, hei+1);						
//				
//			}
//		}
		
	}

}
