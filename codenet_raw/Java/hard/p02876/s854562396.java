import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.SortedSet;
import java.util.Set;
import java.util.NavigableSet;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        TaskD.Item next(TreeSet<TaskD.Item> s, TaskD.Item a) {
            NavigableSet<TaskD.Item> items = s.tailSet(a, false);
            if (items.isEmpty()) return null;
            return items.first();
        }

        TaskD.Item prev(TreeSet<TaskD.Item> s, TaskD.Item a) {
            NavigableSet<TaskD.Item> items = s.headSet(a, false);
            if (items.isEmpty()) return null;
            return items.last();
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            TaskD.Item[] items = new TaskD.Item[n];
            for (int i = 0; i < n; ++i) {
                items[i] = new TaskD.Item();
                items[i].index = i;
                items[i].a = in.nextLong();
                items[i].b = in.nextLong();
            }
            List<TaskD.Item> good = new ArrayList<>();
            List<TaskD.Item> bad = new ArrayList<>();
            for (TaskD.Item item : items) {
                if (item.a <= item.b) good.add(item);
                else bad.add(item);
            }
            TreeSet<TaskD.Item> byB = new TreeSet<>();
            if (good.isEmpty()) {
                out.println("0 1");
                return;
            }
            long delta = 0;
            for (TaskD.Item g : good) {
                byB.add(g);
                delta += g.b - g.a;
            }
            long prefSum = 0;
            int count = 0;
            TaskD.Item at = byB.first();
            while (prefSum + at.b < delta) {
                prefSum += at.b;
                ++count;
                at = next(byB, at);
            }
            long resp = count * at.b + delta - prefSum;
            long resq = at.b;
            Collections.sort(bad, new Comparator<TaskD.Item>() {

                public int compare(TaskD.Item o1, TaskD.Item o2) {
                    return Long.compare(o1.a, o2.a);
                }
            });
            for (TaskD.Item item : bad) {
                byB.add(item);
                delta += item.b - item.a;
                if (delta <= 0) break;
                if (item.compareTo(at) < 0) {
                    ++count;
                    prefSum += item.b;
                }
                while (prefSum >= delta) {
                    TaskD.Item before = prev(byB, at);
                    prefSum -= before.b;
                    --count;
                    at = before;
                }
                while (prefSum + at.b < delta) {
                    prefSum += at.b;
                    ++count;
                    at = next(byB, at);
                }
                long curp = count * at.b + delta - prefSum;
                long curq = at.b;
                double ddiff = curp * (double) resq - curq * (double) resp;
                if (ddiff > 1e18) {
                    resp = curp;
                    resq = curq;
                } else if (ddiff > -1e18) {
                    long diff = curp * resq - curq * resp;
                    if (diff > 0) {
                        resp = curp;
                        resq = curq;
                    }
                }
            }
            resq *= n;
            long g = gcd(resp, resq);
            resp /= g;
            resq /= g;
            out.println(resp + " " + resq);
        }

        private long gcd(long a, long b) {
            while (b > 0) {
                long t = a % b;
                a = b;
                b = t;
            }
            return a;
        }

        static class Item implements Comparable<TaskD.Item> {
            int index;
            long a;
            long b;

            public int compareTo(TaskD.Item o) {
                TaskD.Item o1 = this;
                TaskD.Item o2 = o;
                int z = Long.compare(o1.b, o2.b);
                if (z == 0) z = o1.index - o2.index;
                return z;
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}

