import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while(true){
			int n = sc.nextInt();
			if(n==0) break;
			
			int[] a = new int[n];
			int[] b = new int[n];
			PriorityQueue<Integer> p = new PriorityQueue<Integer>();
			PriorityQueue<Integer> q = new PriorityQueue<Integer>();
			
			for(int i=0;i<n;i++){
				a[i] = sc.nextInt();
				b[i] = sc.nextInt();
				p.add(a[i]);
			}
			
			int x, y;
			int sum = 0;
			boolean flag = true;
			while(p.size()!=0){
				x = p.poll();
				for(int i=0;i<n;i++){
					if(a[i]==x) q.add(b[i]);
				}
				while(q.size()!=0){
					y = q.poll();
					sum += x;
					if(sum>y){
						flag = false;
						break;
					}
				}
				if(flag==false) break;
			}
			if(flag==true) System.out.println("Yes");
			else System.out.println("No");
		}	
	}	
}