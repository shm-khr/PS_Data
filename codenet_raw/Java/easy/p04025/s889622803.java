
import java.util.*; 
public class Main {
    public static void main(String[] args)  {
      Scanner in = new Scanner(System.in);
           int n = in.nextInt();
           TreeSet<Integer> ts = new TreeSet<Integer>();
           for (int i =0;i<n;i++) {
        	   ts.add(in.nextInt());}
           
          if (ts.size()==1) {
        	  System.out.println(0);}
          else {
        	  System.out.println(ts.last());
          }
    }
 
}