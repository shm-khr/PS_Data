import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    int mod = 1_000_000_007;
    long inf = Long.MAX_VALUE/2;

    ArrayList<int[]>[] edge;
    long[] memo;
    boolean flag = true;
    boolean tri = false;
    int[] type;
    long bias = 0;
    void solve(){
       int n = ni();
       int m = ni();
       edge = new ArrayList[n];
       memo = new long[n];
       type = new int[n];
       Arrays.fill(memo, -inf);
       for(int i = 0; i < n; i++){
            edge[i] = new ArrayList<int[]>();
       }
       for(int i = 0; i < m; i++){
            int from = ni()-1;
            int to = ni()-1;
            int s = ni();
            edge[from].add(new int[]{to, s});
            edge[to].add(new int[]{from, s});
       }
       memo[0] = 0;
       dfs(0,-1,0,0);
       if(!flag){
        out.println(0);
        return;
       }
       if(bias==0){
        if(tri){
            for(int i = 0; i < n; i++){
                if(memo[i]<=0){
                    out.println(0);
                    return;
                }
            }
            out.println(1);
            return;
        }
        long s = 1;
        long t = inf;
        for(int i = 0; i < n; i++){
            if(type[i]==0) s = Math.max(s, 1-memo[i]);
            if(type[i]==1) t = Math.min(t, memo[i]-1);
        }
        out.println(Math.max(0, t-s+1));
        return;
       }

       Arrays.fill(memo,-inf);
       long b = bias;
       bias = 0;
       memo[0] = b;
       dfs(0,-1,b,0);
       if(!flag){
        out.println(0);
        return;
       }
       if(bias==0){
        if(tri){
            for(int i = 0; i < n; i++){
                if(memo[i]<=0){
                    out.println(0);
                    return;
                }
            }
            out.println(1);
            return;
        }
        long s = 1;
        long t = inf;
        for(int i = 0; i < n; i++){
            if(type[i]==0) s = Math.max(s, 1-memo[i]);
            if(type[i]==1) t = Math.min(t, memo[i]-1);
        }
        out.println(Math.max(0, t-s+1));
        return;
       }

       Arrays.fill(memo,-inf);
       memo[0] = -b;
       bias = 0;
       dfs(0,-1,-b,0);
       if(!flag){
        out.println(0);
        return;
       }
       if(bias==0){
        if(tri){
            for(int i = 0; i < n; i++){
                if(memo[i]<=0){
                    out.println(0);
                    return;
                }
            }
            out.println(1);
            return;
        }
        long s = 1;
        long t = inf;
        for(int i = 0; i < n; i++){
            if(type[i]==0) s = Math.max(s, 1-memo[i]);
            if(type[i]==1) t = Math.min(t, memo[i]-1);
        }
        out.println(Math.max(0, t-s+1));
        return;
       }
       out.println(0);

    }

    void dfs(int cur, int par, long val, int t){
        if(!flag) return;
        if(bias!=0) return;
        type[cur] = t;
        for(int[] c : edge[cur]){
            if(c[0]==par) continue;
            long d = (long)c[1] - val;
            if(memo[c[0]]!=-inf){
                if(type[c[0]]==type[cur]){
                    tri = true;
                }
                if(memo[c[0]]!=d){
                    if(type[c[0]]!=type[cur]){
                        flag = false;
                    }
                    else{
                        long dif = d-memo[c[0]];
                        if(dif%2!=0) flag = false;
                        bias = dif/2;
                    }
                }
                continue;
            }
            memo[c[0]] = d;
            dfs(c[0],cur,d,1-t);
        }
    }

    void run() throws Exception
    {
        is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        out = new PrintWriter(System.out);
        long s = System.currentTimeMillis();
        solve();
        out.flush();
        if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
    }
    
    public static void main(String[] args) throws Exception { new Main().run(); }
    
    private byte[] inbuf = new byte[1024];
    private int lenbuf = 0, ptrbuf = 0;
    
    private int readByte()
    {
        if(lenbuf == -1)throw new InputMismatchException();
        if(ptrbuf >= lenbuf){
            ptrbuf = 0;
            try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
            if(lenbuf <= 0)return -1;
        }
        return inbuf[ptrbuf++];
    }
    
    private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
    private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
    
    private double nd() { return Double.parseDouble(ns()); }
    private char nc() { return (char)skip(); }
    
    private String ns()
    {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while(!(isSpaceChar(b) && b != ' ')){
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    
    private char[] ns(int n)
    {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while(p < n && !(isSpaceChar(b))){
            buf[p++] = (char)b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }
    
    private char[][] nm(int n, int m)
    {
        char[][] map = new char[n][];
        for(int i = 0;i < n;i++)map[i] = ns(m);
        return map;
    }
    
    private int[] na(int n)
    {
        int[] a = new int[n];
        for(int i = 0;i < n;i++)a[i] = ni();
        return a;
    }
    
    private int ni()
    {
        int num = 0, b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    
    private long nl()
    {
        long num = 0;
        int b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    
    private static void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
 
}
