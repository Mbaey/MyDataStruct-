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
		String a = s.nextLine();
		s.close();
		int []map = new int[10];
		for (int i = 0; i < a.length(); i++) {
			map[a.charAt(i)-'0']++;
		}

//		long ai = Long.parseLong(a) * 2;
//		String b="";
//		b+=ai;//integer with no more than 20 digits. but Long.MAX is 9223372036854775807L has 19;
		String b="";
		int f=0;
		for (int i = a.length()-1; i >= 0; i--) {
			
			int temp = (a.charAt(i)-'0')*2 +f;
			if(temp >= 10){
				temp -=10;
				f=1;
			}else{
				f=0;
			}
			map[temp]--;
			b+=temp;
		}
		if(f ==1)
			b += f;
		
		b = reverse(b);
		
		boolean flag = true;
		for (int i = 0; i < map.length; i++) {
			if(map[i] != 0){
				flag=false;
				break;
			}
		}
		
		if(flag){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}
		System.out.println(b);
	}

	private static String reverse(String b) {
		StringBuffer res = new StringBuffer(b);
		return new String(res.reverse());
	}

}
