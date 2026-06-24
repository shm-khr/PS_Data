import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Objects;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.TreeSet;


public class Main {
    public static void main(String[] args) {
        Out out = new Out();
        solve(out);
        out.outln();
        out.flush();
        out.close();
    }

    public static void solve(Out out) {
        ModuloArithmetic ma = new ModuloArithmetic(Const.MOD7);
        int n = In.ni();
        int m = In.ni();
        int s = In.ni() - 1;
        int t = In.ni() - 1;
        Graph g = new Graph(n);
        for (int i = 0; i < m; i++) {
            int u = In.ni() - 1;
            int v = In.ni() - 1;
            int d = In.ni();
            g.addEdge(u, v, d);
        }
        long[] sd = new Dijkstra(g, s).d;
        long st = sd[t];
        long[] td = new Dijkstra(g, t).d;
        TreeSet<Integer> onPath = new TreeSet<>((u, v) -> {
            if (sd[u] == sd[v]) {
                return u - v;
            } else {
                return Long.compare(sd[u], sd[v]);
            }
        });
        for (int i = 0; i < n; i++) {
            if (sd[i] + td[i] == st) {
                onPath.add(i);
            }
        }
        Digraph stg = new Digraph(n);
        Digraph tsg = new Digraph(n);
        for (int u : onPath) {
            for (Edge e : g.getEdges(u)) {
                int v = e.to;
                long c = e.cost;
                if (onPath.contains(v) && sd[u] < sd[v]) {
                    stg.addEdge(u, v, c);
                    tsg.addEdge(v, u, c);
                }
            }
        }
        long[] dpstg = new long[n];
        dpstg[s] = 1;
        Iterator<Integer> it = onPath.iterator();
        while (it.hasNext()) {
            int u = it.next();
            for (Edge e : stg.getEdges(u)) {
                int v = e.to;
                dpstg[v] = ma.add(dpstg[v], dpstg[u]);
            }
        }
        long[] dptsg = new long[n];
        dptsg[t] = 1;
        Iterator<Integer> rvit = onPath.descendingIterator();
        HashSet<Long> set = new HashSet<>();
        while (rvit.hasNext()) {
            int u = rvit.next();
            for (Edge e : tsg.getEdges(u)) {
                int v = e.to;
                dptsg[v] = ma.add(dptsg[v], dptsg[u]);
                if (2l * td[u] < st && 2l * td[v] >= st) {
                    set.add((long) u * n + v);
                }
            }
        }
        long sub = 0;
        for (long e : set) {
            int u = (int) (e / n);
            int v = (int) (e % n);
            sub = ma.add(sub, ma.mul(dptsg[u], dpstg[v]));
        }
        long ans = ma.sub(ma.mul(dpstg[t], dptsg[s]), sub);
        out.append(ans);
    }
}


class Dijkstra {
    public static final long INF = Const.LINF;
    public int[] prev;
    public long[] d;

    public Dijkstra(AbstractGraph g, int s) {
        if (g.getE() * 10 >= (long) g.getV() * g.getV()) {
            dijkstra2(g, s);
        } else {
            dijkstra(g, s);
        }
    }

    // private void dijkstra(AbstractGraph g, int s) {
    //     int n = g.getV();
    //     this.prev = new int[n];
    //     this.d = new long[n];
    //     TreeSet<Integer> set = new TreeSet<>((u, v) -> {
    //         if (d[u] == d[v]) {
    //             return u - v;
    //         } else {
    //             return Long.compare(d[u], d[v]);
    //         }
    //     });
    //     Arrays.fill(d, INF);
    //     d[s] = 0;
    //     prev[s] = -1;
    //     set.add(s);
    //     while (set.size() > 0) {
    //         int now = set.pollFirst();
    //         for (Edge e : g.getEdges(now)) {
    //             int next = e.to;
    //             long c = e.cost;
    //             if (d[now] + c < d[next]) {
    //                 set.remove(next);
    //                 d[next] = d[now] + c;
    //                 prev[next] = now;
    //                 set.add(next);
    //             }
    //         }
    //     }
    // }

    /**
     * O((V+E)logV) dijkstra
     */
    private void dijkstra(AbstractGraph g, int s) {
        int n = g.getV();
        this.prev = new int[n];
        this.d = new long[n];
        boolean[] settled = new boolean[n];
        PriorityQueue<Integer> pq = new PriorityQueue<>((u, v) -> Long.compare(d[u], d[v]));
        Arrays.fill(d, Const.LINF);
        d[s] = 0;
        prev[s] = -1;
        pq.add(s);
        while (pq.size() > 0) {
            int now = pq.poll();
            if (settled[now]) {
                continue;
            }
            settled[now] = true;
            for (Edge e : g.getEdges(now)) {
                int next = e.to;
                long c = e.cost;
                if (d[now] + c < d[next]) {
                    d[next] = d[now] + c;
                    prev[next] = now;
                    pq.add(next);
                }
            }
        }
    }

    /**
     * O(V^2) dijkstra
     */
    private void dijkstra2(AbstractGraph g, int s) {
        int n = g.getV();
        this.d = new long[n];
        this.prev = new int[n];
        Arrays.fill(d, INF);
        d[s] = 0;
        prev[s] = -1;
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            set.add(i);
        }
        for (int i = 0; i < n; i++) {
            long minD = INF;
            int minV = -1;
            for (int v : set) {
                if (d[v] < minD) {
                    minD = d[v];
                    minV = v;
                }
            }
            if (minV < 0) {
                break;
            }
            int from = minV;
            for (Edge e : g.getEdges(from)) {
                int to = e.to;
                long cost = e.cost;
                if (d[from] + cost < d[to]) {
                    d[to] = d[from] + cost;
                    prev[to] = from;
                }
            }
            set.remove(from);
        }
    }

    public int[] path(int from, int to) {
        ArrayList<Integer> rev = new ArrayList<>();
        for (int now = to; now != from; now = this.prev[now]) {
            rev.add(now);
        }
        rev.add(from);
        int[] path = new int[rev.size()];
        for (int i = 0; i < path.length; i++) {
            path[i] = rev.get(path.length - i - 1);
        }
        return path;
    }
}


class Out {
    private StringBuilder sb = new StringBuilder();
    private PrintWriter w = new PrintWriter(System.out);

    public Out() {
    }

    public void append(int v) {
        sb.append(v);
    }

    public void append(long v) {
        sb.append(v);
    }

    public void append(char c) {
        sb.append(c);
    }

    public void append(double v) {
        sb.append(v);
    }

    public void append(char[] c) {
        sb.append(c);
    }

    public void append(String s) {
        sb.append(s);
    }

    public void append(Object e) {
        sb.append(e);
    }

    public void append(int[] a, String sep) {
        for (int i = 0; i < a.length; i++) {
            append(a[i]);
            if (i < a.length - 1) {
                append(sep);
            }
        }
    }

    public void append(long[] a, String sep) {
        for (int i = 0; i < a.length; i++) {
            append(a[i]);
            if (i < a.length - 1) {
                append(sep);
            }
        }
    }

    public void append(char[] a, String sep) {
        for (int i = 0; i < a.length; i++) {
            append(a[i]);
            if (i < a.length - 1) {
                append(sep);
            }
        }
    }

    public void append(double[] a, String sep) {
        for (int i = 0; i < a.length; i++) {
            append(a[i]);
            if (i < a.length - 1) {
                append(sep);
            }
        }
    }

    public void append(char[][] c, String sep) {
        for (int i = 0; i < c.length; i++) {
            append(c[i]);
            if (i < c.length - 1) {
                append(sep);
            }
        }
    }

    public void append(String[] a, String sep) {
        for (int i = 0; i < a.length; i++) {
            append(a[i]);
            if (i < a.length - 1) {
                append(sep);
            }
        }
    }

    public void append(Object[] a, String sep) {
        for (int i = 0; i < a.length; i++) {
            append(a[i]);
            if (i < a.length - 1) {
                append(sep);
            }
        }
    }

    public void out() {
        w.print(sb);
        clearBuilder();
    }

    public void outln() {
        w.println(sb);
        clearBuilder();
    }

    public void print(int v) {
        w.print(v);
    }

    public void print(long v) {
        w.print(v);
    }

    public void print(char c) {
        w.print(c);
    }

    public void print(double v) {
        w.print(v);
    }

    public void print(String s) {
        w.print(s);
    }

    public void print(Object e) {
        w.print(e);
    }

    public void print(String sep, int... a) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < a.length; i++) {
            s.append(a[i]);
            if (i < a.length - 1) {
                s.append(sep);
            }
        }
        print(s);
    }

    public void print(String sep, long... a) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < a.length; i++) {
            s.append(a[i]);
            if (i < a.length - 1) {
                s.append(sep);
            }
        }
        print(s);
    }

    public void print(String sep, char... a) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < a.length; i++) {
            s.append(a[i]);
            if (i < a.length - 1) {
                s.append(sep);
            }
        }
        print(s);
    }

    public void print(String sep, double... a) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < a.length; i++) {
            s.append(a[i]);
            if (i < a.length - 1) {
                s.append(sep);
            }
        }
        print(s);
    }

    public void print(String sep, String... a) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < a.length; i++) {
            s.append(a[i]);
            if (i < a.length - 1) {
                s.append(sep);
            }
        }
        print(s);
    }

    public void print(String sep, Object... a) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < a.length; i++) {
            s.append(a[i]);
            if (i < a.length - 1) {
                s.append(sep);
            }
        }
        print(s);
    }

    public void println() {
        w.println();
    }

    public void println(int v) {
        w.println(v);
    }

    public void println(long v) {
        w.println(v);
    }

    public void println(double v) {
        w.println(v);
    }

    public void println(char c) {
        w.println(c);
    }

    public void println(String s) {
        w.println(s);
    }

    public void println(Object e) {
        w.println(e);
    }

    public void println(String sep, int... a) {
        print(sep, a);
        println();
    }

    public void println(String sep, long... a) {
        print(sep, a);
        println();
    }

    public void println(String sep, double... a) {
        print(sep, a);
        println();
    }

    public void println(String sep, char... a) {
        print(sep, a);
        println();
    }

    public void println(String sep, String... a) {
        print(sep, a);
        println();
    }

    // public void println(String sep, Object... a) {
    //     print(sep, a);
    //     println();
    // }

    public void flush() {
        w.flush();
    }

    public void close() {
        w.close();
    }

    public void clearBuilder() {
        sb = new StringBuilder();
    }

    public void reverse() {
        sb.reverse();
    }

    public void delete(int start, int end) {
        sb.delete(start, end);
    }

    public void delete(int length) {
        sb.delete(sb.length() - length, sb.length());
    }

    public int length() {
        return sb.length();
    }
}

class IntDeque implements Cloneable {
    private int head = -1;
    private int tail = 0;
    private int pSize;
    private int nSize;
    private int p[];
    private int n[];

    private static final int DEFAULT_SIZE = 64;

    public IntDeque(int initialSize) {
        this(Math.max(1, initialSize - initialSize / 2), Math.max(1, initialSize / 2));
        if (initialSize <= 0) {
            System.err.println("Error in IntDeque::new. initial size must be positive.");
        }
    }

    private IntDeque(int pSize, int nSize) {
        this.pSize = pSize;
        this.nSize = nSize;
        this.p = new int[this.pSize];
        this.n = new int[this.nSize];
    }

    public IntDeque() {
        this(DEFAULT_SIZE);
    }

    public static IntDeque asDeque(int initialSize) {
        return new IntDeque(initialSize);
    }

    public static IntDeque asDeque() {
        return new IntDeque(DEFAULT_SIZE);
    }

    public static IntDeque asQueue(int initialSize) {
        return new IntDeque(Math.max(1, initialSize), 1);
    }

    public static IntDeque asQueue() {
        return new IntDeque(DEFAULT_SIZE, 1);
    }

    public static IntDeque asStack(int initialSize) {
        return new IntDeque(1, Math.max(1, initialSize));
    }

    public static IntDeque asStack() {
        return new IntDeque(1, DEFAULT_SIZE);
    }

    public void addLast(int v) {
        putByRawIndex(tail++, v);
    }

    public void addFirst(int v) {
        putByRawIndex(head--, v);
    }

    public int pollFirst() {
        if (size() == 0) {
            System.err.println("Error in IntDeque::pollFirst. cannot poll element from \"EMPTY\" IntDeque.");
        }
        return getByRawIndex(++head);
    }

    public int pollLast() {
        if (size() == 0) {
            System.err.println("Error in IntDeque::pollLast. cannot poll element from \"EMPTY\" IntDeque.");
        }
        return getByRawIndex(--tail);
    }

    public int get(int index) {
        index += head + 1;
        if (index >= tail) {
            System.err.println("Error in IntDeque::get(" + index + "). the size of IntDeque is " + size() + ".");
        }
        return getByRawIndex(index);
    }

    public int getFirst() {
        return get(0);
    }

    public int getLast() {
        return get(size() - 1);
    }

    public int size() {
        return tail - head - 1;
    }

    public void clear() {
        head = -1;
        tail = 0;
    }

    public int[] toArray() {
        int[] a = new int[size()];
        for (int i = 0; i < size(); i++) {
            a[i] = get(i);
        }
        return a;
    }

    private void resize(boolean positive) {
        if (positive) {
            int[] pCopy = new int[pSize << 1];
            System.arraycopy(p, 0, pCopy, 0, pSize);
            p = pCopy;
            pSize <<= 1;
        } else {
            int[] nCopy = new int[nSize << 1];
            System.arraycopy(n, 0, nCopy, 0, nSize);
            n = nCopy;
            nSize <<= 1;
        }
    }

    private int getByRawIndex(int index) {
        if (index >= 0) {
            return p[index];
        } else {
            return n[-(index + 1)];
        }
    }

    private void putByRawIndex(int index, int v) {
        if (index < 0) {
            if (index <= -(nSize + 1)) {
                resize(false);
            }
            n[-(index + 1)] = v;
        } else {
            if (index >= pSize) {
                resize(true);
            }
            p[index] = v;
        }
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public boolean nonEmpty() {
        return size() != 0;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append('[');
        for (int i = 0; i < size(); i++) {
            sb.append(get(i));
            if (i < size() - 1) {
                sb.append(", ");
            }
        }
        sb.append(']');
        return sb.toString();
    }
}

class Const {
    public static final long MOD7 = 1_000_000_007;
    public static final long MOD9 = 1_000_000_009;
    public static final long MOD99 = 998_244_353;

    public static final long LINF = 1_000_000_000_000_000_000l;
    public static final int IINF = 1_000_000_000;
    public static final double DINF = 1e150;

    public static final double DELTA = 0.000_000_000_1;
    public static final double LDELTA = 0.000_001;

    public static final String YES = "YES";
    public static final String NO = "NO";
    public static final String Yes = "Yes";
    public static final String No = "No";
    public static final String POSSIBLE = "POSSIBLE";
    public static final String IMPOSSIBLE = "IMPOSSIBLE";
    public static final String Possible = "Possible";
    public static final String Impossible = "Impossible";

    public static final int[] dx8 = {1, 0, -1, 0, 1, -1, -1, 1};
    public static final int[] dy8 = {0, 1, 0, -1, 1, 1, -1, -1};
    public static final int[] dx = {1, 0, -1, 0};
    public static final int[] dy = {0, 1, 0, -1};

    private Const(){}
}

class Edge {
    public int from;
    public int to;
    public long cost;

    public Edge(int from, int to, long cost) {
        this.from = from;
        this.to = to;
        this.cost = cost;
    }

    public Edge(int from, int to) {
        this(from, to, 1);
    }

    protected Edge reverse() {
        return new Edge(to, from, cost);
    }
}


class Graph extends AbstractGraph {
    public Graph(int n) {
        super(n);
    }

    public void addEdge(int from, int to, long cost) {
        Edge e = new Edge(from, to, cost);
        super.addEdge(e);
        super.addEdge(e.reverse());
        this.m++;
    }

    public void addEdge(int from, int to) {
        this.addEdge(from, to, 1);
    }

    @Override
    public void addEdge(Edge e) {
        super.addEdge(e);
        super.addEdge(e.reverse());
        this.m++;
    }

    @Override
    protected void generateComponentsIfAbsent() {
        if (Objects.isNull(getNullableComponents())) {
            HashMap<Integer, ArrayList<Integer>> components = new HashMap<>();
            for (int i = 0; i < n; i++) {
                if (!components.containsKey(getRoot(i))) {
                    ArrayList<Integer> component = new ArrayList<>();
                    component.add(i);
                    components.put(getRoot(i), component);
                } else {
                    components.get(getRoot(i)).add(i);
                }
            }
            setComponents(components);
        }
    }

    @Override
    public boolean isBipartite() {
        int[] color = new int[getV()];
        ArrayDeque<Integer> dq = new ArrayDeque<>();
        for (int root : getRoots()) {
            dq.add(root);
            color[root] = 1;
        }
        while (dq.size() > 0) {
            int now = dq.pollFirst();
            for (Edge e : getEdges(now)) {
                int next = e.to;
                if (color[next] == 0) {
                    color[next] = -color[now];
                    dq.add(next);
                } else if (color[now] == color[next]) {
                    return false;
                }
            }
        }
        return true;
    }
}


class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        } else {
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

    private int readByte() {
        if (hasNextByte()) {
            return buffer[ptr++];
        } else {
            return -1;
        }
    }

    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    public boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
            ptr++;
        }
        return hasNextByte();
    }

    public String next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public long nextLong() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
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
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
            throw new NumberFormatException();
        }
        return (int) nl;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}


class Digraph extends AbstractGraph {
    private Graph g;

    public Digraph(int n) {
        super(n);
    }

    public void addEdge(int from, int to, long cost) {
        Edge e = new Edge(from, to, cost);
        super.addEdge(e);
        this.m++;
    }

    public void addEdge(int from, int to) {
        this.addEdge(from, to, 1);
    }

    @Override
    public void addEdge(Edge e) {
        super.addEdge(e);
        this.m++;
    }

    @Override
    protected void generateComponentsIfAbsent() {
        if (Objects.isNull(getNullableComponents())) {
            setComponents(getG().getComponents());
        }
    }

    @Override
    public boolean isBipartite() {
        return getG().isBipartite();
    }

    private void generateNonDirectGraphIfAbsent() {
        if (Objects.isNull(this.g)) {
            this.g = new Graph(n);
            for (int i = 0; i < n; i++) {
                for (Edge e : getEdges(i)) {
                    this.g.addEdge(e);
                }
            }
        }
    }
    
    private Graph getG() {
        generateNonDirectGraphIfAbsent();
        return this.g;
    }

    public boolean isDAG() {
        return isConnected() && Objects.nonNull(TopologicalSort.topologicalSort(this));
    }
}

class ModuloArithmetic {
    public final long MOD;
    private long[] fact;
    private long[] pow;

    /**
     * support modulo p arithmetic
     * 
     * @param p p s.t. p is a prime number.
     */
    public ModuloArithmetic(long p) {
        this.MOD = p;
    }

    /**
     * Calculate x s.t. 0 <= x < MOD /\ x = a mod p.
     * 
     * @param a
     * @return x s.t. 0 <= x < MOD /\ x = a mod p.
     */
    public long mod(long a) {
        a %= MOD;
        return a < 0 ? a + MOD : a;
    }

    /**
     * Calculate x s.t. 0 <= x < MOD /\ x = a_1 + 1_2 + ... + a_k mod p.
     * 
     * @param a
     * @return x s.t. 0 <= x < MOD /\ x = a_1 + 1_2 + ... + a_k mod p.
     */
    public long sum(long... a) {
        long ret = 0;
        for (long c : a) ret += c;
        return mod(ret);
    }

    /**
     * Calculate x s.t. 0 <= x < MOD /\ x = a + b mod p.
     * 
     * @param a
     * @param b
     * @return x s.t. 0 <= x < MOD /\ x = a + b mod p.
     */
    public long add(long a, long b) {
        long s = a + b;
        return s < 0 ? s + MOD : s >= MOD ? s - MOD : s;
    }

    /**
     * Calculate x s.t. 0 <= x < MOD /\ x = a - b mod p.
     * 
     * @param a
     * @param b
     * @return x s.t. 0 <= x < MOD /\ x = a - b mod p.
     */
    public long sub(long a, long b) {
        long s = a - b;
        return s < 0 ? s + MOD : s >= MOD ? s - MOD : s;
    }

    /**
     * Calculate x s.t. 0 <= x < MOD /\ x = a_1 * 1_2 * ... * a_k mod p.
     * 
     * @param a
     * @return x s.t. 0 <= x < MOD /\ x = a_1 * 1_2 * ... * a_k mod p.
     */
    public long prod(long... a) {
        long ret = 1;
        for (long c : a) {
            ret = (ret * c) % MOD;
        }
        return ret < 0 ? ret + MOD : ret;
    }

    /**
     * Calculate x s.t. 0 <= x < MOD /\ x = a * b mod p.
     * 
     * @param a
     * @param b
     * @return x s.t. 0 <= x < MOD /\ x = a * b mod p.
     */
    public long mul(long a, long b) {
        return mod(a * b);
    }

    /**
     * Calculate x s.t. 0 <= x < MOD /\ b * x = a mod p.
     * 
     * @param a
     * @param b
     * @return x s.t. 0 <= x < MOD /\ b * x = a mod p.
     */
    public long div(long a, long b) {
        return mul(a, inv(b));
    }

    /**
     * Calculate the value b s.t. a*b mod MOD = 1.
     * 
     * @param a
     * @return inverse of a
     */
    public long inv(long a) {
        long b = MOD;
        long u = 1, v = 0;
        while (b >= 1) {
            long t = a / b;
            a -= t * b;
            long tmp1 = a; a = b; b = tmp1;
            u -= t * v;
            long tmp2 = u; u = v; v = tmp2;
        }
        return mod(u);
    }

    /**
     * Calculate the permutation nPr.
     * 
     * @param n
     * @param r
     * @return nPr
     */
    public long perm(long n, long r) {
        if (n < r) {
            return 0;
        }
        if (fact != null && n <= fact.length) {
            return div(fact[(int) n], fact[(int) (n - r)]);
        }
        long ret = 1;
        for (long i = n; i > n - r; i--) {
            ret = mul(ret, i);
        }
        return ret;
    }

    /**
     * Calculate the combination nCr.
     * 
     * @param n
     * @param r
     * @return nCr
     */
    public long comb(long n, long r) {
        if (n < r) {
            return 0;
        }
        if (fact != null && n <= fact.length) {
            return div(fact[(int) n], mul(fact[(int) (n - r)], fact[(int) r]));
        }
        r = Math.min(r, n - r);
        long res = 1;
        for (long d = 1; d <= r; d++) {
            res = div(mul(res, n--), d);
        }
        return res;
    }
    
    /**
     * call this method after building factorial array.
     * 
     * @param n
     * @return n! mod p
     */
    public long fact(int n) {
        return fact[n];
    }

    /**
     * call this nethod after building power array.
     * 
     * @param n
     * @return (base)^n
     */
    public long pow(int n) {
        return pow[n];
    }

    /**
     * Calculate a^b (mod {@code MOD}) in O(log b) time.
     * 
     * @param a base
     * @param b index
     * @return a^b (mod {@code MOD})
     */
    public long pow(long a, long b) {
        if (b == 0) {
            return 1;
        }
        long half = pow(a, b >> 1);
        if ((a & 1) == 0) {
            return mul(half, half);
        } else {
            return prod(half, half, a);
        }
    }

    /**
     * build factorial array from 0 to n (closed)
     * 
     * @param n
     */
    public void buildFactorial(int n) {
        this.fact = new long[n + 1];
        for (int i = 0; i <= n; i++) {
            if (i <= 1) {
                fact[i] = 1;
            } else {
                fact[i] = mul(fact[i - 1], i);
            }
        }
    }

    /**
     * build power array based on a from 0 to n (closed)
     * 
     * @param a base of power
     * @param n
     */
    public void buildPower(long a, int n) {
        if (a == 2) {
            buildPower(n);
        } else {
            this.pow = new long[n + 1];
            for (int i = 0; i <= n; i++) {
                if (i == 0) {
                    pow[i] = 1;
                } else {
                    pow[i] = mul(pow[i - 1], a);
                }
            }
        }
    }

    /**
     * build power array based on 2 from 0 to n (closed)
     * 
     * @param n
     */
    public void buildPower(int n) {
        this.pow = new long[n + 1];
        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                pow[i] = 1;
            } else {
                pow[i] = pow[i - 1] << 1;
                if (pow[i] >= MOD) {
                    pow[i] -= MOD;
                }
            }
        }
    }
}


abstract class AbstractGraph {
    protected final int n;
    protected int m = 0;
    private ArrayList<Edge>[] adj;
    private int[] in;
    private HashMap<Integer, ArrayList<Integer>> components;
    private UnionFindTree uft;
    
    @SuppressWarnings("unchecked")
    protected AbstractGraph(int n) {
        this.n = n;
        this.in = new int[n];
        this.adj = new ArrayList[this.n];
        for (int i = 0; i < this.n; i++) {
            this.adj[i] = new ArrayList<>();
        }
        this.uft = new UnionFindTree(this.n);
    }

    protected void addEdge(Edge e) {
        this.adj[e.from].add(e);
        this.in[e.to]++;
        this.uft.unite(e.from, e.to);
    }

    public int in(int i) {
        return this.in[i];
    }

    public int out(int i) {
        return this.adj[i].size();
    }

    public Edge getEdge(int from, int index) {
        return this.adj[from].get(index);
    }

    public ArrayList<Edge> getEdges(int i) {
        return this.adj[i];
    }

    public int getV() {
        return this.n;
    }

    public int getE() {
        return this.m;
    }

    public int getRoot(int i) {
        return uft.root(i);
    }

    public HashMap<Integer, ArrayList<Integer>> getComponents() {
        generateComponentsIfAbsent();
        return this.components;
    }

    protected void setComponents(HashMap<Integer, ArrayList<Integer>> components) {
        this.components = components;
    }

    protected HashMap<Integer, ArrayList<Integer>> getNullableComponents() {
        return this.components;
    }

    public ArrayList<Integer> getComponent(int i) {
        return getComponents().get(getRoot(i));
    }

    public Set<Integer> getRoots() {
        return getComponents().keySet();
    }

    public Collection<ArrayList<Integer>> getComponentSet() {
        return getComponents().values();
    }

    public boolean isConnected() {
        return getComponents().size() == 1;
    }

    public boolean isConnected(int u, int v) {
        return getRoot(u) == getRoot(v);
    }

    public boolean isTree() {
        return m == n - 1 && isConnected();
    }

    abstract public boolean isBipartite();

    abstract protected void generateComponentsIfAbsent();
}


class UnionFindTree {
    private int[] parent;
    private int[] rank;
    private int[] size;
    private int groups;

    public UnionFindTree(int n) {
        this.parent = new int[n];
        this.rank = new int[n];
        this.size = new int[n];
        this.groups = n;
        Arrays.fill(this.size, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int root(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = root(parent[x]);
    }

    public boolean isSame(int x, int y) {
        return root(x) == root(y);
    }

    public void unite(int x, int y) {
        int xr = root(x);
        int yr = root(y);
        if (xr == yr) {
            return;
        }
        if (rank[xr] < rank[yr]) {
            parent[xr] = yr;
            size[yr] += size[xr];
        } else {
            parent[yr] = xr;
            size[xr] += size[yr];
            if (rank[xr] == rank[yr]) {
                rank[xr]++;
            }
        }
        groups--;
    }

    public int size(int x) {
        return size[root(x)];
    }

    public boolean isRoot(int x) {
        return parent[x] == x;
    }

    public int groups() {
        return groups;
    }
}

class TopologicalSort {
    public static int[] topologicalSort(Digraph g) {
        int n = g.getV();
        int[] ret = new int[n];
        int[] in = new int[n];
        for (int i = 0; i < n; i++) {
            in[i] = g.in(i);
        }
        IntDeque zeros = new IntDeque();
        for (int i = 0; i < n; i++) {
            if (g.in(i) == 0) {
                zeros.addLast(i);
            }
        }
        int index = 0;
        while (zeros.size() > 0) {
            int v = zeros.pollFirst();
            for (Edge e : g.getEdges(v)) {
                if (--in[e.to] == 0) {
                    zeros.addLast(e.to);
                }
            }
            ret[index++] = v;
        }
        if (index < n) {
            return null;
        }
        return ret;
    }

    // for example (n=9)
    // [1, 8] -> [2, 5, 6] -> [3, 7] -> [4] -> [9]
    // => length:5
    public static int shortest(Digraph g) {
        int n = g.getV();
        int ret = 0;
        int[] in = new int[n];
        for (int i = 0; i < n; i++) {
            in[i] = g.in(i);
        }
        IntDeque zeros = new IntDeque();
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                zeros.addLast(i);
            }
        }
        int num = zeros.size();
        while (zeros.size() > 0) {
            int size = zeros.size();
            while (size > 0) {
                int v = zeros.pollFirst();
                size--;
                for (Edge e : g.getEdges(v)) {
                    if (--in[e.to] == 0) {
                        zeros.addLast(e.to);
                        num++;
                    }
                }
            }
            ret++;
        }
        if (num < n) {
            return -1;
        }
        return ret;
    }
}


class In {
    public static final FastScanner fsc = new FastScanner();

    public static int ni() {
        return fsc.nextInt();
    }

    public static int[] ni(int n) {
        int[] a = new int[n];
        Arrays.setAll(a, i -> fsc.nextInt());
        return a;
    }

    public static int[][] ni(int n, int m) {
        int[][] a = new int[n][m];
        Arrays.setAll(a, i -> ni(m));
        return a;
    }

    public static long nl() {
        return fsc.nextLong();
    }

    public static long[] nl(int n) {
        long[] a = new long[n];
        Arrays.setAll(a, i -> fsc.nextLong());
        return a;
    }

    public static long[][] nl(int n, int m) {
        long[][] a = new long[n][m];
        Arrays.setAll(a, i -> nl(m));
        return a;
    }

    public static char[] nc() {
        return fsc.next().toCharArray();
    }

    public static char[][] nc(int n, int m) {
        char[][] c = new char[n][m];
        Arrays.setAll(c, i -> nc());
        return c;
    }

    public static double nd() {
        return fsc.nextDouble();
    }

    public static double[] nd(int n) {
        double[] a = new double[n];
        Arrays.setAll(a, i -> nd());
        return a;
    }

    public static double[][] nd(int n, int m) {
        double[][] a = new double[n][m];
        Arrays.setAll(a, i -> nd(m));
        return a;
    }

    public static String ns() {
        return fsc.next();
    }

    public static String[] ns(int n) {
        String[] s = new String[n];
        Arrays.setAll(s, i -> ns());
        return s;
    }

    public static boolean[][] inputGrid(int h, int w, char truechar) {
        boolean[][] grid = new boolean[h][w];
        for (int i = 0; i < h; i++) {
            char[] s = fsc.next().toCharArray();
            for (int j = 0; j < w; j++) {
                grid[i][j] = s[j] == truechar;
            }
        }
        return grid;
    }
}
