
import java.util.*;
import java.lang.*;

class Main {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        long A[] = new long[N];
        for(int i = 0; i < N; i++){
        A[i] = sc.nextInt();
        }
        Arrays.sort(A);

        for(int i = 0; i < M; i++){
            A[N-1] = A[N-1] / 2;
            for(int j = 0; j < i+1; j++){
                if(A[N-1-j] < A[N-2-j]){
                    long temp = A[N-1-j];
                    A[N-1-j] = A[N-2-j];
                    A[N-2-j] = temp;
                }
            }
        }

        long minSum = 0;
        for(int i = 0; i < N; i++){
            minSum += A[i];
        }

        System.out.println(minSum);

    }
}





