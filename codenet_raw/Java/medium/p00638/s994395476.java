import java.util.Arrays;
import java.util.Scanner;


public class Main {
	
	public static class Path implements Comparable<Path>{
		int prize;
		int size;
		
		public Path(int prize, int size) {
			super();
			this.prize = prize;
			this.size = size;
		}

		@Override
		public int compareTo(Path arg0) {
			if(this.prize != arg0.prize){
				return this.prize - arg0.prize;
			}else if(this.size != arg0.size){
				return this.size - arg0.size;
			}else{
				return 0;
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while(true){
			final int n = sc.nextInt();
			
			if(n == 0){
				break;
			}
			
			Path[] array = new Path[n];
			
			for(int i = 0; i < n; i++){
				array[i] = new Path(sc.nextInt(), sc.nextInt());
			}
			
			Arrays.sort(array);
			
			boolean over = false;
			int cur = 0;
			for(int i = 0; i < n; i++){
				cur += array[i].prize;
				
				if(array[i].size < cur){
					over = true;
					break;
				}
			}
			
			if(over){
				System.out.println("No");
			}else{
				System.out.println("Yes");
			}
		}
	}

}