import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new FileInputStream(new File("1.txt")));
//		Scanner s = new Scanner(System.in);
		String a = s.next();
		int k = s.nextInt();
		s.close();

//		long ai = Long.parseLong(a) * 2;
//		String b="";
//		b+=ai;//integer with no more than 20 digits. but Long.MAX is 9223372036854775807L has 19;
		for (int i = 1; i <= k; i++) {
			if(is_Palindromic(a)){
				System.out.println(a);
				System.out.println(i-1);
				return;
			}
			String b = reverse(a);
			String c="";
			
			int f=0;
			for (int j = a.length()-1; j >= 0; j--) {
				int temp = (a.charAt(j)-'0')+(b.charAt(j)-'0') +f;
				if(temp >= 10){
					temp -=10;
					f=1;
				}else{
					f=0;
				}
				c+=temp;
			}
			if(f ==1)
				c += f;
			
			a = reverse(c);
		}
		System.out.println(a);
		System.out.println(k);
		
	}

	private static boolean is_Palindromic(String a) {
		return a.equals(reverse(a));
	}

	private static String reverse(String b) {
		StringBuffer res = new StringBuffer(b);
		return new String(res.reverse());
	}

}
