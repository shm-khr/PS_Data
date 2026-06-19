import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int k = scanner.nextInt();
        boolean can = false;
        for (int i = 0; i < k + 1; i++) {
            if (can) {
                break;
            }
            for (int j = 0; j < k + 1; j++) {
                if (can) {
                    break;
                }
                for (int l = 0; l < k + 1; l++) {
                    int sum = i + l + j;
                    if (!(2 < sum && sum < k + 1)) {
                        continue;
                    }
                    int aa = (int) Math.pow(a, i + 1);
                    int bb = (int) Math.pow(b, j + 1);
                    int cc = (int) Math.pow(c, l + 1);
                    if (aa < bb && bb < cc) {
                        can = true;
                        break;
                    }
                }
            }
        }
        if (can) {
            System.out.println("Yes");
        }else {
            System.out.println("No");
        }
    }


    private static int nextInt(Scanner scanner) {
        return Integer.parseInt(scanner.next());
    }

    private static long nextLong(Scanner scanner) {
        return Long.parseLong(scanner.next());
    }

    private static float nextFloat(Scanner scanner) {
        return Float.parseFloat(scanner.next());
    }

    private static double nextDouble(Scanner scanner) {
        return Double.parseDouble(scanner.next());
    }


}







