
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	static int[] d = new int[100005];
	static int[] next = new int[100005];
//								62535
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new File("1.txt"));
		// Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		int n = s.nextInt();
		int a0 = 0;
		for (int i = 0; i < n; i++) {
			a0 = s.nextInt();
			d[a0] = s.nextInt();
			next[a0] = s.nextInt();
		}
		int pre = 0;
		LinkedList<Integer> linkedList = new LinkedList<Integer>();
		int j = n/2 , cnt=0, mid = n/2;
		if(n % 2 != 0){
			mid++;
			j++;
		}
		for (int i = a; i != -1; i = next[i], cnt++) {
			
			if(cnt < n/2){
				linkedList.add( i);
			}else{
				linkedList.add(--j, i);
			}
			if (next[i] == -1) {
				a = i;
				break;
			}
			pre = i;
		}
//			System.out.println(linkedList);
		for (int i =0; i<n; i++) {
			int in = linkedList.get(i);
//			System.out.println(in+"   "+Integer.MAX_VALUE);
			if (i == n-1) {
				System.out.printf("%05d %d -1\n", in, d[in]);
			} else
				System.out.printf("%05d %d %05d\n", in, d[in], linkedList.get(i+1));
		}

	}

}
