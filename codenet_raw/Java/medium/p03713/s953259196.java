import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		ArrayList<Integer> num = new ArrayList<Integer>();
		ArrayList<String> param = new ArrayList<String>();
		int system = 0; // 文字の空白区切り 0:ON 1:OFF

		while (sc.hasNext()) {
			if (sc.hasNextInt()) {
				num.add(sc.nextInt());
			} else {
				if (system == 0)
					param.add(sc.next());
				if (system == 1)
					param.add(sc.nextLine());
			}
		}
		Method(num, param);
	}

	static void Method(ArrayList<Integer> num, ArrayList<String> param) {
		BigInteger area = BigInteger.valueOf(num.get(0)).multiply(BigInteger.valueOf(num.get(1)));
		BigInteger min = new BigInteger(String.valueOf(Math.min(num.get(0), num.get(1))));;
		BigInteger max = new BigInteger(String.valueOf(Math.max(num.get(0), num.get(1))));
		BigInteger big = new BigInteger("0");
		BigInteger answer = new BigInteger("999999999999999999999999");

		BigInteger two = new BigInteger("2");
		BigInteger three = new BigInteger("3");


		if(area.remainder(new BigInteger("3")).compareTo(BigInteger.ZERO) == 0){
				answer = big;
		}else if(area.remainder(new BigInteger("2")).compareTo(BigInteger.ZERO) == 0){
			for(int i = 0; i < max.intValue(); i++){
				big = (new BigInteger(String.valueOf(i))).multiply(min);
				big = big.subtract((area.subtract(big)).divide(two));
				if(big.abs().compareTo(answer) < 0) answer = big.abs();
			}

		}else{
			for(int i = 0; i < max.intValue(); i++){
				big = new BigInteger(String.valueOf(i)).multiply(min);
				if(big.abs().compareTo(area.divide(three)) < 0){
					big = area.subtract(big).subtract((area.subtract(big)).divide(min).multiply(min.divide(two))).subtract(big);
					if(big.abs().compareTo(answer) < 0) answer = big.abs();
				} else {
					big = big.subtract((area.subtract(big)).divide(min).multiply(min.divide(two)));
					if(big.abs().compareTo(answer) < 0) answer = big.abs();
				}
			}
		}
		System.out.println(answer);
		//System.out.println(small);
		//System.out.println(big);
	}
}