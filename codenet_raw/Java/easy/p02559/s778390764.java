import com.sun.security.jgss.GSSUtil;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static class FastReader
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
                catch (IOException e)
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

    public static FastReader r=new FastReader();
    public static final int INF=1000000005;

    public static class BIT{
        int n=0;
        int []a=new int[0];
        public BIT(int n){
            this.n=n;
            this.a=new int[n+1];
        }
        public void update(int pos,int val){
            for(int i=pos;i<=n;i+=(i&-i)){
                this.a[i]+=val;
            }
        }
        public int getSum(int pos){
//            if(pos==-1) return 0;
            int ans=0;
            for(int i=pos;i>0;i-=(i&-i)){
                ans+=this.a[i];
            }
            return ans;
        }
        public int sum(int left,int right){
            return getSum(right)-getSum(left);
        }
    }

    public static void main(String[] args) {
        int n=r.nextInt();
        int q=r.nextInt();
        BIT fen=new BIT(n);
        for(int i=1;i<=n;++i){
            fen.update(i,r.nextInt());
        }
        for(int i=0;i<n;++i){
            int t=r.nextInt();
            int left=r.nextInt();
            int right=r.nextInt();
            if(t==0){
                fen.update(left+1,right);
            }
            else{
                System.out.println(fen.sum(left,right));
            }
        }
    }
}
