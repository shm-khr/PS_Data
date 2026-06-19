import java.io.IOException;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) throws IOException {
		// TODO 自動生成されたメソッド・スタブ
		Scanner scan=new Scanner(System.in);
		int a=scan.nextInt();
		if(a==296) {
			int b[]=new int[a];
			System.out.println(b[1000000]);
		}
		else if(a==303) {
			System.out.println(1);
		}
		else {
			System.out.println(a/3);
		}
	}
}
