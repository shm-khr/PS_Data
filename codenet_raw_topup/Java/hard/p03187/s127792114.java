import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int L = scan.nextInt();
		int N = scan.nextInt();
		int[] X = new int[N];
		int[] Y = new int[N];
		int ans=0;
		int point=0;
		for(int i=0;i<N;i++){
			X[i]=scan.nextInt();
			Y[N-1-i]=L-X[i];
		}
		int j=0;
		int k=0;
		for(int i=0;i<N;i++){
			int p = X[j]+point;
			int q = Y[k]-point;
			if(p>q){
				ans+=p;
				point=X[j]*-1;
				j+=1;
			}else{
				ans+=q;
				point=Y[k];
				k+=1;
			}
		}
		System.out.println(ans);
	}
}