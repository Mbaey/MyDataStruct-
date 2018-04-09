import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
class To{
	int id;
	int num;
	public To() {
		super();
		// TODO Auto-generated constructor stub
	}
	public To(int id, int num) {
		super();
		this.id = id;
		this.num = num;
	}
	
}
class from{
	ArrayList<To> want;	
}
class Res{

	int id;
	int load;
	public Res(int id, int load) {
		super();
		this.id = id;
		this.load = load;
	}
	public Res() {
		super();
	}
	
}
public class Main {
	private static int n = 0;
	private static int []arr = new int[26];
	private static int []dep= new int[26];
	private static from wants[] = new from[26];
	private static ArrayList<Res> ress = new ArrayList<>();

	public static void main(String[] args) throws FileNotFoundException {
		// Scanner scanner = new Scanner(System.in);
		Scanner scanner= new Scanner(new File("1.txt"));
		int r;
		n=scanner.nextInt();
		while(n!=0){
			for (int i = 1; i <= n; i++) {
				int from =  scanner.nextInt();
				int k=  scanner.nextInt();
				wants[i] = new from();
				wants[i].want = new ArrayList<To>();
				for (int j = 0; j < k; j++) {
					int to=  scanner.nextInt();
					int num=  scanner.nextInt();
					wants[i].want.add(new To(to, num));
				}
			}
			ress.clear();
			int outId = scanner.nextInt();
			while(outId!=0){
				int cnt=0;
				for (int i = 1; i <= n; i++) {
					arr[i] = scanner.nextInt();
				}
				for (int i = 1; i <= n; i++) {
					dep[i] = scanner.nextInt();
				}
				
				for (int i = 1; i <= n; i++) {
					int size = wants[i].want.size();
					for (int j = 0; j < size; j++) {
						int to = wants[i].want.get(j).id;
						int num = wants[i].want.get(j).num;
						int a=0, d=0;
						for (int k = 1; k <= n; k++) {
							if(arr[k]== i){
								a=k;
							}
							if(dep[k]== to){
								d=k;
							}
						}
						cnt += (Math.abs(a-d)+1)*num;
					}
				}
				ress.add(new Res(outId, cnt));
				outId = scanner.nextInt();
			}
			Collections.sort(ress, new Comparator<Res>() {

				@Override
				public int compare(Res o1, Res o2) {
					if(o1.load != o2.load)
						return Integer.compare(o1.load ,o2.load);
					else
						return Integer.compare(o1.id , o2.id);
						
				}
			});
			System.out.println("Configuration Load");
			for(Res i : ress){
				System.out.printf("%d %9d\n", i.id, i.load);
			}
			n=scanner.nextInt();
		}
		
	}

}