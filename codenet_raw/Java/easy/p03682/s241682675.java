import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Main {

    int[] forest;

    public static void main(String[] args) {
        new Main().compute();
    }

    void compute() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] x = new int[N];
        int[] y = new int[N];
        forest = new int[N];
        List<Edge> edges = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
            forest[i] = i;
            for (int j = 0; j < i; j++) {
                edges.add(new Edge(i, j, Math.min(Math.abs(x[i] - x[j]), Math.abs(y[i] - y[j]))));
            }
        }
        edges.sort((o1, o2) -> o1.cost - o2.cost);
        int sum = 0;
        for (Edge e : edges) {
            if (forest[e.u] != forest[e.v]) {
                sum += e.cost;
                forest = Arrays.stream(forest).map(op -> op == forest[e.v] ? forest[e.u] : op).toArray();
            }
        }
        System.out.println(sum);
    }

    class Edge {

        int u;
        int v;
        int cost;

        Edge(int u, int v, int cost) {
            this.u = u;
            this.v = v;
            this.cost = cost;
        }
    }
}