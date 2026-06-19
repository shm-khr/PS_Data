import java.util.Scanner;

class Main {
	public static void main(String[] $) {
		Scanner sc = new Scanner(System.in);
		String s=sc.next();
		boolean flag=true;
		int j=s.length();
		for(int i=0;i<s.length()/2;i++) {
			if(!s.substring(i, i+1).equals(s.substring(j-1, j))) flag=false;
			j--;
		}
		j=s.length()/2;
		for(int i=0;i<s.length()/4;i++) {
			if(!s.substring(i, i+1).equals(s.substring(j-1, j))) flag=false;
			j--;
		}
		j=s.length();
		for(int i=s.length()/2+2;i<s.length()/4*3;i++) {
			if(!s.substring(i, i+1).equals(s.substring(j-1, j))) flag=false;
			j--;
		}
		if(flag) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}