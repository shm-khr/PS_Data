import java.util.*;
public class Main {	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		int n = sc.nextInt();

		System.out.println(core(h,w,n));
	}
	
	static int core(int h , int w, int n ) {
		int max = Math.max(h,w);
		return (int)Math.floor(  (double)n /(double) max);
	
	}	
}
