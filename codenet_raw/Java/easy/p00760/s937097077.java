import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		
		for(int i = 0; i < n; i++){
			
			int y = scan.nextInt();
			int m = scan.nextInt();
			int d = scan.nextInt();
			
			int s = y / 3;
			
			int sum_d = s * 200;
			
			sum_d += (y - s) * 195;
			
			sum_d += (m / 2) * 19;
			
			sum_d += (m - (m / 2)) * 20;
			
			sum_d += d;
			
			sum_d = 196686 - sum_d;
			
			System.out.println(sum_d);
			
			
		}
		
		
		
	}
}