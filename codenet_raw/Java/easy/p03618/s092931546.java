import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String A = sc.next();
		sc.close();
//		int ans = 1;
//		for(int i=0; i<A.length()-1; i++) {
//			for(int j=i+1; j<A.length(); j++) {
//				if(A.charAt(i)!=A.charAt(j)) {
//					ans++;
//				}
//			}
//		}
		Map<Character, Long> acount = new HashMap<Character, Long>();
		for(int i=0; i<A.length(); i++) {
			if(acount.containsKey(A.charAt(i))) {
				acount.put(A.charAt(i), acount.get(A.charAt(i))+1);
			} else {
				acount.put(A.charAt(i), (long) 1);
			}
		}
		long ans = A.length()*(A.length()-1)/2;
		for(Map.Entry<Character, Long> entry : acount.entrySet()) {
			long temp = entry.getValue();
			ans -= temp*(temp-1)/2;
		}
		System.out.println(ans+1);
	}

}
