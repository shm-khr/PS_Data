import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
    public void solve() {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String S = scan.next();
        char[] d = S.toCharArray();
        Set<Character> ns = new HashSet<>();
        Set<Character> ew = new HashSet<>();
        for (int i = 0; i < d.length; i++) {
            char x = d[i];
            if (x == 'W' || x == 'E') {
                ew = move_ew(ew, x);
                continue;
            }
            if (x == 'N' || x == 'S') {
                ns = move_ns(ns, x);
                continue;
            }
        }
        if (ns.size() == 0 && ew.size() == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
    private Set<Character> move_ns(Set<Character> set, char x) {
        return move_inner(set, x, 'N','S');
    }
    private Set<Character> move_ew(Set<Character> set, char x) {
        return move_inner(set, x, 'W','E');
    }
    private Set<Character> move_inner(Set<Character> set, char x, char d1, char d2) {
        if (x == d1) {
            if (set.contains(d2)) {
                set.remove(d2);
                return set;
            }
            if (!set.contains(d1)) {
                set.add(d1);
            }
        }
        if (x == d2) {
            if (set.contains(d1)) {
                set.remove(d1);
                return set;
            }
            if (!set.contains(d2)) {
                set.add(d2);
            }
        }
        return set;
    }
}
