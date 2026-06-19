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
            public int compare(City p1, City p2){
                return p1.x > p2.x ? 1 : -1;
            }
        });
        for(int i = 0; i < c.length - 1; i++){
            roads.add(new Road(c[i].p, c[i + 1].p, Math.abs(c[i].x - c[i + 1].x)));
        }
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