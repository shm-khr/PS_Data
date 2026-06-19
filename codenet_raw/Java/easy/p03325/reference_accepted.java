	import java.util.Scanner;

	public class Main {

		static long mod = 1000000007;

		public static void main(String[] args) {

			Scanner sc = new Scanner(System.in);
			String[] t = sc.nextLine().split(" ");
			int n  	   = Integer.parseInt(t[0]);
			int ans    = 0;
			//long k = Long.parseLong(t[1].replaceAll("\\.", ""));

			String[] r = sc.nextLine().split(" ");
			for(int i = 0; i < n; i ++) {
				ans += twoThree(Integer.parseInt(r[i]));
			}

			System.out.println(ans);
		}

		public static int twoThree(int x) {

			int cnt = 0;
			while(x % 2 == 0) {

				if(x % 2 == 0) {
					x /= 2;
				}
				cnt++;
			}
			return cnt;
		}
	}
