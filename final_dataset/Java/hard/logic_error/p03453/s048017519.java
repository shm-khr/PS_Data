import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;
 
class E {
    static class Edge {
        final V to;
        final int d;
 
        public Edge(V to, int d) {
            this.to = to;
            this.d = d;
        }
    }
 
    static class V extends ArrayList<Edge> implements Comparable<V> {
        public V(int idx) {
            this.idx = idx;
        }
 
        final int idx;
        long dist = Long.MAX_VALUE;
        long count = 0;
 
        @Override
        public int compareTo(V o) {
            final int l = Long.compare(dist, o.dist);
            return l == 0 ? idx - o.idx : l;
        }
    }
 
    static final long MOD = 1_000_000_000 + 7;
 
    public static void main(String... args) {
        final Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        final int M = sc.nextInt();
        final int S = sc.nextInt() - 1;
        final int T = sc.nextInt() - 1;
        final int[] U = new int[M];
        final int[] V = new int[M];
        final int[] D = new int[M];
        for (int i = 0; i < M; i++) {
            U[i] = sc.nextInt() - 1;
            V[i] = sc.nextInt() - 1;
            D[i] = sc.nextInt();
        }
        final V[] vs = new V[N];
        for (int i = 0; i < N; i++)
            vs[i] = new V(i);
        for (int i = 0; i < M; i++) {
            vs[U[i]].add(new Edge(vs[V[i]], D[i]));
            vs[V[i]].add(new Edge(vs[U[i]], D[i]));
        }
        final TreeSet<V> set = new TreeSet<>();
        vs[S].dist = 0;
        set.add(vs[S]);
        while (!set.isEmpty()) {
            final V v = set.pollFirst();
            for (final Edge e : v)
                if (v.dist + e.d < e.to.dist) {
                    set.remove(e.to);
                    e.to.dist = v.dist + e.d;
                    set.add(e.to);
                }
        }
        final long dist = vs[T].dist;
        final V[] vvs = new V[N];
        final V[] revs = new V[N];
        for(int i = 0; i < N; i++) {
            vvs[i] = new V(i);
            vvs[i].dist = vs[i].dist;
            revs[i] = new V(i);
            revs[i].dist = dist - vs[i].dist;
        }
        for(int i = 0; i < N; i++)
            for(final Edge e : vs[i])
                if(vs[i].dist + e.d == e.to.dist) {
                    vvs[i].add(new Edge(vvs[e.to.idx], e.d));
                    revs[e.to.idx].add(new Edge(revs[i], e.d));
                }
        final V[] sorted = Arrays.copyOf(vvs, N);
        Arrays.sort(sorted);
        vvs[S].count = 1;
        for(int i = 0; i < N; i++)
            for(final Edge e : sorted[i])
                e.to.count = (e.to.count + sorted[i].count) % MOD;
        final V[] rev_sorted = Arrays.copyOf(revs, N);
        Arrays.sort(rev_sorted);
        revs[T].count = 1;
        for(int i = 0; i < N; i++)
            for(final Edge e : rev_sorted[i])
                e.to.count = (e.to.count + rev_sorted[i].count) % MOD;
        long res = vvs[T].count * vvs[T].count % MOD;
//        long revres = revs[T].count * revs[T].count % MOD;
//        System.out.println(res + "\t" + revres);
        for(int i = 0; i < N; i++)
            if(vs[i].dist * 2 == dist) {
                res = (res - vvs[i].count * vvs[i].count %MOD * revs[i].count % MOD * revs[i].count % MOD + MOD) % MOD;
            } else if(vs[i].dist * 2 < dist) {
                for(final Edge e : vs[i])
                    if(e.to.dist * 2 > dist) {
                        res = (res - vvs[i].count * vvs[i].count % MOD * revs[e.to.idx].count % MOD * revs[e.to.idx].count % MOD + MOD) % MOD;
                    }
            }
        System.out.println(res);
    }
}
public class Main {
    public static void main(String... args) {
        E.main(args);
    }
}