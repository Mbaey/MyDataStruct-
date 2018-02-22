import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public static int post[] = new int[40];
	public static int in[] = new int[40];
	public static int l[] = new int[40];
	public static int r[] = new int[40];
	public static int N;

	public static void main(String[] args) throws FileNotFoundException {
		Arrays.fill(post, -1);
		Scanner scanner = new Scanner(new File("1.txt"));
		// Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();

		for (int i = 1; i <= N; i++) {
			post[i] = scanner.nextInt();
		}
		for (int i = 1; i <= N; i++) {
			in[i] = scanner.nextInt();
		}

		creatTree(1, N, N);
		levelOrder();
	}

	// 2 3 1 5 7 6 4
	// 1 2 3 4 5 6 7
	private static int creatTree(int il, int ir, int pr) {// 分治法，post找根，in找左右
		if (il <= ir) {
			int root = post[pr], now = 0;
			for (int i = il; i <= ir; i++) {
				if (in[i] == root) {
					now = i;
					break;
				}
			}
			int cnt = ir - now;// 记录右子树节点个数
			l[root] = creatTree(il, now - 1, pr - cnt - 1);
			r[root] = creatTree(now + 1, ir, pr - 1);
			return root;
		}
		return 0;
	}

	private static void levelOrder() {

		Queue<Integer> queue = new LinkedList<Integer>();
		int cnt = 0;
		if (post[N] != 0) {
			queue.offer(post[N]);
			while (!queue.isEmpty()) {
				Integer node = queue.poll();
				cnt++;
				if (cnt != N)
					System.out.print(node + " ");
				else
					System.out.print(node);
				if (l[node] != 0)
					queue.offer(l[node]);
				if (r[node] != 0)
					queue.offer(r[node]);
			}
		}
		// System.out.println("累");

	}

}
