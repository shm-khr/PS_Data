import java.io.*;
import java.util.*;
import java.math.*;
class Main
{ 
	public static int M = 1000000007;
    public static void main(String[] args)throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String[] s = br.readLine().split(" ");	
        int n = Integer.parseInt(s[0]);
        int k = Integer.parseInt(s[1]);
        String[] str = br.readLine().split(" ");
        out.println((n/k)+(n%k));
        out.flush();
    }
    /** Loops
    *	i: for(int i=0;i<n;i++)
    *	j: for(int j=0;j<n;j++)
    *	k: for(int k=0;k<n;k++)

    *	ArrayList<Integer> arr1 = new ArrayList<>();
    
    * 	HashMap
    *	HashMap<Integer, Integer> hm = new HashMap<>();
    * 	for (Map.Entry<String,String> entry : hm.entrySet()) 
    		out.println(entry.getValue());
    
    *	Count frequencies
    	for(int i=0;i<n;i++)
        {
            Integer c = hm.get(Integer.parseInt(s[i]));
            if(c==null)
                hm.put(Integer.parseInt(s[i]),1);
            else
                hm.put(Integer.parseInt(s[i]),++c);
        }
	**/		
    public static long modularExpo(long x,long n,int M)
	{
		long result=1;
		while(n>0)
		{
		    if(n%2==1)
		        result=(result*x)%M;
		    x=(x*x)%M;
		    n=n/2;
		}	
		return result;												
	}
	//FLT, only when a and M are co-prime
	public static long modInverse(int a,int M)
	{
		long g = gcd(a,M);
		if(g!=1)
			return -1;
	    return modularExpo(a,M-2,M);
	}
	public static long gcd(int a, int b) 
	{
	    if(b==0)
	        return a;
	    else
	        return gcd(b, a % b);
	}
}