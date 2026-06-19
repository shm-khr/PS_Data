import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static PrintWriter out;

    public static void main(String[] args) {
        Main.run();
    }

    private static void run() {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        Scanner sc = new Scanner(System.in);
        int a = Integer.parseInt(sc.next()); // 冷蔵庫種類
        int b = Integer.parseInt(sc.next()); // クーラー種類
        int m = Integer.parseInt(sc.next()); // 割引券枚数
        // 冷蔵庫価格リスト
        ArrayList<Integer> alist = new ArrayList<>(a);
        for (int i = 0; i < a; i++) {
            alist.add(Integer.parseInt(sc.next()));
        }
        // クーラー価格リスト
        ArrayList<Integer> blist = new ArrayList<>(b);
        for (int i = 0; i < b; i++) {
            blist.add(Integer.parseInt(sc.next()));
        }
        // 冷蔵庫最小価格
        int min_a = 999999999;
        for (Integer i : alist) {
            min_a = Math.min(min_a, i);
        }
        // クーラー最小価格
        int min_b = 999999999;
        for (Integer i : blist) {
            min_b = Math.min(min_b, i);
        }
        // 割引反映前の最少額
        int ans = min_a + min_b;
        // 割引反映
        for (int i = 0; i < m; i++) {
            int x = Integer.parseInt(sc.next()); // 割引対象の番号：冷蔵庫
            int y = Integer.parseInt(sc.next()); // 割引対象の番号：クーラー
            int c = Integer.parseInt(sc.next()); // 割引額
            ans = Math.min(ans, alist.get(x - 1) + blist.get(y - 1) - c);
        }

        out.println(ans);
        out.close();
        sc.close();
    }

}
