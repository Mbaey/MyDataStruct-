
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

class Peo {
	int id;
	int fang_num;
	int fang_area;

	public Peo() {
		super();
	}

	@Override
	public String toString() {
		return "Home [ id=" + id + ",  fang_num=" + fang_num + ", fang_area=" + fang_area +"]";
	}
}

class node {
    int id, people;
    double num, area;
    boolean flag = false;
};
public class Main {
	private static int[] father = new int[10000];
	private static boolean[] vis = new boolean[10000];

	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File("1.txt"));
		// Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		Peo[] peo = new Peo[1002];

		for (int i = 0; i < 10000; i++)
			father[i] = i;
		for (int i = 0; i < n; i++) {
			peo[i] = new Peo();
			int he = scanner.nextInt();
			int f = scanner.nextInt();
			int m = scanner.nextInt();
			int c = scanner.nextInt();
			vis[he] = true;
			peo[i].id = he;
			if (f != -1) {
				vis[f] = true;
				union(he, f);
			}
			if (m != -1) {
				vis[m] = true;
				union(he, m);
			}
			for (int j = 0; j < c; j++) {
				int ch = scanner.nextInt();
				vis[ch] = true;
				union(he, ch);
			}
			peo[i].fang_num = scanner.nextInt();
			peo[i].fang_area = scanner.nextInt();
		}
		scanner.close();
		// 0 4
		// 2
		node []ans = new node[10000];
		for (int i = 0; i < 10000; i++) {
			ans[i] = new node();
		}
		for(int i = 0; i < n; i++) {
	        int id = find(peo[i].id);
	        ans[id].id = id;
	        ans[id].num += peo[i].fang_num;
	        ans[id].area += peo[i].fang_area;
	        ans[id].flag = true;
	    }
		int cnt = 0;
	    for(int i = 0; i < 10000; i++) {
	        if(vis[i])
	            ans[find(i)].people++;
	        if(ans[i].flag)
	            cnt++;
	    }
	    for(int i = 0; i < 10000; i++) {
	        if(ans[i].flag) {
	            ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people);
	            ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
	        }
	    }
		

		Arrays.sort(ans, new Comparator<node>() {

			@Override
			public int compare(node o1, node o2) {
				if (o1.area != o2.area) {
					return Double.compare(o2.area, o1.area);
				} else {
					return Integer.compare(o1.id, o2.id);
				}
			}
		});
		System.out.println(cnt);
		for (int i = 0; i < cnt; i++) {
			System.out.printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].people,ans[i].num,ans[i].area);
		}

	}

	private static void union(int he, int m) {
		int fah = find(he);
		int fm = find(m);
		if (fah > fm) {
			father[fah] = fm;
		} else {
			father[fm] = fah;

		}

	}

	private static int find(int m) {
		while (m != father[m]) {
			m = father[m];
		}
		return m;
	}
}
