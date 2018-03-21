import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new File("1.txt"));
		// Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int a[] =new int[n], sum=0, min=0;
		for (int i = 0; i < n; i++) {
			a[i] =s.nextInt();
			sum += a[i];
		}
		Arrays.sort(a);
		
		int in = n/2;
		for (int i = 0; i < in; i++) {
			min += a[i];
		}
		
		System.out.printf("Outgoing #: %d\n", n-in);
		System.out.printf("Introverted #: %d\n", in);
		System.out.printf("Diff = %d\n", sum - min-min);
		
	}
}
