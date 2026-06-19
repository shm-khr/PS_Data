import java.util.Scanner;
class Main{
  public static void main(String args[]){
    Scanner scan=new Scanner(System.in);
    int a=scan.nextInt();
    int b=scan.nextInt();
    int c=scan.nextInt();
    int d=(int)(Math.floor(b/a));
    int d=Math.max(d,c);
    System.out.println(d);
  }
}