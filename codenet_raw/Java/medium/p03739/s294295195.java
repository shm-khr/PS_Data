import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long ns[] = new long[n];
        for (int i = 0; i < n; i++) {
            ns[i] = sc.nextLong();
        }
        long sum = ns[0];
        long ans = 0;
        boolean isNegative = ns[0] < 0;
        int j;
        for (j = 0; j < n -1; j++) {
            if (ns[j] != ns[j+1]) {
                isNegative = ns[j] < ns[j+1];
                break;
            }
        }
        if (ns[0] == 0) {
            if (j % 2 != 0)
                isNegative = !isNegative;
            if (isNegative) {
                sum = -1;
            }
            else
                sum = 1;
            ans++;
        }
        for (int i = 1; i < n; i++) {
            sum += ns[i];
            if (isNegative && sum < 0) {
                ans -= sum - 1;
                sum = 1;
            }
            else if (!isNegative && sum > 0) {
                ans += sum + 1;
                sum = -1;
            }
            else if (sum == 0) {
                ans++;
                if (isNegative)
                    sum = 1;
                else
                    sum = -1;
            }
            isNegative = !isNegative;
        }


        System.out.println(ans);
    }
}
