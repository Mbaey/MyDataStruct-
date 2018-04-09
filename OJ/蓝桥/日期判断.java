import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static int day[] = new int[] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	static int day2[] = new int[] { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	private static int sum = 0;

	public static void main(String[] args) throws FileNotFoundException {
		// Scanner scanner = new Scanner(System.in);
		Scanner scanner = new Scanner(new File("1.txt"));
		int year = scanner.nextInt();
		int week = 3;// 
		for (int i = 1998; i < year; i++) {
			if (is_run(i)) {
				week = (week + 366) % 7;
			} else {
				week = (week + 365) % 7;
			}
//			System.out.printf("第%d年 1-1 是星期:%d\n", i+1, week+1);
		}

		week = (week + 12) % 7;
		for (int i = 0; i < 12; i++) {
			if (week == 4) {
				sum++;
//				System.out.printf("%d-%d-%d\n", year, i+1, 13 );
			}
			if (is_run(year))
				week = (week + day2[i]) % 7;
			else
				week = (week + day[i]) % 7;;
		}

		System.out.println(sum);

	}

	private static boolean is_run(int i) {
		if (i % 4 == 0 && i % 100 != 0) {
			return true;
		}
		if( i % 400 == 0)
			return true;
		return false;
	}
}