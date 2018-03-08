//import java.io.File;
//import java.io.FileNotFoundException;
//import java.util.ArrayList;
//import java.util.Scanner;
//
//class node {
//	int v;
//	node r, l;
//
//	public node() {
//		super();
//	}
//
//	public node(int v) {
//		super();
//		this.v = v;
//	}
//	
//	public ArrayList<Integer> after(){
//		ArrayList<Integer> list = new ArrayList<>();
//		return after(this, list);
//	}
//	
//	private ArrayList<Integer> after(node r, ArrayList<Integer> list){
//		if(r != null){
//			
//			after(r.l, list);
//			after(r.r, list);			
//			list.add(r.v);
//		}
//		return list;
//	}
//	
//
//}
//
//public class CopyOfMain {
//
//	private static int n;
//	private static int[] nodes = new int[1005];
//	private static boolean[] vis = new boolean[1005];
//
//	public static void main(String[] args) throws FileNotFoundException {
//		Scanner scanner = new Scanner(new File("1.txt"));
//		n = scanner.nextInt();
//		for (int i = 0; i < n; i++) {
//			nodes[i] = scanner.nextInt();
//		}
//		node t1 = createBST(0);
//		node t2 = createRBST(0);
//		
//		ArrayList<Integer> l1 = t1.after();
//		ArrayList<Integer> l2 = t2.after();
//		if(l1.size() == n){
//			System.out.println("YES");
//			for (int i = 0; i < n-1; i++) {
//				System.out.print(l1.get(i)+" ");
//			}
//			System.out.print(l1.get(n-1));
//		}else if(l2.size() == n){
//			System.out.println("YES");
//			for (int i = 0; i < n-1; i++) {
//				System.out.print(l2.get(i)+" ");
//			}
//			System.out.print(l2.get(n-1));
//			
//		}else{
//			System.out.println("NO");
//		}
//	}
//	
//	private static node createRBST(int root) {
//		if (root < 0 || root >= n)
//			return null;
//		vis[root] = true;
//		
//		node tree = new node(nodes[root]);
//		if (nodes[root + 1] >= nodes[root]) {
//			tree.l = createRBST(root + 1);
//			for (int i = 0; i < n; i++) {
//				if (!vis[i]) {
//					if(nodes[i] < nodes[root])
//						tree.r = createRBST(i);
//					break;
//				}
//			}
//		} else {
//			if(root>=1 && nodes[root + 1] < nodes[root-1]){//next node is father's rchild;
//				tree.r = null;
//			}else{
//				tree.r = createRBST(root + 1);			
//			}
//			tree.l = null;
//		}
//
//		return tree;
//	}
//
//	private static node createBST(int root) {
//		if (root < 0 || root >= n)
//			return null;
//		vis[root] = true;
//		
//		node tree = new node(nodes[root]);
//		if (nodes[root + 1] < nodes[root]) {
//			tree.l = createBST(root + 1);
//			for (int i = 0; i < n; i++) {
//				if (!vis[i]) {
//					if(nodes[i] >= nodes[root])
//						tree.r = createBST(i);
//						
//					break;
//				}
//			}
//		} else {
//			if(root>=1 && nodes[root + 1] >= nodes[root-1]){//next node is father's rchild;
//				tree.r = null;
//			}else{
//				tree.r = createBST(root + 1);			
//			}
//			tree.l = null;
//		}
//
//		return tree;
//	}
//
//}
