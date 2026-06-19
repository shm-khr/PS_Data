import java.io.*;
import java.util.*;
public class Main{
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.flush();out.close();
    }
        static class TaskE {
            class pair{
                int F, S;
                pair(int a, int b){F = a; S = b;}
            }
            boolean inc[];
            TreeSet<Integer> ts[] = new TreeSet[2];
           public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            make(n, m ,in);
            if(m % 2 == 1){
                out.println(-1); return;
            }
            inc = new boolean[m];
            for(int i = 0; i < 2; i++) ts[i] = new TreeSet<>();
            for(int i = 1; i <= n; i++){
                if(c[i] < 2)continue;
                ts[c[i] % 2].add(i);
            }
            while(!ts[0].isEmpty() || !ts[1].isEmpty()){
            // System.out.println(ts[0] + " " + ts[1]);
                while(!ts[0].isEmpty()){
                    int u = ts[0].first();
                    for(pair v : ja[u]){
                        if(inc[v.S])continue;
                        inc[v.S] = true;
                        out.println(u + " " + v.F); 
                        c[v.F]--; c[u]--;
                        if(c[v.F] >= 2){
                            ts[c[v.F] % 2].add(v.F);
                        }
                        ts[1 - c[v.F] % 2].remove(v.F);
                    }
                    ts[0].remove(u);
                }
                while(!ts[1].isEmpty()){
                    int u = ts[1].first();
                    int x = c[u] - 1;
                    for(pair v : ja[u]){
                        if(inc[v.S])continue;
                        inc[v.S] = true;
                        out.println(u + " " + v.F);
                        c[v.F]--; x--; c[u]--;
                        if(c[v.F] >= 2){
                            ts[c[v.F] % 2].add(v.F);
                        }
                        ts[1 - c[v.F] % 2].remove(v.F);
                        if(x == 0)break;
                    }
                    // if(c[u] == 0){
                    //     ts[1].remove(u);
                    // }
                    ts[1].remove(u);
                }
            }

          }
            pair ja[][];int from[],to[],c[];
            void make(int n,int m,InputReader in){
             ja=new pair[n+1][];from=new int[m];to=new int[m];c=new int[n+1];
             for(int i=0;i<m;i++){
              int u=in.nextInt(),v=in.nextInt();
              c[u]++;c[v]++;from[i]=u;to[i]=v;
             }
             for(int i=1;i<=n;i++){
              ja[i]=new pair[c[i]];c[i]=0;
             }
             for(int i=0;i<m;i++){
              ja[from[i]][c[from[i]]++]=new pair(to[i],i);
              ja[to[i]][c[to[i]]++]=new pair(from[i],i);
             }
            }
//        int[] radixSort(int[] f){ return radixSort(f, f.length); }
//    int[] radixSort(int[] f, int n)
//    {
//        int[] to = new int[n];
//        {
//            int[] b = new int[65537];
//            for(int i = 0;i < n;i++)b[1+(f[i]&0xffff)]++;
//            for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
//            for(int i = 0;i < n;i++)to[b[f[i]&0xffff]++] = f[i];
//            int[] d = f; f = to;to = d;
//        }
//        {
//            int[] b = new int[65537];
//            for(int i = 0;i < n;i++)b[1+(f[i]>>>16)]++;
//            for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
//            for(int i = 0;i < n;i++)to[b[f[i]>>>16]++] = f[i];
//            int[] d = f; f = to;to = d;
//        }
//        return f;
//    }
    }
    static class InputReader {
        BufferedReader br;
        StringTokenizer st;
        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
            st = null;
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}