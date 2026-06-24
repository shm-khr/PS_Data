import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

/**
 *http://abc075.contest.atcoder.jp/tasks/abc075_d
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		final int K = sc.nextInt();
		Point[] points = new Point[N];
		for(int i=0; i<N; i++){
			points[i] = new Point(sc.nextLong(), sc.nextLong());
		}
		sc.close();
		
		long ans = Long.MAX_VALUE;
		
		Arrays.sort(points, new Comparator<Point>() {
			public int compare(Point p1, Point p2) {
				if(p1.x==p2.x) return 0;
				return p1.x - p2.x > 0 ? 1 : -1;
			}
		});
		for(int i=0; i<N-K+1; i++){
			long max = 0;
			long min = Long.MAX_VALUE;
			for(int j=i; j<i+K; j++){
				max = Math.max(max, points[j].y);
				min = Math.min(min, points[j].y);
			}
			ans = Math.min((points[i+K-1].x-points[i].x)*(max-min), ans);
		}
		
		
		Arrays.sort(points, new Comparator<Point>() {
			public int compare(Point p1, Point p2) {
				if(p1.y==p2.y) return 0;
				return p1.y - p2.y > 0 ? 1 : -1;
			}
		});
		
			
		for(int i=0; i<N-K+1; i++){
			long max = 0;
			long min = Long.MAX_VALUE;
			for(int j=i; j<i+K; j++){
				max = Math.max(max, points[j].x);
				min = Math.min(min, points[j].x);
			}
			ans = Math.min((points[i+K-1].y-points[i].y)*(max-min), ans);
		}
		
		System.out.println(ans);

	}
	
	static class Point{
		public Point(long x, long y) {
			this.x = x;
			this.y = y;
		}
		long x;
		long y;
	}

}