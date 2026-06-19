import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        int N = in.nextInt();
        City[] c = new City[N];
        UnionFind uf = new UnionFind(N);
        for (int i = 0; i < N; i++) {
            c[i] = new City(i, in.nextLong(), in.nextLong());
        }
        ArrayList<Road> roads = new ArrayList<>();
        Arrays.sort(c, new Comparator<City>() {
            public int compare(City c1, City c2){
                return c1.x > c2.x ? 1 : -1;
            }
        });
        for(int i = 1; i < c.length; i++){
            roads.add(new Road(c[i - 1].p, c[i].p, Math.abs(c[i - 1].x - c[i].x)));
        }
        Arrays.sort(c, new Comparator<City>() {
            public int compare(City c1, City c2){
                return c1.y > c2.y ? 1 : -1;
            }
        });
        for(int i = 1; i < c.length; i++){
            roads.add(new Road(c[i - 1].p, c[i].p, Math.abs(c[i - 1].y - c[i].y)));
        }
        roads.sort(new Comparator<Road>() {
            public int compare(Road r1, Road r2){
                return r1.cost > r2.cost ? 1 : -1;
            }
        });
        long ans = 0;
        for(Road r: roads){
            if(!uf.same(r.from, r.to)){
                ans += (long)r.cost;
                uf.union(r.from, r.to);
            }
        }
        System.out.println(ans);
    }
}

class City {
    int p;
    long x, y;

    public City(int a, long b, long c) {
        p = a;
        x = b;
        y = c;
    }
}

class Road{
    int from, to;
    long cost;
    public Road(int f, int t, long c){
        from = f;
        to= t;
        cost = c;
    }
}

class UnionFind {
    int[] par;
    int[] rank;

    public UnionFind(int n) {
        par = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    public int find(int i) {
        if (par[i] == i) {
            return i;
        }
        return par[i] = find(par[i]);
    }

    public void union(int x, int y) {
        x = find(x);
        y = find(y);

        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }

    public boolean same(int x, int y) {
        return find(par[x]) == find(par[y]);
    }
}