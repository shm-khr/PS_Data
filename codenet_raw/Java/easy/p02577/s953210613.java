import java.util.*;
class Main{
  int help(int k){
 int s=k;
    while(s>91){
      int p=0;
      while(k>0){
        p=p+k%10;
        k=k/10;
      }
      s=p;
    }
  }
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
   String n=sc.nextLine();
    int a=0;
    for(int i=0;i<n.length();i++){
    a=n.charAt(i)-'0';
    }
    if(a<91){
      if(a%9==0){
      System.out.println("Yes");
      }else{
        System.out.println("No");
      }}
    
    else{
      int b=help(a);
         if(b%9==0){
      System.out.println("Yes");
      }else{
        System.out.println("No");
      }
   
  }}}