import java.io.*;
import java.util.*;
class Main{
    public static void main(String[] args){
	try{
	    BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
	    int sum=1, n = Integer.valueOf(sc.readLine());
	    for(int i=2; i<=n; i++)
		sum*=i;
	    System.out.println(sum);
	}catch(Exception e){
	    System.out.println("Error");
	}
    }
}