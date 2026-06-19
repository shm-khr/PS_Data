import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        sc.close();

        boolean nodec = true;
        for(int i=1; i<n; i++){
            if(a[i] <= a[i-1]) nodec = false;
        }
        if(nodec){
            System.out.println(1);
            return;
        }

        
        int m = 31;
        int l = 0, r = 210000;
        int mid = 2;
        int[] dec = new int[m];

        out: while(r-l > 1){
            mid = (l+r)/2;
            dec = new int[m];
            nout: for(int i=1; i<n; i++){
                if(a[i] <= a[i-1] && a[i] < m){
                    if(dec[a[i]-1] < mid){
                        dec[a[i]-1]++;
                    }else{
                        int pos = a[i]-1;
                        
                        while(pos > 0){
                            dec[pos-1]++;
                            for(int j=pos; j<m; j++){
                                dec[j] = 0;
                            }
                            if(dec[pos-1] <= mid) continue nout;
                            pos--;
                        }
                        l = mid;
                        continue out;
                    }
                }
            }
            r = mid;
        }

        System.out.println(r+1);

        // int m = 400000;
        // int[] dec = new int[m];
        // for(int i=1; i<n; i++){
        //     if(a[i] <= a[i-1] && a[i] < m) dec[a[i]-1]++;
        // }

        // int l=0, r = m;
        // while(r-l>1){
        //     int mid = (l+r)/2;
        //     int[] mdec = Arrays.copyOf(dec, dec.length);
        //     for(int i=30; i>0; i--){
        //         if(mdec[i] > (long)Math.pow(mid, i)){
        //             mdec[i-1] += mdec[i] - mid;
        //         }
        //     }
        //     if(mdec[0] > mid){
        //         l = mid;
        //     }else{
        //         r = mid;
        //     }
        // }

        // System.out.println(r+1);
    }
}