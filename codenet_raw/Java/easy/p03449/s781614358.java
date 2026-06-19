import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int A[][] = new int[2][N];
        int ans = 0;
        int result0 = 0;
        int result1 = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = sc.nextInt();
            }
        }
        lavel:for (int i = 0; i < 2;) {
            for (int j = 0; j < N;) {
                result0 = 0;
                result1 = 0;
                ans += A[i][j];
                if (i == 0) {
                    for (int n = j+1; n < N; n++) {
                        result0 += A[0][n];
                    }
                    result0 += A[1][N - 1];
                }
                for (int n = j; n < N; n++) {
                    result1 += A[1][n];
                }
                if (result0 < result1) {
                    if(i==0){
                    i++;
                    }else{
                        j++;
                    }
                } else {
                    j++;
                }
                if(i==1&&j==N-1){
                    ans+=A[1][N-1];
                    break lavel;
                }
            }
        }
        System.out.println(ans);
    }
}