import java.util.Scanner;

class Location {
	int locX=0;
	int locY=0;
	int candy=0;
}

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int[][] a = new int [2][n];
		
		for(int i =0 ; i<2 ; i++) {
			for(int j =0 ; j<n ; j++) {
				a[i][j]=sc.nextInt();
			}	
		}
		Location loc1 = new Location();
		while(loc1.locX != 1 && loc1.locY != n-1) {
			int sum1=a[1][n-1], sum2=a[1][n-1];
			loc1.candy +=a[loc1.locX][loc1.locY];
//			System.out.println("locY:"+loc1.locY);
//			System.out.println("candy:"+loc1.candy);
			for(int i =loc1.locY+1; i<n ; i++) {
				sum1 += a[0][i];
			}
			for(int i = loc1.locY; i<n-1; i++) {
				sum2 += a[1][i];
			}
//			System.out.println("sum1:"+sum1);
//			System.out.println("sum2:"+sum2);
			if(sum1>= sum2 || a[1][loc1.locY]<=a[0][loc1.locY+1]) {
				loc1.locY++;
			} else {
				loc1.locX++;
			}
			if(loc1.locY==(n-1)) {
				loc1.candy += sum1;
				break;
			}
			if(loc1.locX==1 ) {
				loc1.candy+=sum2;
				break;
			}
			if(loc1.locY==n-1) {
				loc1.candy += a[1][n-1];
			}

			
		}
		if(loc1.candy==0 && loc1.locY==n-1) {
			loc1.candy=a[0][0]+a[1][0];
		}
		

		System.out.println(loc1.candy);
		
		sc.close();

	}

}
