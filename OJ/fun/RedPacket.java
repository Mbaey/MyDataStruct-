package com.redPacket.bean;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class RedPacket {
	private int sum;
	private int[] each;
	private int peo;
	private int max, min;

	public RedPacket() {
		super();
	}

	public RedPacket(float sum, int peo, double max, double min) {// 因为钱只是精确到小数点后两位
		super();
		each = new int[peo];
		this.sum = (int) (sum * 100);
		this.peo = peo;
		this.max = (int) (max * 100);
		this.min = (int) (min * 100);
	}	
	
	
	/**
	 * algo-1:
	 * 	rand() 一个【min,max】之间的数
	 *  每次迭代， max减一点，min加一点。生成最后一个数时 max = min = sum
	 * @return
	 * 
	 * 不管max,min了。直接乱生成
	 */
	public Double[] getEach() {
		int f = 0;
		for (int i = 0; i < peo - 1; i++) {
			min = 1;
			max = sum - peo + i;
			do {
				f = rand();
			} while (sum < f);// f > sum
			sum -= f;

			each[i] = f;
//			System.out.println("***" + i + " sum:" + sum + "   E: " + f);
			/*
			 
			 */
//			int mid = sum / (peo - i);
//			if (mid < f) {
//				max = (int) (max * (float) (mid - min) / (max - min));
//			}else{
//				max = (int) (max * (float) (mid - min) / (max - min));
//			}
		}
		each[peo - 1] = sum;
		ArrayList<Double> a = new ArrayList<>();
		for(int i : each){
			a.add(i/100.0);
		}
		Collections.shuffle(a);
		Double []res = new Double[peo];
		res =  a.toArray(res);
		return res;
	}
	/**
	 * algo2:
	 * 	每个数组里平分一点。
	 *	对每个each[i],each[i+1] 
	 *  然后rand（）一个[(min-mid)/2, (max - mid)/2]
	 *  但是也可能对于a[5], 在mid=100， max=500， min=50的情况下， 减的太多而变成负值; 
	 * @return
	 */
	public int[] getEach2() {
		int mid = sum/ peo;
		Arrays.fill(each, mid);
		for (int i = 0; i < peo; i++) {
			int ran = rand2(mid);
			if(i == peo - 1){
				each[i] -= ran;
				each[0] += ran;
			}else{
				each[i] -= ran;
				each[1+i] += ran;
			}
		}
		int cnt=sum, max_i=0, min_i=0;
		cnt -= each[0];
		for (int i = 1; i < peo; i++) {
			if(each[i] > max){
				max_i = i;
			}
			if(each[i] < min){
				min_i = i;
			}
			cnt -= each[i];
		}
		if(cnt > 0){
			each[min_i] += cnt;
		}else{
			each[max_i] -= cnt;
		}
		return each;
	}
	private int rand() {
		return (int) (Math.random() * (max - min) + min);
	}
	
	private int rand2(int mid) {
		int down  = (min-mid)/2;
		int up = (max-mid)/2;
		return (int) (Math.random() * (up - down) + down);
	}

	public static void main(String[] args) {
		RedPacket redPacket = new RedPacket(10, 10, 10, 0.1);
		Double[] each2 = redPacket.getEach();
		double sum = (double) 0;
		for (Double f : each2) {
			System.out.println(f);
			sum += f;
		}
		System.out.printf("SUM: %.2f" , sum);
	}

}
