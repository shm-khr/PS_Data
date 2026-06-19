import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
      	int count = 0;
		int K = sc.nextInt();
		for(int i = 2;i <= K; i = i + 2){
          for(int j = 1;j <= K; j = j + 2){
            count++;
          }
        }
	}
}