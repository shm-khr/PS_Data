import java.io.*;
import java.util.*;

public class Main {
    public static final long mod = (long)1e9+7;
    public static final long INF = Long.MAX_VALUE/2;
    public static final int inf = Integer.MAX_VALUE/2;
    //agc14 c
    static void solve(InputReader in, PrintWriter out){
        int h = in.ni(), w = in.ni(), k = in.ni();
        char[][] map = new char[h][w];
        for (int i = 0; i < h; i++) {
            map[i] = in.ns().toCharArray();
        }
        int sx = 0, sy = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if(map[i][j]=='S'){
                    sx = i;
                    sy = j;
                }
            }
        }
        int[] dx = new int[]{0,1,0,-1};
        int[] dy = new int[]{1,0,-1,0};
        ArrayDeque<Pair> que = new ArrayDeque<Pair>();
        que.addFirst(new Pair(sx, sy));
        int count = 0;
        int ans = inf;
        while(!que.isEmpty() && count < k ){
            Pair p = que.pollLast();
            int len1 = Math.min((h-p.x-2+k)/k, (p.x+k-1)/k);
            int len2 = Math.min((w-p.y-2+k)/k, (p.y+k-1)/k);
            ans = Math.min(ans, Math.min(len1, len2)+1);
            for (int i = 0; i < 4; i++) {
                int x = p.x+dx[i], y = p.y+dy[i];
                if(x>=0&&x<h&&y>=0&&y<w&&map[x][y]=='.'){
                    que.addFirst(new Pair(x, y));
                }
            }
            count++;
        }
        out.println(ans);
    }
    public static class Pair{
        int x; int y;
        public Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args){
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        solve(in, out);
        out.close();
    }
    public static class InputReader{
        private BufferedReader br;
        private StringTokenizer st;
        public InputReader(InputStream is){
            br = new BufferedReader(new InputStreamReader(is));
            st = null;
        }
        public String ns(){
            if(st == null || !st.hasMoreTokens()){
                try{
                    st = new StringTokenizer(br.readLine());
                }catch (Exception e){
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }
        public int ni(){
            return Integer.parseInt(ns());
        }
        public long nl(){
            return Long.parseLong(ns());
        }
        public double nd(){
            return Double.parseDouble(ns());
        }
        public char nc(){
            return ns().toCharArray()[0];
        }
        public int[] ni(int n){
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = ni();
            }
            return a;
        }
        public long[] nl(int n){
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = nl();
            }
            return a;
        }
        public double[] nd(int n){
            double[] a = new double[n];
            for (int i = 0; i < n; i++) {
                a[i] = nd();
            }
            return a;
        }
    }
}