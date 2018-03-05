import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new FileInputStream(new File("1.txt")));
//		Scanner s = new Scanner(System.in);
		int r = s.nextInt();
		int g = s.nextInt();
		int b = s.nextInt();
		String R = ten213(r);
		String G = ten213(g);
		String B = ten213(b);
		System.out.print("#");
		System.out.print(R);
		System.out.print(G);
		System.out.print(B);
		
	}

	private static String ten213(int r) {
		StringBuffer sb = new StringBuffer();
		while(r > 13){
			int wei = r % 13;
			r /= 13;
			sb.append(toChar(wei));
		}
		sb.append(toChar(r));
		while(sb.length() != 2)
			sb.append('0');
		return sb.reverse().toString();
	}

	private static char toChar(int wei) {
		if(wei<10)
			return (char) (wei + '0');
		else{
			return (char) (wei - 10 +  'A');			
		}
	}



}
