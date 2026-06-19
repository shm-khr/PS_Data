import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		final long S = h*w;
		long s1,s2,s3;
		long ans = Long.MAX_VALUE;
		for(int i = 1; i < h; i++) {//一つの長方形のhについて全探索
			s1 = w*i;
			s2 = w*((h-i)/2);
			s3 = S-s1-s2;
			ans = Math.min(ans, Math.abs(Math.max(s1, Math.max(s2, s3))-Math.min(s1, Math.min(s2, s3))));
			s2 = (h-i)*(w/2);
			s3 = S-s1-s2;
			ans = Math.min(ans, Math.abs(Math.max(s1, Math.max(s2, s3))-Math.min(s1, Math.min(s2, s3))));
		}
		for(int i = 1; i < w; i++) {
			s1 = h*i;
			s2 = h*((w-i)/2);
			s3 = S-s1-s2;
			ans = Math.min(ans, Math.abs(Math.max(s1, Math.max(s2, s3))-Math.min(s1, Math.min(s2, s3))));
			s2 =(w-i)*(h/2);
			s3 = S-s1-s2;
			ans = Math.min(ans, Math.abs(Math.max(s1, Math.max(s2, s3))-Math.min(s1, Math.min(s2, s3))));
		}
		System.out.println(ans);
	}
}