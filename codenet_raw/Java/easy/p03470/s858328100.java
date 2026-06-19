import java.util.Arrays;
import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n= scan.nextInt();
		int d[]=new int[n];
		for(int i=0;i<n;i++) {
			d[i]=scan.nextInt();
		}
		scan.close();

		Arrays.sort(d);
		int cnt=0;
		for(int i=1;i<n;i++) {
			if(d[i-1]!=d[i]) {
				cnt++;
			}
		}
		System.out.println(cnt);
	}

}