import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		if((str.contains("N") && !str.contains("S")) || (str.contains("S") && !str.contains("N"))){
			System.out.println("NO");
			return;
		}
		if((str.contains("E") && !str.contains("W")) || (str.contains("W") && !str.contains("E"))){
			System.out.println("NO");
			return;
		}
		System.out.println("YES");	 
	}
