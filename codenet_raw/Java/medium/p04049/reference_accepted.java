import java.io.*;
import java.util.*;

/**
 * Created by Katushka on 11.03.2020.
 */
public class Main {

    static int[] readArray(int size, InputReader in) {
        int[] a = new int[size];
        for (int i = 0; i < size; i++) {
            a[i] = in.nextInt();
        }
        return a;
    }

    static long[] readLongArray(int size, InputReader in) {
        long[] a = new long[size];
        for (int i = 0; i < size; i++) {
            a[i] = in.nextLong();
        }
        return a;
    }

    public static void main(String[] args) throws FileNotFoundException {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = in.nextInt();
        int k = in.nextInt();
        List<Integer>[] nodes = new List[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 1; i++) {
            int u = in.nextInt();
            int v = in.nextInt();

            nodes[u].add(v);
            nodes[v].add(u);
        }

        int min = solve(n, k, nodes, 1);
        out.println(min);

        out.close();
    }

    private static int solve(int n, int k, List<Integer>[] nodes, int nodeNum) {
        List<Integer> longestPath = bfs(nodeNum, n, nodes, Integer.MAX_VALUE, -1);
        longestPath = bfs(longestPath.get(longestPath.size() - 1), n, nodes, Integer.MAX_VALUE, -1);
        int diameter = longestPath.size() - 1;

        if (diameter <= k) {
            return 0;
        }

        int min = Integer.MAX_VALUE;
        if (k % 2 == 0) {
            for (int i = 1; i <= n; i++) {
                min = Math.min(min, bfs(i, n, nodes, k / 2, -1).size());
            }
        } else {
            for (int u = 1; u <= n; u++) {
                for (Integer v : nodes[u]) {
                    int ans = bfs(u, n, nodes, k / 2, v).size();
                    ans += bfs(v, n, nodes, k / 2, u).size();
                    min = Math.min(ans, min);
                }
            }
        }

        return min;
    }

    private static Integer getOrDefault(List<Integer> list, int index) {
        return index < list.size() ? list.get(index) : 0;
    }

    private static int dfs(int node, List<Integer>[] nodes, boolean[] visited, List<Integer> toCutForLevel, int level) {
        visited[node] = true;

        while (level + 1 >= toCutForLevel.size()) {
            toCutForLevel.add(0);
        }

        int res = 0;
        for (Integer child : nodes[node]) {
            if (!visited[child]) {
                res += dfs(child, nodes, visited, toCutForLevel, level + 1);
            }
        }
        toCutForLevel.set(level + 1, toCutForLevel.get(level + 1) + res);

        return res + 1;
    }

    private static List<Integer> bfs(int node, int n, List<Integer>[] nodes, int maxPossibleDist, int exceptEdge) {
        Queue<Integer> q = new LinkedList<>();
        q.add(node);
        boolean[] used = new boolean[n + 1];
        int[] parents = new int[n + 1];
        int[] distances = new int[n + 1];
        used[node] = true;
        parents[node] = -1;

        while (!q.isEmpty()) {
            Integer v = q.poll();
            for (Integer to : nodes[v]) {
                if ((v == node && to == exceptEdge) || (v == exceptEdge && to == node)) {
                    continue;
                }
                if (!used[to]) {
                    used[to] = true;
                    q.add(to);
                    distances[to] = distances[v] + 1;
                    parents[to] = v;
                }
            }
        }

        if (maxPossibleDist < Integer.MAX_VALUE) {
            List<Integer> result = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                if (distances[i] > maxPossibleDist) {
                    result.add(i);
                }
            }
            return result;
        }

        int maxNodeInd = -1;
        int maxDist = 0;
        for (int i = 1; i <= n; i++) {
            if (distances[i] > maxDist) {
                maxDist = distances[i];
                maxNodeInd = i;
            }
        }

        List<Integer> path = new ArrayList<>();
        for (int v = maxNodeInd; v != -1; v = parents[v]) {
            path.add(v);
        }
        Collections.reverse(path);
        return path;
    }


    private static void outputArray(long[] ans, PrintWriter out) {
        StringBuilder str = new StringBuilder();
        for (long an : ans) {
            str.append(an).append(' ');
        }
        out.println(str);
    }

    private static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                createTokenizer();
            }
            return tokenizer.nextToken();
        }

        private void createTokenizer() {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public String nextWord() {
            return next();
        }

        public String nextString() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public char nextChar() {
            return next().charAt(0);
        }

        public int[] nextInts() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                createTokenizer();
            }
            List<Integer> res = new ArrayList<>();
            while (tokenizer.hasMoreElements()) {
                res.add(Integer.parseInt(tokenizer.nextToken()));
            }
            int[] resArray = new int[res.size()];
            for (int i = 0; i < res.size(); i++) {
                resArray[i] = res.get(i);
            }
            return resArray;
        }
    }
}