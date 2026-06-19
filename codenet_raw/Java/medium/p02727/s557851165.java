import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	private static List<Long> getStrings(Scanner sc, long num) {
		List<Long> stringList = new ArrayList<>();
		while(num>0) {
			long nextInt = sc.nextLong();
			stringList.add(nextInt);
			num--;
		}
		return stringList;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long x = sc.nextLong();
		long y = sc.nextLong();
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		List<Long> aArray = getStrings(sc, a);
		List<Long> bArray = getStrings(sc, b);
		List<Long> cArray = getStrings(sc, c);
		Collections.sort(aArray);
		Collections.sort(bArray);
		Collections.sort(cArray);
		Collections.reverse(aArray);
		Collections.reverse(bArray);
		Collections.reverse(cArray);

		long sum = 0;
		int i =0;
		int j =0;
		int k =0;
		while (x > 0 || y >0){
			if (k < c) {
				if (x>0 && y>0) {
					if (aArray.get(i) >= cArray.get(k) && bArray.get(j) >= cArray.get(k)) {
						sum+=aArray.get(i);
						sum+=bArray.get(j);
						i++;
						j++;
						x--;
						y--;
						continue;
					} else if (aArray.get(i) >= cArray.get(k)) {
						sum+=aArray.get(i);
						sum+=cArray.get(k);
						i++;
						k++;
						x--;
						y--;
						continue;
					} else if (bArray.get(j) >= cArray.get(k)) {
						sum+=bArray.get(j);
						sum+=cArray.get(k);
						j++;
						k++;
						x--;
						y--;
						continue;
					}
				} else if (x>0) {
					if (aArray.get(i) >= cArray.get(k)) {
						sum+=aArray.get(i);
						i++;
						x--;
						continue;
					} else {
						sum+=cArray.get(k);
						k++;
						x--;
						continue;
					}
				} else {
					if (bArray.get(j) >= cArray.get(k)) {
						sum+=bArray.get(j);
						j++;
						y--;
						continue;
					} else {
						sum+=cArray.get(k);
						k++;
						y--;
						continue;
					}
				}

			} else {
				if (x >0 && y>0) {
					sum+=aArray.get(i);
					sum+=bArray.get(j);
					i++;
					j++;
					x--;
					y--;
					continue;
				} else if (x>0) {
					sum+=aArray.get(i);
					i++;
					x--;
					continue;
				} else {
					sum+=bArray.get(j);
					j++;
					y--;
					continue;
				}

			}

		}
		System.out.println(sum);
	}

}
