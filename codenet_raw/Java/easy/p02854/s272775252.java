import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int sum = 0;
		int sum1 = 0;
		int count = 0;
		int ans = 0;
 		Scanner scanner = new Scanner(System.in);
 		int N = scanner.nextInt();
 		int Number[] = new int[N];
 		
 		for (int i = 0; i < N; i++) {
 	 		int a = scanner.nextInt();
 	 		Number[i] = a;
 	 		sum += a;
 		}
 		
 		int b = sum/2;
 		for (int i = 0; i < N; i++) {
 	 		sum1 += Number[i];
 	 		if (sum1 > b) {
 	 			count = i;
 	 			break;
 	 		}
 		}
 		
 		if (count == N) {
 			ans = 2 * Number[N] - sum1;
 		} else if (count == 0) {
 			ans = 2 * sum1 - sum;
 		} else {
 		
 			int x = sum1 - Number[count];
 			int y = sum - sum1;
 		
// 			System.out.println(x);
// 			System.out.println(y);
// 			System.out.println(Number[count]);
 			if (x > y) {
 				ans = Number[count] - (x - y);
 			} else {
 				ans = Number[count] - (y - x);
 			}
 		}
 		System.out.println(ans);
	}
}
