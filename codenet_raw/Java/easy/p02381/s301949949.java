import java.util.Scanner;

public class mathfunctuions {
	  public static void main(String[]args){
		    Scanner sc = new Scanner(System.in);
		    int ten[];
		    int i=0;
		    int sum=0;
		    int m=0;
		    int x=0;
		    int A=0;
		    ten = new int[1000];
		    	int n=sc.nextInt();
		    	for(i=0;i<n;++i)
		    	{
		    		ten[i]=sc.nextInt();
		    		sum=sum+ten[i];
		    	}
		    	m=sum/n;
		    	for(i=0;i<n;++i)
		    	{
		    		x=x+(ten[i]-m)*(ten[i]-m);
		    	}
		    	A=x/n;
		    	double a=Math.sqrt(A);
		    	System.out.println(a);
		    	sc.close();
		    }
}
