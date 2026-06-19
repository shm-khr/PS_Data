/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */

public class Main
{
	Scanner sc = new Scanner(System.in);
	int q = sc.nextInt();
	for(int i = 0; i < q; ++i){
		BigInteger n1 = sc.nextBigInteger();
 		BigInteger n2 = sc.nextBigInteger();
 		BigInteger ans = n1.add(n2);
 		String sa = ans.toString();
 		if(sa.length() > 80){
 			System.out.println("overflow");	
 		}
 		else{
 			System.out.println(sa);
 		}
 	}	
}