
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File("1.txt"));
		// Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		// 5*6*7
		int sqr = (int) (Math.sqrt(n));
		for (int lian = 12; lian >= 1; lian--) {
			for (int i = 2; i <= sqr; i++) {
				long sum=1;
				for (int j = 0; j < lian; j++) {
					sum*=i+j;
					if (n % sum != 0)
						break;
				}
				if(n % sum == 0){
					System.out.println(lian);
					System.out.print(i);
					for (int j = i+1; j < i+lian; j++) {
						System.out.print("*"+j);
					}
					return;
				}
			}
		}
		System.out.println(1);
		System.out.println(n);
	}
}
