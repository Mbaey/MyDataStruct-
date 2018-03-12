
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

class Home {
	HashSet<Integer> ids;
	int id, num;
	int fang_num;
	int fang_area;
	float f_n;
	float f_a;

	public Home() {
		super();
		ids = new HashSet<Integer>();
	}

	@Override
	public String toString() {
		return "Home [ids=" + ids + ", id=" + id + ", num=" + num + ", fang_num=" + fang_num + ", fang_area="
				+ fang_area + ", f_n=" + f_n + ", f_a=" + f_a + "]";
	}
	

}

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File("1.txt"));
		// Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		ArrayList<Home> homes = new ArrayList<Home>();

		for (int i = 0; i < n; i++) {
			HashSet<Integer> ids = new HashSet<>();
			int he = scanner.nextInt();
			int f = scanner.nextInt();
			int m = scanner.nextInt();
			int c = scanner.nextInt();
			ids.add(he);
			if (f != -1)
				ids.add(f);
			if (m != -1)
				ids.add(m);
			for (int j = 0; j < c; j++) {
				int ch = scanner.nextInt();
				ids.add(ch);
			}
			boolean single = true; // this peo is contains in a home
			// for (int j = 0; j < homes.size(); j++) {
			// System.out.println(homes.get(j).ids);
			// System.out.println(ids);
			// if (!Collections.disjoint(homes.get(j).ids, ids)) {// have same
			// // element
			// single = false;
			// homes.get(j).ids.addAll(ids);
			// homes.get(j).fang_num = scanner.nextInt();
			// homes.get(j).fang_area = scanner.nextInt();
			// }
			// }
			if (single) {
				homes.add(new Home());

				int j = homes.size() - 1;
				homes.get(j).ids.addAll(ids);
				homes.get(j).fang_num = scanner.nextInt();
				homes.get(j).fang_area = scanner.nextInt();
			}
		}
		scanner.close();
		// 0 4
		// 2
		for (int j = 0; j < homes.size(); j++) {
//			System.out.println(homes.get(j).ids);
			boolean single = true;
			for (int i = j + 1; i < homes.size(); i++) {
				HashSet<Integer> ids = homes.get(i).ids;
//				System.out.println(ids);
//				System.out.println("*****");
				if (!Collections.disjoint(homes.get(j).ids, ids)) {// have same element
//					System.out.println(homes.get(j));
//					System.out.println(homes.get(i));
					homes.get(j).ids.addAll(ids);
					homes.get(j).fang_num += homes.get(i).fang_num;
					homes.get(j).fang_area += homes.get(i).fang_area;
					homes.remove(i);
					i--;
					single = false;
//					System.out.println(homes.get(j));
				}
			}
			if(!single){
				j--;
			}
		}

		System.out.println(homes.size());
		for (Home h : homes) {
//			System.out.println(h);
//			System.out.println(h.ids.toArray());
			h.id = Collections.min(h.ids);
			h.num = h.ids.size();
			h.f_n = (float) h.fang_num / h.num;
			h.f_a = (float) h.fang_area / h.num;
		}

		Collections.sort(homes, new Comparator<Home>() {

			@Override
			public int compare(Home o1, Home o2) {
				if (o1.f_a != o2.f_a) {
					return Float.compare(o2.f_a, o1.f_a);
				} else {
					return Integer.compare(o1.id, o2.id);
				}
			}
		});
		for (Home h : homes) {
			System.out.printf("%04d %d %.3f %.3f\n", h.id, h.num, h.f_n, h.f_a);
		}

	}
}
