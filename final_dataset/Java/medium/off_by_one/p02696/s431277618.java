import java.util.Scanner;
 
class Main {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextInt();
        long B = sc.nextInt();
        long N = sc.nextInt();
        long max = 0;
        
        for(long x  = 1; x <= N; x++) {
        	long tmpMax = (long) Math.floor((double)A * ((double)x/(double)B - Math.floor((double)x/(double)B)));
        	if(tmpMax > max) {
        		max = tmpMax;
        	}        	      	
        }
        
        System.out.print(max);
	}
}

