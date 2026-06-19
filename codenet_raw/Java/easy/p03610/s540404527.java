import java.util.Arrays;
import java.util.*;
public class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
     String s = sc.next();
     int n = s.length();
     int m = 0;
     char[] cha = new char[n];
     for(int i=0;i<n;i++){
       if((i+1)%2!=0){
         cha[m] = s.charAt(i);
         m += 1; 
       }
     }
     String odd = String.valueOf(cha);
     System.out.println(odd);
  }
}
