import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
	
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File("1.txt"));
//		Scanner scanner = new Scanner(System.in);
		long N = scanner.nextLong();
		int b = scanner.nextInt();
		scanner.close();
		
//		System.out.println(Integer.parseInt("11011", b));
		String a = T2B(N, b);
		String a2 = reverse(a);
		if(a.equals(a2)){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}
		for (int i = 0; i < a2.length()-1; i++) {
			System.out.printf("%c ", a2.charAt(i));
		}
		System.out.printf("%c", a2.charAt(a2.length()-1));
	}

	private static String reverse(String a) {
		StringBuffer sb = new StringBuffer(a);
		sb.reverse();
		return sb.toString();
	}

	private static String T2B(long n, int b) {//但是没有考虑 超出10进制的情况
		String sb = new String();
		while( n >= b ){
			sb =  sb +  String.valueOf(n%b);
			n /=b;
		}
		sb += n;
		return sb;
	}
}
