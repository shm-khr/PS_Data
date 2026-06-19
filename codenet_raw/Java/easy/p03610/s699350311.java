import java.util.Scanner;

public class Main {
	
	public static void main(String[] args){
		
		Scanner scan = new Scanner(System.in);
		String str = scan.nextLine();
		int wordCount = str.length();
		String result = "";
		
		for(int i = 0; wordCount > i; i = i + 2){
			result = result + str.charAt(i);
		}
		System.out.println(result);
	}

}