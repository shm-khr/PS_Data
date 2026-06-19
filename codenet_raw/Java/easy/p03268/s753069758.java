import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        int kp2bai = 0;
        int kbai = 0;
        long ans = 0L;
        for (int i = 1; i <= n; i++) {
            if (i % (k / 2) == 0) kp2bai++;//k/2の倍数
            if (i % k == 0) kbai++;//kの倍数
        }
        if (k % 2 == 0) {
            ans = kp2bai;
        } else {
            ans = kbai;
        }

        System.out.println(ans * ans * ans);
    }
}
