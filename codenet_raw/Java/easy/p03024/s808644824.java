import java.util.*;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        sc.close();

        // 主処理
        boolean judge = 7 <= s.replaceAll("[^o]", "").length();
        String result = judge ? "YES" : "NO";

        // 出力
        System.out.println(result);
    }
}
