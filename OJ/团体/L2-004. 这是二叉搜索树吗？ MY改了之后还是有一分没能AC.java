import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

class node {
	int v;
	node r, l;

	public node() {
		super();
	}

	public node(int v) {
		super();
		this.v = v;
	}

	public ArrayList<Integer> after() {
		ArrayList<Integer> list = new ArrayList<>();
		return after(this, list);
	}

	private ArrayList<Integer> after(node r, ArrayList<Integer> list) {
		if (r != null) {

			after(r.l, list);
			after(r.r, list);
			list.add(r.v);
		}
		return list;
	}

}

public class Main {

	private static int n;
	private static int[] nodes = new int[1005];

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File("1.txt"));
		// Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		for (int i = 0; i < n; i++) {
			nodes[i] = scanner.nextInt();
		}

		node BST = null;
		if (test(true, 0, n - 1)) {
			BST = createBST(true, 0, n - 1);
		} else if (test(false, 0, n - 1)) {
			BST = createBST(false, 0, n - 1);
		} else {
			System.out.println("NO");
		}

		if (BST != null) {
			System.out.println("YES");
			ArrayList<Integer> after = BST.after();
			for (int i = 0; i < n - 1; i++) {
				System.out.print(after.get(i) + " ");
			}
			System.out.print(after.get(n - 1));
		}
	}

	// b = true test BST
	// else test RBST
	private static boolean test(boolean b, int l, int r) {
		int i = l + 1;
		for (; i <= r; i++) {
			if (b) {
				if (nodes[i] >= nodes[l]) {
					break;
				}
			} else {
				if (nodes[i] < nodes[l]) {
					break;
				}
			}
		}
		for (; i <= r; i++) {
			if (b) {
				if (nodes[i] < nodes[l]) {
					return false;
				}
			} else {
				if (nodes[i] >= nodes[l]) {
					return false;
				}
			}
		}
		return true;
	}

	// b = true create BST
	// else create RBST
	private static node createBST(boolean b, int l, int r) {
		if (l > r)
			return null;

		node tree = new node(nodes[l]);
		int i = l + 1;
		for (; i <= r; i++) {
			if (b) {
				if (nodes[i] >= nodes[l]) {
					break;
				}
			} else {
				if (nodes[i] < nodes[l]) {
					break;
				}
			}
		}
		tree.l = createBST(b, l + 1, i - 1);
		tree.r = createBST(b, i, r);
		return tree;
	}

}
