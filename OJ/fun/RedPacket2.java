import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;

public class RedPacket2 {
	private int total;
	private int amount;
	private int max;
	private int min;
	public ArrayList<Integer> res;
	
	public RedPacket2() {
		super();
	}
	/**
	 * max > total / amount 
	 * min < total / amount
	 * else throw  
	 * @param total
	 * @param amount
	 * @param d
	 * @param e
	 */
	public RedPacket2(double total, int amount, double max, double min) {//以分为单位
		super();
		this.total = (int) (total*100);
		this.amount = amount;
		double mid = total / amount;
		if(Double.compare(max, mid) == -1){
//			throw 
			System.out.println("mdzz");
		}
		this.max = (int) (max*100);
		this.min = (int) (min*100);
		res = new ArrayList<>(amount);
	}
	
	public ArrayList<Integer> getPackets(){
		Random random = new Random();
		int sum=0;
		for (int i = 0; i < amount; i++) {
			int ran = random.nextInt(max-min) + min;
			res.add(ran);
			sum += ran;
		}
		System.out.println(res);
		System.out.println(sum(res));
		/**
		 * 逐步修正
		 *  1.我以前想的是逐步修正生成每个数时的概率，但是那太需要数学功底了；
		 *  2.所以不如直接改结果。
		 *  但其实没必要规定max，min的吧。。微信红包也没让我们输啊。
		 *  
		 *  3.还可以用概率法编程，就不用while里套个（判定条件那么复杂的）for了 //但生成随机数也要耗时
		 */
		while (sum > total) {
			int temp = sum-total, j=0;
			for (int i = 0; i < temp && j < res.size(); i++) {
				Integer curVaule = res.get(j);
				if(curVaule > min){
					res.set(j, curVaule-1);
					sum--;
				}else{
					i--;
				}
				j++;
			}
		}
		while (sum < total) {
			int temp = total-sum, j=0;
			for (int i = 0; i < temp && j < res.size(); i++) {
				Integer curVaule = res.get(j);
				if(curVaule < max){
					res.set(j, curVaule+1);
					sum++;
				}else{
					i--;
				}
				j++;
			}
		}
		return res;
	}
	
	public static void main(String[] args) {
		RedPacket2 redPacket = new RedPacket2(10, 11, 9, 0.07);
		ArrayList<Integer> packets = redPacket.getPackets();
		System.out.println(packets);
		System.out.println(sum(packets));
	}

	private static int sum(ArrayList<Integer> packets) {
		int res=0;
		for(int i : packets)
			res += i;
		return res;
	}
}
