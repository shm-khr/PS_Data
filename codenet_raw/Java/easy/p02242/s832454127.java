
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int cost[][] = new int[n][n];
        for(int i=0; i<n; i++)
           Arrays.fill(cost[i], Integer.MAX_VALUE);

        for(int ni=0; ni<n; ni++) {
            int u = sc.nextInt();
            int k = sc.nextInt();
            for(int ki=0; ki<k; ki++) {
                int v = sc.nextInt();
                int c = sc.nextInt();
                cost[u][v] = cost[v][u] = c;
            }
        }

        // Dijkstra
        class Node {
            int number;
            int d = Integer.MAX_VALUE;
            Node prev = null;
            int a = Integer.MAX_VALUE;

            int geta() {return a;}
        }
        Node[] V = new Node[n];
        for(int i=0; i<n; i++) {
            V[i] = new Node();
            V[i].number = i;
        }
        V[0].d = 0;
        V[0].a = 0;

        PriorityQueue<Node> q = new PriorityQueue<>(Comparator.comparing(Node::geta));
        q.addAll(Arrays.asList(V));

        while(!q.isEmpty()) {
            Node u = q.peek();
            for(Node v: V) {
                if(cost[u.number][v.number] != Integer.MAX_VALUE) {
                    int alt = u.d + cost[u.number][v.number];
                    if(v.d > alt) {
                        v.d = alt;
                        v.prev = u;
                        v.a = alt;
                    }
                }
            }
            q.poll();
        }

        for(int i=0; i<n; i++) {
            System.out.println(i + " " + V[i].d);
        }
    }
}

