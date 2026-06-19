import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		try (Scanner sc = new Scanner(System.in)) {
			int n = sc.nextInt();
			int[] a = new int[n];
			for(int i = 0; i < n; i++) {
				a[i] = i + 1;
			}
			recursive(a, 0);
		}
	}
	private static void recursive(int[] a,int j){  
		if(j==a.length){ 
			for(int i = 0; i < a.length - 1; i++) {
				System.out.print(a[i] + " ");
			}
			System.out.println(a[a.length - 1]);
			return;  
		}  
		for(int i=j;i<a.length;i++){  
			int t=a[i];  
			for(int k=i;k>j;k--)  
				a[k]=a[k-1];  
			a[j]=t;  
			recursive(a,j+1);  
			for(int k=j;k<i;k++)  
				a[k]=a[k+1];  
			a[i]=t;  
		}  
	}
}
