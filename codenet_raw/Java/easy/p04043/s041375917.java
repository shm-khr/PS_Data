import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		int[] a = new int[3];
		for(int i=0;i<3;i++){
			a[i] = sc.nextInt();
		}
		sc.close();
		int c5=0,c7=0;
		for(int i=0;i<3;i++){
			if(a[i]==5){
				c5++;
			}else if(a[i]==7){
				c7++;
			}else{
				System.out.println("NO");
				return;
			}
		}
		if(c5==2&&c7==1){
			System.out.println("YES");
			return;
		}
	}

}
