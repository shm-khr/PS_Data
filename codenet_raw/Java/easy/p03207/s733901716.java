import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());

        int[] arr = new int[n];
        int sum = 0;
        String[] line = scanner.nextLine().split(" ", n);
        for (int i = 0; i < n; i++) {
            sum += Integer.parseInt(scanner.nextLine());
        }

        System.out.println(sum);
    }
}
