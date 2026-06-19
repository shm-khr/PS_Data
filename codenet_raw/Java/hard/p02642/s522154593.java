import java.util.Scanner;
import java.util.Arrays;


public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();
    int[] a = new int[N];

    for(int i = 0; i<N ; i++){
      a[i] = scanner.nextInt();
    }

    Arrays.sort(a);
    
    int count = 1;
    int flag = 0;
    if(N==1){
      System.out.println(count);
      scanner.close();
      return;
    }
    if(a[0] == a[1]){
      count = 0;
    }

    for(int i=1; i<N; i++){
      for(int j=0; j<=i-1; j++){
        if(a[i]%a[j] == 0){
          flag  = 1;
          break;
        }
      }
      if(flag == 0 && (i+1 == N || (i+1<N && a[i]!=a[i+1]))){
        count += 1;
      }else{
        flag = 0;
      }
    }

    System.out.println(count);
    scanner.close();
    return;
    

  }
}
