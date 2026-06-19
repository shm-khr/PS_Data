import java.util.*;
class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		long A = sc.nextInt();
		long B = sc.nextInt();
		long C = sc.nextInt();
		long K = sc.nextInt();
		
		if(A >= K)
		{
			System.out.println(A);
		}
		else if(A + B >= K)
		{
			System.out.println(A);
		}
		else
		{
			long n = K - (A + B);
			System.out.println(A - n);
		}
	}
}