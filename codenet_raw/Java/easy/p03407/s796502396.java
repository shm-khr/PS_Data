import java.util.Scanner;

public class main {
	public static void main(String[] args){
    	Scanner sc =new Scanner(System.in);
    	int a = sc.nextInt();
    	int b = sc.nextInt();
    	double c= sc.nextInt();	
    	if(a + b >= c) {
			System.out.println("Yes");
		}
    	else {
    		System.out.println("No");
    	}
    	
    }
}
