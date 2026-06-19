import java.util.*;
public class Main{
	public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
      	int k = sc.nextInt();
      int x = (int) k/2;
      int y = x*2
	  if(y == k)System.out.println(k*k/4);
      else System.out.println((k-1)*(k+1)/4);
      sc.close();
    }
}
