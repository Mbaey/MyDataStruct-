
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	static int[] friend = new int[105];
	static int[][] hate = new int[105][105];
	static int n, m, k;

	// 62535
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new File("1.txt"));
		// Scanner s = new Scanner(System.in);

		int fa, fb, con;
		n = s.nextInt();
		m = s.nextInt();
		k = s.nextInt();
		for (int i = 1; i <= n; i++) {
			friend[i] = i;
		}
		for (int i = 1; i <= m; i++) {
			fa = s.nextInt();
			fb = s.nextInt();
			con = s.nextInt();
			if (con == 1) {
				if (fa > fb)
					friend[fa] = fb;
				else
					friend[fb] = fa;
			} else {
				hate[fa][fb] = 1;
				hate[fb][fa] = 1;
			}
		}
		for (int i = 1; i <= k; i++) {
			fa = s.nextInt();
			fb = s.nextInt();
			boolean is_f = ch_f(fa, fb);
			boolean is_h = hate[fa][fb] == 1;
			if (is_f && is_h) {
				System.out.println("OK but...");
			} else if (is_h) {
				System.out.println("No way");
			} else if (is_f) {
				System.out.println("No problem");
			} else {
				System.out.println("OK");
			}

		}

	}

	private static boolean ch_f(int fa, int fb) {
		int a = find2(fa);
		int b = find2(fb);
		if (a == b) {
			return true;
		}
		return false;
	}

	private static int find2(int p) {
		if (friend[p] == p) {
			return p;
		} else {
			friend[p] = find2(friend[p]);
			return friend[p];
		}
	}

	private static int find(int fb) {
		int t = fb;
		while (friend[fb] != fb) {
			fb = friend[fb];
		}
		friend[t] = fb;
		return fb;
	}

}
