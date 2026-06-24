
import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main
{
    public static void print(String str,int val){
        System.out.println(str+"  "+val);
    }



    public static void debug(long[][] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.println(Arrays.toString(arr[i]));
        }
    }
    public static void debug(int[][] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.println(Arrays.toString(arr[i]));
        }
    }
    public static void debug(String[] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.println(arr[i]);
        }
    }

    public static void print(int[] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.print('\n');
    }
    public static void print(String[] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.print('\n');
    }
    public static void print(long[] arr){
        int len = arr.length;
        for(int i=0;i<len;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.print('\n');
    }

    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }

    static int[] value;
    static int[] weight;
    static int[][] knapsack;
    static int n;
    public static void compute(){
        for(int i=0;i<=Math.min((1<<9),n);i++){
            for(int w=0;w<=100000;w++){
                if(i==0||w==0){
                    knapsack[i][w] =0;
                }
                else if(weight[i]<=w){
                    knapsack[i][w] = Math.max(knapsack[((i)>>1)][w-weight[i]]+value[i],knapsack[(i)>>1][w]);
                }
                else {
                    knapsack[i][w] = knapsack[((i)>>1)][w];
                }
            }
        }
    }
    public static void main(String[] args)
    {
        FastReader s=new FastReader();
        n = s.nextInt();
        value = new int[n+1];
        weight = new int[n+1];
        knapsack = new int[(1<<9)+1][100000+1];
        for(int i=1;i<=n;i++){
            value[i] = s.nextInt();
            weight[i] = s.nextInt();
        }
        compute();
        int q = s.nextInt();
        while ((q--)>0){
            int vertex = s.nextInt();
            int given_weight = s.nextInt();
            if(vertex<(1<<9)){
                System.out.println(knapsack[vertex][given_weight]);
            }
            else {
                int max_value = Integer.MIN_VALUE;
                int log_value = (int)Math.floor(Math.log(vertex)/Math.log(2));
                int n_bits = log_value-8;
                for(int mask =0;mask<(1<<n_bits);mask++){
                    int tot_value =0;
                    int rem_weight = given_weight;
                    for(int i=0;i<n_bits;i++){
                        if((mask&(1<<i))==1){
                            if(rem_weight>=weight[(int)(vertex/(1<<i))]){
                                tot_value+=value[(int)(vertex/(1<<i))];
                            }
                        }
                    }
                    if(rem_weight>0){
                        tot_value+=knapsack[(int)(vertex/(1<<n_bits))][rem_weight];
                    }
                    max_value = Math.max(max_value,tot_value);

                }
                System.out.println(max_value);
            }
        }

    }




//    OutputStream out = new BufferedOutputStream( System.out );
//        for(int i=1;i<n;i++){
//    out.write((arr[i]+" ").getBytes());
//}
//        out.flush();

    //  long start = System.currentTimeMillis();
//  long end = System.currentTimeMillis();
//  System.out.println((end - start) + "ms");



}
