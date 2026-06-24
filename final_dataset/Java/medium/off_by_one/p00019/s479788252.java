import java.math.*;
import java.io.*;
class hoge{
 public static void main(String args[])throws IOException{
  int i,n;
  BigInteger fact=BigInteger.valueOf(1);
  BufferedReader br=
   new BufferedReader(new InputStreamReader(System.in));
  n=Integer.parseInt(br.readLine());
  for(i=2;i<=n;i++) fact=fact.multiply(BigInteger.valueOf(i));
  System.out.println(fact);
 }
}