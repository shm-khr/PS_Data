

import java.util.*;

public class Main {
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int [] d = new int[n + 1];
        PriorityQueue<Integer> time = new PriorityQueue<>();
        time.add(0);
        d[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int current = scanner.nextInt();
            current = Math.min(current, 24 - current);
            time.add(current);
            d[i] = current;
        }
        int max = 0;
        while (time.size() == n + 1) {
            int current = time.poll();
            int originalCurrent = current;
            int currentMin = 24;
       //     System.out.println("current: " + current);
            PriorityQueue<Integer> copy = new PriorityQueue<>(time);
            while (!time.isEmpty()) {
                int nextTime = time.poll();
           //     System.out.println("next: " + nextTime);
                if (nextTime - current == 24) {
                    currentMin = Math.min(currentMin, 0);
                } else {
                    currentMin = Math.min(currentMin, nextTime - current);
                }
                current = nextTime;
            }
       //     System.out.println("currentMin: " + currentMin);
            max = Math.max(max, currentMin);
    //        System.out.println("max: " + max);
            if (24 - originalCurrent > originalCurrent) {
                copy.add(24 - originalCurrent);
            //    System.out.println("push: " + (24 - originalCurrent));

            }
        //    System.out.println("==============");
            time = new PriorityQueue<>(copy);
        }
        if (max == 24) {
            System.out.println(0);
            return;
        }
        System.out.println(max);

    }
}
