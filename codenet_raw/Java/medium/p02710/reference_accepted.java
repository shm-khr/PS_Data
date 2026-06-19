import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.OptionalInt;
import java.util.PrimitiveIterator;

class Main {
    public static void main(String[] args) throws Exception {
        FastScanner sc = new FastScanner();
        FastPrintStream pw = new FastPrintStream();
        solve(sc, pw);
        sc.close();
        pw.flush();
        pw.close();
    }

    public static void solve(FastScanner sc, FastPrintStream pw) {
        int n = sc.nextInt();
        int[] c = new int[n];
        Arrays.setAll(c, i -> sc.nextInt() - 1);
        TreeBuilder tb = new TreeBuilder(n);
        for (int i = 0; i < n - 1; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            tb.addEdge(u, v);
        }
        long[] ans = new long[n];
        Tree t = tb.build();
        int[] rootCon = new int[n];
        Arrays.fill(rootCon, n);
        int[] par = t.parent();
        int[] sub = DFS.dfsDPInt(t, i -> 1, Integer::sum, Integer::sum, 0);
        int[] con = sub.clone();
        int[] dep = new int[n];
        for (int u : t.preOrder()) if (u != t.getRoot()) dep[u] = dep[par[u]] + 1;
        int[] tour = eulerTour(t);
        // System.err.println(Arrays.toString(tour));
        IntDeque[] colStacks = new IntDeque[n];
        for (int i = 0; i < n; i++) {
            colStacks[i] = new IntDeque();
        }
        int[] lvl = new int[n];
        for (int i = 0; i < n << 1; i++) {
            int v = tour[i];
            if (v >= 0) {
                lvl[dep[v]] = v;
                if (colStacks[c[v]].size() > 0) {
                    int colPar = colStacks[c[v]].getLast();
                    con[lvl[dep[colPar] + 1]] -= sub[v];
                } else {
                    rootCon[c[v]] -= sub[v];
                }
                colStacks[c[v]].addLast(v);
            } else {
                colStacks[c[~v]].removeLast();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int v : t.getEdges(i)) {
                if (v != par[i]) {
                    long num = con[v];
                    ans[c[i]] += num * (num + 1) / 2;
                }
            }
            if (i != c[t.getRoot()]) {
                long num = rootCon[i];
                ans[i] += num * (num + 1) / 2;
            }
        }
        long sum = (long) n * (n + 1) / 2;
        for (int i = 0; i < n; i++) {
            pw.println(sum - ans[i]);
        }
    }

    public static int[] eulerTour(Tree t) {
        int n = t.getV();
        boolean[] vis = new boolean[n];
        int[] pre = t.preOrder();
        int[] pst = t.postOrder();
        // System.err.println("pre : " + Arrays.toString(pre));
        // System.err.println("pst : " + Arrays.toString(pst));
        int[] tour = new int[n << 1];
        int i = 0, j = 0;
        while (i + j < tour.length) {
            while (i != n) {
                tour[i + j] = pre[i];
                vis[pre[i]] = true;
                if (pre[i++] == pst[j]) break;
            }
            while (j != n && vis[pst[j]]) {
                tour[i + j] = ~pst[j];
                j++;
            }
        }
        return tour;
    }
}

class IntDeque implements Iterable<Integer> {
    static final int DEFAULT_CAPACITY = 1 << 6;
    int[] buf;
    int len = 1;
    int mask;
    int head = 0;
    int tail = 0;
    public IntDeque(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException(
                String.format("Capacity %d is negative.", capacity)
            );
        }
        while (this.len < capacity) {
            this.len <<= 1;
        }
        this.mask = this.len - 1;
        this.buf = new int[len];
    }
    public IntDeque() {
        this(DEFAULT_CAPACITY);
    }
    public int getLast() {
        if (size() == 0) throw new NoSuchElementException();
        return buf[(tail - 1) & mask];
    }
    public int getFirst() {
        if (size() == 0) throw new NoSuchElementException();
        return buf[head];
    }
    public int get(int index) {
        if (index < 0 || index >= size()) {
            throw new IndexOutOfBoundsException(
                String.format("Index %d out of bounds for length %d.", index, size())
            );
        }
        return buf[(head + index) & mask];
    }
    public void addLast(int v) {
        if (size() == len) grow();
        buf[tail++ & mask] = v;
    }
    public void addFirst(int v) {
        if (size() == len) grow();
        buf[--head & mask] = v;
    }
    public int removeLast() {
        if (size() == 0) throw new NoSuchElementException();
        return buf[--tail & mask];
    }
    public int removeFirst() {
        if (size() == 0) throw new NoSuchElementException();
        return buf[head++ & mask];
    }
    public OptionalInt pollLast() {
        if (size() == 0) return OptionalInt.empty();
        return OptionalInt.of(removeLast());
    }
    public OptionalInt pollFirst() {
        if (size() == 0) return OptionalInt.empty();
        return OptionalInt.of(removeFirst());
    }
    public int size() {
        return tail - head;
    }
    public boolean isEmpty() {
        return size() == 0;
    }
    public void clear() {
        head = tail = 0;
    }
    public int[] toArray() {
        int[] ret = new int[size()];
        PrimitiveIterator.OfInt it = iterator();
        Arrays.setAll(ret, i -> it.nextInt());
        return ret;
    }
    private void grow() {
        int[] newBuf = new int[len << 1];
        head &= mask;
        tail &= mask;
        int len1 = len - head;
        int len2 = head;
        System.arraycopy(buf, head, newBuf, 0, len1);
        System.arraycopy(buf, 0, newBuf, len1, len2);
        this.head = 0;
        this.tail = this.len;
        this.len <<= 1;
        this.mask = this.len - 1;
        this.buf = newBuf;
    }
    public PrimitiveIterator.OfInt iterator() {
        return new PrimitiveIterator.OfInt(){
            int it = head;
            public boolean hasNext() {return it < tail;}
            public int nextInt() {return buf[it++ & mask];}
        };
    }
    public PrimitiveIterator.OfInt descendingIterator() {
        return new PrimitiveIterator.OfInt(){
            int it = tail;
            public boolean hasNext() {return it > head;}
            public int nextInt() {return buf[--it & mask];}
        };
    }

    /***************************** DEBUG *********************************/

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append('[');
        PrimitiveIterator.OfInt it = iterator();
        while (it.hasNext()) {
            sb.append(it.next().toString());
            if (it.hasNext()) sb.append(',');
        }
        sb.append(']');
        return sb.toString();
    }
}

class DFS {
    @SuppressWarnings("unchecked")
    public static <Node, Result> Result[] dfsDP(Tree t, java.util.function.IntFunction<Node> node, java.util.function.BiFunction<Node, Result, Result> gather, java.util.function.BinaryOperator<Result> mergeChildren, java.util.function.Supplier<Result> e) {
        final int n = t.getV();
        final int[] par = t.parent();
        Result[] dp = (Result[]) new Object[n];
        for (int u : t.postOrder()) {
            Node p = node.apply(u);
            Result res = e.get();
            for (int v : t.getEdges(u)) {
                if (v == par[u]) continue;
                res = mergeChildren.apply(res, dp[v]);
            }
            dp[u] = gather.apply(p, res);
        }
        return dp;
    }
    public static int[] dfsDPInt(Tree t, java.util.function.IntUnaryOperator node, java.util.function.IntBinaryOperator gather, java.util.function.IntBinaryOperator mergeChildren, int e) {
        final int n = t.getV();
        final int[] par = t.parent();
        int[] dp = new int[n];
        for (int u : t.postOrder()) {
            int p = node.applyAsInt(u);
            int res = e;
            for (int v : t.getEdges(u)) {
                if (v == par[u]) continue;
                res = mergeChildren.applyAsInt(res, dp[v]);
            }
            dp[u] = gather.applyAsInt(p, res);
        }
        return dp;
    }
    public static long[] dfsDPLong(Tree t, java.util.function.LongUnaryOperator node, java.util.function.LongBinaryOperator gather, java.util.function.LongBinaryOperator mergeChildren, long e) {
        final int n = t.getV();
        final int[] par = t.parent();
        long[] dp = new long[n];
        for (int u : t.postOrder()) {
            long p = node.applyAsLong(u);
            long res = e;
            for (int v : t.getEdges(u)) {
                if (v == par[u]) continue;
                res = mergeChildren.applyAsLong(res, dp[v]);
            }
            dp[u] = gather.applyAsLong(p, res);
        }
        return dp;
    }
}

class TreeBuilder {
    private final int n;
    private int ptr = 0;
    private final int root;
    private final long[] edges;
    private final int[] count;
    private final int[][] adj;
    public TreeBuilder(int n, int root) {
        this.n = n;
        this.root = root;
        this.edges = new long[n - 1];
        this.count = new int[n];
        this.adj = new int[n][];
    }
    public TreeBuilder(int n) {
        this(n, 0);
    }
    public void addEdge(int u, int v) {
        edges[ptr++] = (long) u << 32 | v;
        count[u]++;
        count[v]++;
    }
    private static final long mask = 0xffff_ffffl;
    public Tree build() {
        for (int i = 0; i < n; i++) {
            adj[i] = new int[count[i]];
        }
        for (long e : edges) {
            int u = (int) (e >>> 32);
            int v = (int) (e & mask);
            adj[u][--count[u]] = v;
            adj[v][--count[v]] = u;
        }
        return new Tree(n, root, adj);
    }
}

class Tree {
    private final int n;
    private final int root;
    private final int[][] adj;
    private final int[] par;
    private final int[] pre;
    private final int[] pst;
    Tree(int n, int root, int[][] adj) {
        this.n = n;
        this.adj = adj;
        this.root = root;
        this.par = new int[n];
        this.pre = new int[n];
        this.pst = new int[n];
        build();
    }
    private void build() {
        int preOrd = 0, pstOrd = 0;
        java.util.Arrays.fill(par, -1);
        int[] stack = new int[n << 1];
        int ptr = 0;
        stack[ptr++] = ~root;
        stack[ptr++] =  root;
        while (ptr > 0) {
            int u = stack[--ptr];
            if (u >= 0) {
                pre[preOrd++] = u;
                for (int i = adj[u].length - 1; i >= 0; i--) {
                    int v = adj[u][i];
                    if (v == par[u]) continue;
                    par[v] = u;
                    stack[ptr++] = ~v;
                    stack[ptr++] =  v;
                }
            } else {
                pst[pstOrd++] = ~u;
            }
        }
    }
    public int getV() {
        return n;
    }
    public int getRoot() {
        return root;
    }
    public int[] getEdges(int u) {
        return adj[u];
    }
    public int[] parent() {
        return par;
    }
    public int[] preOrder() {
        return pre;
    }
    public int[] postOrder() {
        return pst;
    }
}

class FastPrintStream implements AutoCloseable {
    private static final int BUF_SIZE = 1 << 15;
    private final byte[] buf = new byte[BUF_SIZE];
    private int ptr = 0;
    private final java.lang.reflect.Field strField;
    private final java.nio.charset.CharsetEncoder encoder;

    private java.io.OutputStream out;

    public FastPrintStream(java.io.OutputStream out) {
        this.out = out;
        java.lang.reflect.Field f;
        try {
            f = java.lang.String.class.getDeclaredField("value");
            f.setAccessible(true);
        } catch (NoSuchFieldException | SecurityException e) {
            f = null;
        }
        this.strField = f;
        this.encoder = java.nio.charset.StandardCharsets.US_ASCII.newEncoder();
    }

    public FastPrintStream(java.io.File file) throws java.io.IOException {
        this(new java.io.FileOutputStream(file));
    }

    public FastPrintStream(java.lang.String filename) throws java.io.IOException {
        this(new java.io.File(filename));
    }

    public FastPrintStream() {
        this(System.out);
        try {
            java.lang.reflect.Field f = java.io.PrintStream.class.getDeclaredField("autoFlush");
            f.setAccessible(true);
            f.set(System.out, false);
        } catch (IllegalAccessException | IllegalArgumentException | NoSuchFieldException e) {
            // ignore
        }
    }

    public FastPrintStream println() {
        if (ptr == BUF_SIZE) internalFlush();
        buf[ptr++] = (byte) '\n';
        return this;
    }

    public FastPrintStream println(java.lang.Object o) {
        return print(o).println();
    }

    public FastPrintStream println(java.lang.String s) {
        return print(s).println();
    }

    public FastPrintStream println(char[] s) {
        return print(s).println();
    }

    public FastPrintStream println(char c) {
        return print(c).println();
    }

    public FastPrintStream println(int x) {
        return print(x).println();
    }

    public FastPrintStream println(long x) {
        return print(x).println();
    }

    public FastPrintStream println(double d, int precision) {
        return print(d, precision).println();
    }

    private FastPrintStream print(byte[] bytes) {
        int n = bytes.length;
        if (ptr + n > BUF_SIZE) {
            internalFlush();
            try {
                out.write(bytes);
            } catch (java.io.IOException e) {
                throw new RuntimeException();
            }
        } else {
            System.arraycopy(bytes, 0, buf, ptr, n);
            ptr += n;
        }
        return this;
    }

    public FastPrintStream print(java.lang.Object o) {
        return print(o.toString());
    }

    public FastPrintStream print(java.lang.String s) {
        if (strField == null) {
            return print(s.getBytes());
        } else {
            try {
                return print((byte[]) strField.get(s));
            } catch (IllegalAccessException e) {
                return print(s.getBytes());
            }
        }
    }

    public FastPrintStream print(char[] s) {
        try {
            return print(encoder.encode(java.nio.CharBuffer.wrap(s)).array());
        } catch (java.nio.charset.CharacterCodingException e) {
            byte[] bytes = new byte[s.length];
            for (int i = 0; i < s.length; i++) {
                bytes[i] = (byte) s[i];
            }
            return print(bytes);
        }
    }

    public FastPrintStream print(char c) {
        if (ptr == BUF_SIZE) internalFlush();
        buf[ptr++] = (byte) c;
        return this;
    }

    public FastPrintStream print(int x) {
        if (x == 0) {
            if (ptr == BUF_SIZE) internalFlush();
            buf[ptr++] = '0';
            return this;
        }
        int d = len(x);
        if (ptr + d > BUF_SIZE) internalFlush();
        if (x < 0) {
            buf[ptr++] = '-';
            x = -x;
            d--;
        }
        int j = ptr += d; 
        while (x > 0) {
            buf[--j] = (byte) ('0' + (x % 10));
            x /= 10;
        }
        return this;
    }

    public FastPrintStream print(long x) {
        if (x == 0) {
            if (ptr == BUF_SIZE) internalFlush();
            buf[ptr++] = '0';
            return this;
        }
        int d = len(x);
        if (ptr + d > BUF_SIZE) internalFlush();
        if (x < 0) {
            buf[ptr++] = '-';
            x = -x;
            d--;
        }
        int j = ptr += d; 
        while (x > 0) {
            buf[--j] = (byte) ('0' + (x % 10));
            x /= 10;
        }
        return this;
    }

    public FastPrintStream print(double d, int precision) {
        if (d < 0) {
            print('-');
            d = -d;
        }
        d += Math.pow(10, -d) / 2;
        print((long) d).print('.');
        d -= (long) d;
        for(int i = 0; i < precision; i++){
            d *= 10;
            print((int) d);
            d -= (int) d;
        }
        return this;
    }

    private void internalFlush() {
        try {
            out.write(buf, 0, ptr);
            ptr = 0;
        } catch (java.io.IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void flush() {
        try {
            out.write(buf, 0, ptr);
            out.flush();
            ptr = 0;
        } catch (java.io.IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void close() {
        try {
            out.close();
        } catch (java.io.IOException e) {
            throw new RuntimeException(e);
        }
    }

    private static int len(int x) {
        int d = 1;
        if (x >= 0) {d = 0; x = -x;}
        int p = -10;
        for (int i = 1; i < 10; i++, p *= 10) if (x > p) return i + d;
        return 10 + d;
    }

    private static int len(long x) {
        int d = 1;
        if (x >= 0) {d = 0; x = -x;}
        long p = -10;
        for (int i = 1; i < 19; i++, p *= 10) if (x > p) return i + d;
        return 19 + d;
    }
}

class FastScanner implements AutoCloseable {
    private final java.io.InputStream in;
    private final byte[] buf = new byte[2048];
    private int ptr = 0;
    private int buflen = 0;

    public FastScanner(java.io.InputStream in) {
        this.in = in;
    }

    public FastScanner() {
        this(System.in);
    }

    private boolean hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        try {
            buflen = in.read(buf);
        } catch (java.io.IOException e) {
            throw new RuntimeException(e);
        }
        return buflen > 0;
    }

    private int readByte() {
        return hasNextByte() ? buf[ptr++] : -1;
    }

    public boolean hasNext() {
        while (hasNextByte() && !(32 < buf[ptr] && buf[ptr] < 127)) ptr++;
        return hasNextByte();
    }

    private StringBuilder nextSequence() {
        if (!hasNext()) throw new java.util.NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        for (int b = readByte(); 32 < b && b < 127; b = readByte()) {
            sb.appendCodePoint(b);
        }
        return sb;
    }

    public String next() {
        return nextSequence().toString();
    }

    public String next(int len) {
        return new String(nextChars(len));
    }

    public char nextChar() {
        if (!hasNextByte()) throw new java.util.NoSuchElementException();
        return (char) readByte();
    }

    public char[] nextChars() {
        StringBuilder sb = nextSequence();
        int l = sb.length();
        char[] dst = new char[l];
        sb.getChars(0, l, dst, 0);
        return dst;
    }
    public char[] nextChars(int len) {
        if (!hasNext()) throw new java.util.NoSuchElementException();
        char[] s = new char[len];
        int i = 0;
        int b = readByte();
        while (32 < b && b < 127 && i < len) {
            s[i++] = (char) b; b = readByte();
        }
        if (i != len) {
            throw new java.util.NoSuchElementException(
                String.format("Next token has smaller length than expected.", len)
            );
        }
        return s;
    }
    public long nextLong() {
        if (!hasNext()) throw new java.util.NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) throw new NumberFormatException();
        while (true) {
            if ('0' <= b && b <= '9') {
                n = n * 10 + b - '0';
            } else if (b == -1 || !(32 < b && b < 127)) {
                return minus ? -n : n;
            } else throw new NumberFormatException();
            b = readByte();
        }
    }
    public int nextInt() {
        return Math.toIntExact(nextLong());
    }
    public double nextDouble() {
        return Double.parseDouble(next());
    }
    public void close() {
        try {
            in.close();
        } catch (java.io.IOException e) {
            throw new RuntimeException(e);
        }
    }
}
