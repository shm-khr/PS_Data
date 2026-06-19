import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		try (Scanner sc = new Scanner(System.in)) {
			StringBuilder str = new StringBuilder();
			int n = sc.nextInt();
			for(int i = 1; i < n + 1; i++) {
				str.append(i);
			}
			permutation(str.toString(),"");
		}
	}
	public static void permutation(String q, String ans){
		if(q.length() <= 1) {
			for(int i = 0; i < ans.length(); i++) {
				System.out.print(ans.charAt(i) + " ");
			}
			System.out.println(q);
		}
		else {
			for (int i = 0; i < q.length(); i++) {
				permutation(q.substring(0, i) + q.substring(i + 1), ans + q.charAt(i));
			}
		}
	}
}
