

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;


public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int n = Integer.parseInt(br.readLine());
            StringTokenizer str = new StringTokenizer(br.readLine(), " ");
            long[] A = new long[n];
            for(int i = 0; i < n ; i++) {
                A[i] = Integer.parseInt(str.nextToken());
            }
            long c = func(A,n);
            System.out.println(c);
        } catch (IOException e) {
            System.out.println("error");
        }
    }
    static long func(long[] A,int n){
        long sum = 0;
        long c1 = 0,c2 = 0;
        for(int i = 0; i < n; i++){
            if(i%2==0 && sum+A[i]>=0){   //次は負
                c1 += (sum+A[i] + 1);
                sum = -1;
            }
            else if(i%2==1 && sum+A[i]<=0){
                c1 += 1+(-sum-A[i]);
                sum = 1;
            }
            else{
                sum+=A[i];
            }
        }
        sum = 0;
        for(int i = 0; i < n; i++){
            if(i%2==0 && sum+A[i]<=0){   //次は負
                c2 += (sum+A[i] + 1);
                sum = 1;
            }
            else if(i%2==1 && sum+A[i]>=0){
                c2 += 1+(-sum-A[i]);
                sum = -1;
            }
            else{
                sum+=A[i];
            }
        }

        return Math.min(c1,c2);
    }
}