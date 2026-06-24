import java.util.Scanner;

public class Main
{
	
	public static void main(String... args)
	{
		Scanner scan = new Scanner(System.in);
		int f = scan.nextInt();
		f = Math.max(1, f);
		f = Math.min(20, f);
		int tmp = 1;
		for(int i = 1; i <= f; i++)
		{
			tmp *= i;
		}
		System.out.println(tmp);
	}

}