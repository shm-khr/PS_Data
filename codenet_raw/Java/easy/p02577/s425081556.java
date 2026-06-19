import java.util.Scanner;

class B{
  public static void main(String args[])
  {
    int N;
    int sum = 0;
    int dig;

    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();

    while(N > 0){
      dig = N % 10;
      sum = sum + dig;
      N = N/10;
    }

    if (sum%9 == 0){
      System.out.println("Yes");
    }else if(sum%9 != 0){
      System.out.println("No");
    }


    return;
  }
}