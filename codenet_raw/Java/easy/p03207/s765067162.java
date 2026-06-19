import java.util.*;
public class Main {
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		//入力
		int N = sc.nextInt();
		int p[]=new int[N];
		for(int i=0;i<N;i++)
		{
			p[i]=sc.nextInt();
		}
		//変数
		int answer=0;
		int max=0;
		//処理
		for(int i=0;i<N;i++)
		{
			max=Math.max(max,p[i]);
		}
		for(int i=0;i<N;i++)
		{
			if(max==p[i])
			{
				p[i]=max/2;
				System.out.println(p[i]);
				break;
			}
		}
		for(int i=0;i<N;i++)
		{
			answer+=p[i];
		}
		// 出力
		//System.out.println(max);
		//System.out.println("");
		System.out.println(answer);
	}
}