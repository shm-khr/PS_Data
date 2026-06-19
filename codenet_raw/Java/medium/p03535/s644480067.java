import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0;i < n;i ++) {
			a[i] = in.nextInt();
		}
		
		int b = 24 - a[n - 1];
		int c = b - a[n - 2];
		System.out.println(c);
		
			}

}
