import java.util.*;


public class Main {

	public static void main(String[] args) {
		
		int a = new java.util.Scanner(System.in).nextInt();
		int b = new java.util.Scanner(System.in).nextInt();
		if(a + b == 15) 
			System.out.println('+');
		else if(a * b == 15) 
			System.out.println('*');
		else 
			System.out.println('x');
	}

}
