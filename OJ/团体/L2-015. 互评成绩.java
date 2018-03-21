import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new File("1.txt"));
//		Scanner s = new Scanner(System.in);
		ArrayList<Double> res = new ArrayList<Double>();
		int n = s.nextInt();
		int k = s.nextInt();
		int m = s.nextInt();
		for (int i = 0; i < n; i++) {
			double sum=0;
			double min=100, max=0;
			for (int j = 0; j < k; j++) {
				double ts = s.nextDouble();
				sum +=ts;
				if(ts>max){
					max=ts;
				}
				if(ts<min){
					min=ts;
				}
			}
			sum =sum- min-max;
			res.add(sum / (double)(k-2));
		}
		Collections.sort(res, new Comparator<Double>() {
			@Override
			public int compare(Double o1, Double o2) {
				
				return Double.compare(o2, o1);
			}
		});
		for (int i = m-1; i >0 ; i--) {
			System.out.printf("%.3f ", res.get(i));
		}
		System.out.printf("%.3f", res.get(0));
		
	}
}
