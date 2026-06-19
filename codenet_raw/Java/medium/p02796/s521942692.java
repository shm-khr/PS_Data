import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		HashMap<Integer,Integer> map = new HashMap<>();
		int[] q = new int[n]; // X + L
		for(int i = 0 ; i < n ; i++) {
			int x = sc.nextInt();
			int l = sc.nextInt();
			map.put(x + l , map.getOrDefault(x + l, -1000000007) < x - l ? x - l : map.get(x + l));
			q[i] = x + l;
		}
		sc.close();
		Arrays.sort(q);

		int number = 0;
		int max = -1000000007;
		for(int i = 0 ; i < n ; i++) {
			if(max <= map.get(q[i])) {
			max = q[i];
			map.put(q[i],1000000007);
			number++;
			}

		}

			System.out.println(number);


	}

}
