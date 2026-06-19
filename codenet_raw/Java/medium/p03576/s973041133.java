import java.util.*;
public class Main {
	
	public static class Pair implements Comparable<Pair>{
		int x, y;
		public Pair(int x, int y) {
			this.x = x; this.y = y;
		}
		@Override
		public int compareTo(Pair o) {
			return Integer.compare(this.x, o.x);
		}
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt(), K = sc.nextInt();
		
		Pair [] coords = new Pair[N+1];
		for(int i = 1; i<=N; i++) {
			int x = sc.nextInt(), y = sc.nextInt();
			coords[i] = new Pair(x, y);
		}
		
		coords[0] = new Pair(0,0);
		Arrays.sort(coords);
						
		long minArea = Long.MAX_VALUE;
		for(int i = 1; i<=N; i++) {
			int x1 = coords[i].x, y1 = coords[i].y;
			for(int j = i+1; j<=N; j++) {
				int x2 = coords[j].x, y2 = coords[j].y;
//				System.out.println(y1 + " " + y2);
				if((long)(Math.abs(x2-x1))*Math.abs(y2-y1) < minArea) {
					
					int point = 0;
					
					for(int k = 1; k<=N; k++) {
						if(coords[k].x <= Math.max(x2, x1) && coords[k].x >= Math.min(x1, x2) && coords[k].y >= Math.min(y2,y1) && coords[k].y <= Math.max(y2,y1)) {
							point++;
						}
					}
					if(point >= K) minArea = (long) (Math.abs(x2-x1))*Math.abs(y2-y1);
				}
				
			}
		}
		
		System.out.println(minArea);
	}

}
