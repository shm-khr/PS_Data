import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		List<Integer> nums = new ArrayList<Integer>();
		for (int i=0; i<N; i++) {
			int c = sc.nextInt();
			nums.add(c);
		}

		List<Integer> range = new ArrayList<Integer>();
		for (int i=1; i<N+1; i++) {
			range.add(i);
		}

		boolean wareru = true;
		int cnt = 0;
		for (int i=0; i<range.size(); i++) {
			int a = nums.get(i);
			for (int j=0; j<nums.size(); j++) {
				int b = nums.get(j);
				if(i!=j && a % b ==0) {
					wareru = false;
					break;
				} else {
					wareru = true;
				}
			}

			if (wareru==true) {
				cnt += 1;
			}
		}
		System.out.println(cnt);

	}

}