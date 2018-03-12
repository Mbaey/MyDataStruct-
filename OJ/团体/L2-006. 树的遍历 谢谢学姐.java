
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
	static int []in = new int[31];
	static int []after = new int[31];
	static int []level= new int[1005];
//	https://www.liuchuo.net/archives/2079  Ð»Ð»Ñ§½ã~
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File("1.txt"));
//		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		for (int i = 0; i < N; i++) {
			after[i]= scanner.nextInt();
		}
		for (int i = 0; i < N; i++) {
			in[i]= scanner.nextInt();
		}
		scanner.close();
		creat_tree(N-1, 0 ,N-1, 0);
		
		int cnt=0;
		for (int i = 0; i < level.length; i++) {
			if(level[i] != 0 && cnt != N -1){
				cnt++;
				System.out.print(level[i]+" ");
			}else if(level[i] != 0 ){
				System.out.print(level[i]);
			}
		}
		
	}
//	7
//	2 3 1 5 7 6 4
//	1 2 3 4 5 6 7
	private static void creat_tree(int root_index, int l, int r, int index) {
		if(l > r)
			return;
		int root = after[root_index];
		int in_index = get_in(root, l ,r);
		int r_cnt = r - in_index;
		level[index] = root;
		
		creat_tree(root_index-r_cnt-1, l, in_index-1, index*2+1);
		creat_tree(root_index-1, in_index+1, r, index*2+2);
	}

	private static int get_in(int root, int l, int r) {
		for (int i = l; i <= r; i++) {
			if(in[i] == root){
				return i;
			}
		}
		return -1;
	}

}
