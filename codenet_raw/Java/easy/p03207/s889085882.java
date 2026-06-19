import java.util.Scanner;

public class Main{
public static void main(){
  int N=0;
  int Max=0;
  Scanner s=new Scanner(System.in);
  int all=0; 
  int save=0;
 
  N=s.nextInt();
 
  for(int i=0;i<N;i++){
   save=s.nextInt();
   all+=save
 
    if(Max<save){
     Max=save;
   }
 
  }
 all-=Max;
 all+=Max/2;
 }
}