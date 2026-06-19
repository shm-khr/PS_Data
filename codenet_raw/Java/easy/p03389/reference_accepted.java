import java.io.IOException;
import java.io.InputStream;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int max = Math.max(a,Math.max(b,c));
        if (3*max%2==(a+b+c)%2)System.out.println((3*max-a-b-c)/2);
        else System.out.println((3*max+3-a-b-c)/2);
    }



    public static final long mod = 998244353L;
    public static final long MOD = 1000000007L;
    public static final int tenE9 = 1000000000;
    public static final int INF = Integer.MAX_VALUE/2;
    public static final int dataDigit = 10000;
    static Basic basic = new Basic();
    static FastScanner sc = new FastScanner();
    public static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        private boolean hasNextByte() {
            if (ptr < buflen) {
                return true;
            }else{
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (buflen <= 0) {
                    return false;
                }
            }
            return true;
        }
        private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
        private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
        public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while(isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }
        public long nextLong() {
            if (!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) {
                throw new NumberFormatException();
            }
            while(true){
                if ('0' <= b && b <= '9') {
                    n *= 10;
                    n += b - '0';
                }else if(b == -1 || !isPrintableChar(b)){
                    return minus ? -n : n;
                }else{
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }
        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int) nl;
        }
        public double nextDouble() { return Double.parseDouble(next());}
    }
    public static class Basic {
        //math
        private final int MAX = 51*dataDigit;
        private final long MOD = Main.MOD;
        private final long[] fac = new long[MAX];
        private final long[] finv = new long[MAX];
        private final long[] inv = new long[MAX];
        public long factorial(long num) {
            if (num < 2) return 1;
            else return num * factorial(num - 1);
        }//階乗
        public long modFactorial(long num) {
            if (num < 2) return 1;
            else return num*modFactorial(num-1)%MOD;
        }//余り階乗
        public double log(double base, double antilogarithm) {
            return Math.log(antilogarithm) / Math.log(base);
        }//対数
        public long gcd(long x, long y) {
            if (y == 0) return x;
            else return gcd(y, x % y);
        }//最大公約数
        public long lcm(long x, long y) {
            return x / gcd(x, y) * y;
        }//最小公倍数
        public HashMap<Long, Long> factorization(long num) {
            HashMap<Long, Long> hash = new HashMap<>();
            long n = num;
            long count = 2;
            while (n > 1) {
                while (n % count == 0) {
                    n /= count;
                    if (hash.containsKey(count)) hash.put(count, hash.get(count) + 1);
                    else hash.put(count, 1L);
                }
                count++;
            }
            return hash;
        }//素因数分解
        public int sum(int[] num) {
            int ans = 0;
            for (int j : num) {
                ans += j;
            }
            return ans;
        }//総和
        public int[] reduce(int small, int big) {
            int ins = 2;
            while (ins <= small) {
                if (small % ins == 0 && big % ins == 0) {
                    small /= ins;
                    big /= ins;
                    ins = 2;
                } else {
                    ins++;
                }
            }
            return new int[]{small, big};
        }//約分
        public int reduceCount(int small, int big) {
            int ins = 2;
            int ans = 0;
            while (ins <= small) {
                if (small % ins == 0 && big % ins == 0) {
                    small /= ins;
                    big /= ins;
                    ins = 2;
                    ans++;
                } else {
                    ins++;
                }
            }
            return ans;
        }//約分回数
        public long modPow(long a, long n, long mod) {
            long res = 1;
            while (n > 0) {
                if ((n & 1) != 0) res = res * a % mod;
                a = a * a % mod;
                n >>= 1;
            }
            return res;
        }
        public long pow(long a, long n) {
            long res = 1;
            while (n > 0) {
                if ((n & 1) != 0) res = res * a;
                a = a * a;
                n >>= 1;
            }
            return res;
        }
        public long modInv(long a, long mod) {
            return modPow(a, mod - 2, mod);
        }//単位元は素数であることが必須。
        public void dataInit() {
            fac[0] = 1;
            fac[1] = 1;
            finv[0] = 1;
            finv[1] = 1;
            inv[1] = 1;
            for (int i = 2; i < MAX; i++) {
                fac[i] = fac[i - 1] * i % MOD;
                inv[i] = MOD - inv[(int)(MOD % i)] * (MOD / i) % MOD;
                finv[i] = finv[i - 1] * inv[i] % MOD;
            }
        }
        public long combination(int n, int k) {
            if (n < k) return 0;
            if (n < 0 || k < 0) return 0;
            return fac[n] * (finv[k] * finv[n-k]%MOD)% MOD;
        }
        public long permutation(int n, int k){
            return fac[n]*finv[n-k]%MOD;
        }
        public long hCOM(int n, int k) {
            return combination(n + k - 1, k);
        }
        public boolean[] getIsPrimeArray(int max){
            boolean[] ret = new boolean[max+1];
            Arrays.fill(ret,true);
            ret[0]=false;
            ret[1]=false;
            for (int i=2;i<=max;i++){
                if (ret[i]){
                    int c = 2*i;
                    while (c<=max){
                        ret[c]=false;
                        c+=i;
                    }
                }
            }
            return ret;
        }
        public int digits(long n) {
            return String.valueOf(n).length();
        }
        boolean isPrime(int N) {
            if(N <= 1)
                return false;
            else if(N == 2)
                return true;
            for(int i = 2; i <= Math.sqrt(N); i++)
                if(N % i == 0)
                    return false;
            return true;
        }
        public long modInvert(long a, long m){
            long b = m;
            long u = 1;
            long v = 0;
            while (b!=0){
                long t = a/b;
                a-=t*b;
                long c = a;
                a=b;
                b=c;
                u-=t*v;
                c=u;
                u=v;
                v=c;
            }
            u%=m;
            if (u<0)u+=m;
            return u;
        }//単位元が素数でなくても可能。a,mは互いに素であることが必須。得られる逆元は最小値。より高速。



        //array
        public int[] remove(int[] ar, int pos) {
            int[] ret = new int[ar.length - 1];
            for (int i = 0; i < pos; i++) ret[i] = ar[i];
            for (int i = pos + 1; i < ar.length; i++) ret[i - 1] = ar[i];
            return ret;
        }
        public int[] nextArray(int size,int cons){
            int[] ret = new int[size];
            for (int i=0;i<size;i++)ret[i]=sc.nextInt()+cons;
            return  ret;
        }
        public int[] reverse(int[] ar){
            int[] ret = new int[ar.length];
            for (int i=0;i<ar.length;i++){
                ret[i]=ar[ar.length-1-i];
            }
            return ret;
        }
        public long[] cumulative_sum(int[] ar){
            long[] ret = new long[ar.length+1];
            ret[0]=0;
            for (int i=0;i<ar.length;i++)ret[i+1]=ret[i]+ar[i];
            return ret;
        }
        public int median(int[] a) {
            Arrays.sort(a);
            if(a.length % 2 == 1)
                return a[a.length/2];
            else
                return (a[a.length/2-1] + a[a.length/2]) / 2;
        }
        public int binarySearch(int[] array, int target) {
            int pos = -1;
            int left = 0;
            int right = array.length - 1;
            int middle;
            while (pos == -1 && left <= right) {
                middle = (left + right) / 2;
                if (array[middle] == target) pos = middle;
                else if (array[middle] > target) right = middle - 1;
                else left = middle + 1;
            }
            return pos;
        }
        public int lowerBound(int[] a, int key) {
            if(a[a.length-1] < key)
                return a.length;
            int lb = 0, ub = a.length-1, mid;
            do {
                mid = (ub+lb)/2;
                if(a[mid] < key)
                    lb = mid + 1;
                else
                    ub = mid;
            }while(lb < ub);
            return ub;
        }
        public int upperBound(int[] a, int key) {
            if(a[a.length-1] <= key)
                return a.length;
            int lb = 0, ub = a.length-1, mid;
            do {
                mid = (ub+lb)/2;
                if(a[mid] <= key)
                    lb = mid + 1;
                else
                    ub = mid;
            }while(lb < ub);
            return ub;
        }
        public int count(int[] a, int key) {
            return upperBound(a, key) - lowerBound(a, key);
        }
        public List<String> Permutation = new ArrayList<>();
        public void initPermutation(){Permutation.clear();}
        public void permutationList(String q, String ans){
            if(q.length() <= 1) {
                Permutation.add(ans + q);
            }
            else {
                for (int i = 0; i < q.length(); i++) {
                    permutationList(q.substring(0, i) + q.substring(i + 1), ans + q.charAt(i));
                }
            }
        }
        public Comparator<String> dictionarySort = new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                int ret = 0;
                int p = 0;
                int min = Math.min(o1.length(),o2.length());
                boolean b = true;
                while (b&&p<min){
                    if (o1.charAt(p)<o2.charAt(p)){
                        ret=-1;
                        b=false;
                    }else if (o1.charAt(p)>o2.charAt(p)){
                        ret=1;
                        b=false;
                    }
                    p++;
                }
                if (ret==0){
                    if (o1.length()<o2.length())ret=-1;
                    else if (o1.length()>o2.length())ret=1;
                }
                return ret;
            }
        };
        public int[] forEach(int[] array, ArrayReplace ar){
            int[] ret = new int[array.length];
            for (int i=0;i<array.length;i++)ret[i]=ar.replace(i);
            return ret;
        }
        //graph
        public void warshall_floyd(int[][] d) {
            int n = d.length;
            for (int k = 0; k < n; k++)
                for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
        }//隣接行列が引数。辺が無い場合、INFを入力。
        public int[] bellman_ford(int[][] d, int size, int start){
            int e = d.length;
            int[] ans = new int[size];
            Arrays.fill(ans,Integer.MAX_VALUE);
            ans[start]=0;
            for (int i=0;i<size;i++){
                for (int[] a : d) {
                    if (ans[a[1]] > ans[a[0]] + a[2]) {
                        ans[a[1]] = ans[a[0]] + a[2];
                        if (i == size - 1) {
                            System.out.println("negative loop");
                            break;
                        }
                    }
                }
            }
            return ans;
        }//辺を配列の要素として管理。
        public interface ArrayReplace{
            int replace(int num);
        }
    }
    public static class Queue<T>{
        private final int max = 10000000;
        private final T[] queue = (T[]) new Object[max];
        private int tail = 0; private int head = 0;
        public void init(){this.head = 0; tail = 0;}
        public boolean isEmpty(){return (head==tail);}
        public boolean isFull(){return (head == (tail+1)%max);}
        public void enqueue(T v){
            if (isFull()){
                System.out.println("error: queue is full.");
                return;
            }
            queue[tail++] = v;
            if (tail == max) tail = 0;
        }
        public T dequeue(){
            if (isEmpty()){
                System.out.println("error: queue is empty");
                return null;
            }
            T res = queue[head];
            ++head;
            if (head == max) head = 0;
            return res;
        }
    }
    public static class Deque<T>{
        private final int max = 10000000;
        private final T[] queue = (T[]) new Object[max];
        private int tail = 0; private int head = 0;
        public void init(){this.head = 0; tail = 0;}
        public boolean isEmpty(){return (head==tail);}
        public boolean isFull(){
            return (head == (tail+1)%max);
        }
        public void pushFirst(T v){
            if (isFull()){
                System.out.println("error: queue is full.");
                return;
            }
            head--;
            if (head==-1)head=max-1;
            queue[head] = v;
        }
        public void pushLast(T v){
            if (isFull()){
                System.out.println("error: queue is full.");
                return;
            }
            queue[tail++] = v;
            if (tail == max) tail = 0;
        }
        public T popFirst(){
            if (isEmpty()){
                System.out.println("error: queue is empty");
                return null;
            }
            T res = queue[head];
            ++head;
            if (head == max) head = 0;
            return res;
        }
        public T popLast(){
            if (isEmpty()){
                System.out.println("error: queue is empty");
                return null;
            }
            if (--tail==-1)tail=max-1;
            return queue[tail];
        }

        public T peekFirst(){
            if (isEmpty()){
                System.out.println("error: queue is empty");
                return null;
            }
            return queue[head];
        }
        public T peekLast(){
            if (isEmpty()){
                System.out.println("error: queue is empty");
                return null;
            }
            return queue[tail];
        }
    }
    public static class Stack<T>{
        private final int max = 1000000;
        private final T[] stack =(T[]) new Object[max];
        private int top = 0;
        public boolean isEmpty(){return (top==0);}
        public boolean isFull(){return (top==max);}
        public void init(){top=0;}
        public void push(T v){
            if (isFull()){
                System.out.println("error: stack is full.");
                return;
            }
            stack[top++] = v;
        }
        public T pop(){
            if (isEmpty()){
                System.out.println("error: stack is empty");
                return null;
            }
            return stack[--top];
        }
        public T peek(){
            if (isEmpty()){
                System.out.println("error: stack is empty");
                return null;
            }
            return stack[top];
        }
    }
    public static class Pair<K,V>{
        private K A;
        private V B;
        Pair(K a,V b){
            A=a;
            B=b;
        }
        public void changeA(K a){A=a;}
        public void changeB(V b){B=b;}
        public void changeAB(K a,V b){A=a;B=b;}
        public static Comparator numberSortWithA = new Comparator() {
            @Override
            public int compare(Object o1, Object o2) {
                Pair p = (Pair)o1;
                Pair q = (Pair)o2;
                if ((int)p.A<(int)q.A)return -1;
                else if ((int)p.A==(int)q.A){
                    if ((int)p.B<(int)q.B)return -1;
                    else if ((int)p.B==(int)q.B)return 0;
                    else return 1;
                }
                else return 1;
            }
        };
        public static Comparator numberSortWithB = new Comparator() {
            @Override
            public int compare(Object o1, Object o2) {
                Pair p = (Pair)o1;
                Pair q = (Pair)o2;
                if ((int)p.B<(int)q.B)return -1;
                else if ((int)p.B==(int)q.B){
                    if ((int)p.A<(int)q.A)return -1;
                    else if ((int)p.A==(int)q.A)return 0;
                    else return 1;
                }
                else return 1;
            }
        };
    }
    public static class Graph{
        private final HashMap<Integer,HashSet<Integer>> graph = new HashMap<>();
        private final int Size;
        Graph(int size){
            for (int i=0;i<size;i++)graph.put(i,new HashSet<>());
            Size = size;
        }

        public void addEdge(int node1,int node2){
            if (graph.containsKey(node1)&&graph.containsKey(node2)){
                graph.get(node1).add(node2);
                graph.get(node2).add(node1);
            }
        }
        public void addDirectEdge(int from,int to){
            if (graph.containsKey(from)&&graph.containsKey(to)){
                graph.get(from).add(to);
            }
        }
        public int[] depth(int root){
            Queue<Integer> q = new Queue<>();
            q.enqueue(root);
            boolean[] seen = new boolean[Size];
            Arrays.fill(seen, false);
            seen[root]=true;
            int[] depth = new int[Size];
            Arrays.fill(depth,-1);
            depth[root]=0;
            while (!q.isEmpty()){
                int v = q.dequeue();
                for (int u : graph.get(v)){
                    if (!seen[u]){
                        seen[u]=true;
                        q.enqueue(u);
                        depth[u]=depth[v]+1;
                    }
                }
            }
            return depth;
        }
        public HashSet<Integer> getConnected(int pos){return graph.get(pos);}
        public boolean isConnected(int from,int to){return graph.get(from).contains(to);}
        public int diameter(){
            int[] f = depth(0);
            int m = Arrays.stream(f).max().getAsInt();
            int n = basic.binarySearch(f,m);
            int[] s = depth(n);
            return Arrays.stream(s).max().getAsInt();
        }

    }
    public static class WeightedGraph{
        private final HashMap<Integer,HashMap<Integer,Integer>> graph = new HashMap<>();
        private final int Size;
        private long[] Depth;
        WeightedGraph(int size){
            for (int i=0;i<size;i++)graph.put(i,new HashMap<>());
            Size = size;
        }

        public void addEdge(int node1,int node2,int weight){
            if (graph.containsKey(node1)&&graph.containsKey(node2)){
                graph.get(node1).put(node2,weight);
                graph.get(node2).put(node1,weight);
            }
        }
        public void addDirectEdge(int from,int to,int weight){
            if (graph.containsKey(from)&&graph.containsKey(to)){
                graph.get(from).put(to,weight);
            }
        }
        public int[] dijkstra(int root){
            Comparator<int[]> c = new Comparator<int[]>() {
                @Override
                public int compare(int[] o1, int[] o2) {
                    return Integer.compare(o1[1], o2[1]);
                }
            };
            PriorityQueue<int[]> q = new PriorityQueue<>(c);
            q.add(new int[]{root,0});
            int[] ret = new int[Size];
            Arrays.fill(ret,Integer.MAX_VALUE);
            ret[root]=0;
            while (!q.isEmpty()){
                int[] v = q.poll();
                if (v[1]<=ret[v[0]]){
                    HashMap<Integer,Integer> h = graph.get(v[0]);
                    for (int u : h.keySet()){
                        if (ret[u]>v[1]+h.get(u)){
                            ret[u]=v[1]+h.get(u);
                            q.add(new int[]{u,ret[u]});
                        }
                    }
                }
            }
            return ret;
        }

        public long[] Depth(int root){
            Queue<Integer> q = new Queue<>();
            q.enqueue(root);
            boolean[] seen = new boolean[Size];
            Arrays.fill(seen, false);
            seen[root]=true;
            long[] depth = new long[Size];
            depth[root]=0;
            while (!q.isEmpty()){
                int v = q.dequeue();
                for (int u : graph.get(v).keySet()){
                    if (!seen[u]){
                        seen[u]=true;
                        q.enqueue(u);
                        depth[u]=depth[v]+graph.get(v).get(u);
                    }
                }
            }
            Depth = depth.clone();
            return depth;
        }

    }
    public static class UnionFindTree{
        int[] parent;
        int[] rank;
        int[] Size;
        int Number;
        public UnionFindTree(int size){
            this.parent = new int[size];
            this.rank = new int[size];
            this.Size = new int[size];
            makeSet();
        }
        public void makeSet(){
            for (int i=0;i<Size.length;i++){
                parent[i]=i;
                rank[i]=0;
                Size[i]=1;
            }
            Number= Size.length;
        }
        public void unite(int x, int y){
            int xRoot = find(x);
            int yRoot = find(y);
            if (rank[xRoot]>rank[yRoot]){
                parent[yRoot] = xRoot;
                Size[xRoot]+=Size[yRoot];
                Number--;
            }else if (rank[xRoot]<rank[yRoot]){
                parent[xRoot] = yRoot;
                Size[yRoot]+=Size[xRoot];
                Number--;
            }else if (xRoot!=yRoot){
                parent[yRoot] = xRoot;
                rank[xRoot]++;
                Size[xRoot]+=Size[yRoot];
                Number--;
            }
        }
        public int find(int i){
            if (i!= parent[i]){
                parent[i]=find(parent[i]);
            }
            return parent[i];
        }
        public boolean same(int x, int y){
            return find(x) == find(y);
        }
        public int getSize(int i){return Size[find(i)];}
        boolean isConnected(){
            return Number<2;
        }
    }
    public static class BitSearch<T>{
        T[] Array;
        int Width;
        int Length;
        BitSearch(T[] t, int width){
            Array = t;
            Width = width;
            Length = Array.length;
        }
        void start(){
            long max = (long)Math.pow(Width,Length);
            for (long i=0;i<max;i++){
                StringBuilder s = new StringBuilder(Long.toString(i, Width));
                while (s.length()<Length) s.insert(0, "0");
                run(s);
            }
        }
        void run(StringBuilder s){

        }
    }
    public static class SegmentTree{
        static int N, n, INF = Integer.MAX_VALUE/2;
        static int[] dat;
        static void init(int N) {
            n = 1;
            while(n<N)
                n*=2;
            dat=new int[2*n-1];
            for(int i=0;i<2*n-1;i++)
                dat[i]=INF;
        }
        static void update(int k, int a) {
            k+=N-1;
            dat[k]=a;
            while(k>0) {
                k =(k-1)/2;
                dat[k]=Math.min(dat[k*2+1],dat[k*2+2]);
            }
        }
        static int queryMin(int a, int b, int k, int l, int r) {
            if(r<=a||b<=l)
                return INF;
            else if(a<=l&&r<=b)
                return dat[k];
            else
                return Math.min(queryMin(a, b, k*2+1, l, (l+r)/2), queryMin(a, b, k*2+2, (l+r)/2, r));
        }
        static int queryMin(int a, int b) {
            return queryMin(a, b, 0, 0, n);
        }

    }

}
