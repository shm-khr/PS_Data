import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String A = sc.next();
		sc.close();
		int ans = 1;
		for(int i=0; i<A.length()-1; i++) {
			for(int j=i+1; j<A.length(); j++) {
				if(A.charAt(i)!=A.charAt(j)) {
					ans++;
				}
			}
		}
		System.out.println(ans);
	}

}
