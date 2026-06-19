
import java.util.Scanner;


public class Main{
	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		for (int i= 1; i < N; i++){
			

		}
		int i = sc.nextInt();

			if (i%2 == 0) {

				if (i%3 == 0) {
					System.out.print("APPROVED");
				}else{
					if(i%5 == 0) {
						System.out.print("APPROVED");
					}else {
						System.out.print("DENIED");
					}
					
				}
				
			}
	}

}

