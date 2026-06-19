import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int len = s.length();
		int ans=0;
		String a="",b="";
		for(int i=0;i<(len-1)/2;i++) {
			a+=(char)s.charAt(i);
		}
		for(int i=((len+3)/2-1);i<len-1;i++) {
			b+=(char)s.charAt(i);
		}
	for(int i=0;i<(len-1)/4;i++) {
		if((char)a.charAt(i)!=(char)a.charAt((len-1)/2-1-i)) {
			ans=-1;
			break;
		}
		if((char)b.charAt(i)!=(char)b.charAt((len-1)/2-1-i)) {
			ans=-1;
			break;
		}
	}
	if(ans==0) {
		System.out.println("Yes");
	}else {
		System.out.println("No");
	}
	}
}
