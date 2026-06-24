import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter ou = new PrintWriter(System.out);
		int[] a = new int[3];
		int q = 0;
		for(int i = 0 ; i < 3 ; i++){
			a[i] = Integer.parseInt(sc.next());
			if(a[i] % 2 == 0) q++;
		}
		sc.close();
		int yono = 0;
		if(q % 3 != 0) yono++;
		for(int i = 0 ; i < 3 ; i++) a[i] = a[i] / 2;
		int max = Math.max(a[0] , Math.max(a[1] , a[2]));
		for(int i = 0 ; i < 3 ; i++) yono += max - a[i];
		ou.print(yono + "\n");
		ou.flush();
    }
}