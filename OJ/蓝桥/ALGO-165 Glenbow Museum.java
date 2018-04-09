import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
//参考文献 https://blog.csdn.net/sunny_hun/article/details/79337650
public class Main {
	private static int sum = 0;

	public static void main(String[] args) throws FileNotFoundException {
		// Scanner scanner = new Scanner(System.in);
		Scanner scanner= new Scanner(new File("1.txt"));
		int n, cnt=0;
		n=scanner.nextInt();
		while( n!=0){
			cnt++;
			if(n%2==1 || n<4){
				System.out.printf("Case %d: %d\n", cnt, 0);
				n=scanner.nextInt();
				continue;
			}
 			int r = (n+4)/2;
			long res = C(r, 4) + C(r-1, 4);
			System.out.printf("Case %d: %d\n", cnt, res);
			n=scanner.nextInt();
		}
		
	}
	/*
	 * n取m 组合
	 */
	private static long C(int n, int m) {
		if(m>n)
			return 0;
		long zi=1, mu=1;
		if(m > n-m){
			m=n-m;
		}
		for (int i = m; i > 0; i--) {
			zi*=n;
			n--;
			mu*=i;
			int com= gcd(zi, mu);
			zi /=com;
			mu /=com;
		}
		
		return zi/mu;
	}
	private static int gcd(long zi, long mu) {
		
		return (int) (mu==0? zi: gcd(mu, zi%mu));
	}

}