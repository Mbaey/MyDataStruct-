
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
//		String l = "2147483647";
//		System.out.println(Integer.MAX_VALUE);
//		System.out.println(l.length());
		Scanner scanner = new Scanner(new File("1.txt"));
//		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		
		HashSet sets[] =new HashSet[N+1];
		for (int i = 1; i <= N; i++) {
			int m = scanner.nextInt();
			sets[i] = new HashSet<Long>();
			for (int j = 0; j < m; j++) {
				long l = scanner.nextLong();
				sets[i].add(l);
			}
			
		}
		int n2 = scanner.nextInt();
		for (int i = 0; i < n2; i++) {
			int a = scanner.nextInt();
			int b = scanner.nextInt();
			HashSet<Long> all = new HashSet<Long>();
			all.addAll(sets[a]);
			all.addAll(sets[b]);
			int A = sets[a].size();
			int B = sets[b].size();
			int C = all.size();
			float r = (A+B-C)/(float)C;
//			System.out.println(A+B-C);
			System.out.printf("%.2f%%\n", r*100);
		}
	}

}
