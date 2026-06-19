import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int k = sc.nextInt();
		int res=0;
		k=k-a;
		if(k<=0) {
			System.out.println(a);
		}
		else{
			k=k-b;
			if(k<=0) {
				System.out.println(a);
			}
			else {
				System.out.println(a-k);
			}
			
		}
	}

}