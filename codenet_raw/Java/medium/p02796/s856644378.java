import java.util.*;
 
public class Main {
 
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);				
		int a = sc.nextInt();		
		int robot[][] = new int[a][2];		
		for(int i=0;i<n;i++) {
			int b = sc.nextInt(), c = sc.nextInt();
			robot[i][0] = b-c;
			robot[i][1] = b+c;
		}		
		Arrays.sort(robot, Comparator.comparingInt(arr[0] -> arr[1]));
		
		int d = 0;
		int e = Integer.MIN_VALUE;
		for(int i=0;i<a;i++) {
			if(robot[i][0] >= e) {
				d++;
				e = robot[i][1];
			}
		}		
		System.out.println(d);				
	} 
}