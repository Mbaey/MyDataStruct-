package com.test;

public class Ten2X {
	public static void main(String[] args) {
		int d = 5555, x = 16;
		String a = Ten2XX(d, x);
		System.out.println(a);

	}

	public static char forDigit(int d, int x) {
		if (d < 10) {
			return (char) (d + '0');
		} else {
			return (char) (d - 10 + 'A');
		}
	}

	public static String Ten2XX(int d, int x) {
		String ans = "";
		while (d >= x) {
			ans += forDigit(d % x, x);
			d /= x;
		}
		ans += forDigit(d, x);

		int len = ans.length();
		String result = "";
		for (int i = len - 1; i >= 0; i--) {
			result += ans.charAt(i);
		}
		return result;
	}
}
