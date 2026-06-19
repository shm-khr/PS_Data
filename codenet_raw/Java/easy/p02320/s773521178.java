import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    public long solve(int W, List<Integer> values, List<Integer> weights)  {
        int[] dp = new int[W + 1];
        for (int i = 1; i <= values.size(); ++i) {
            for (int j = W; j >= 0; --j) {
                int w = weights.get(i - 1);
                int v = values.get(i - 1);
                if (j - w >= 0) {
                    dp[j] = Math.max(dp[j], dp[j - w] + v);
                }
            }
        }
        return dp[W];
    }
 
    private static List<Integer> transform(int num) {
        List<Integer> ret = new ArrayList<>();
        int ele = 1;
        while (num - ele + 1 > 0) {
            ret.add(ele);
            ele = ele * 2;
        }
        int lst = ret.size() - 1;
        ret.set(lst, num - ret.get(lst) + 1);
        return ret;
    }
 
    private static final Pattern SPLIT = Pattern.compile("\\s");
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Integer> weights = new ArrayList<>();
        List<Integer> values = new ArrayList<>();
        List<Integer> nums = new ArrayList<>();
        List<Integer> NW = Stream.of(SPLIT.split(scanner.nextLine())).map(Integer::valueOf)
                                 .collect(Collectors.toList());
        final int N = NW.get(0);
        final int W = NW.get(1);
        for (int i = 0; i < N; ++i) {
            List<Integer> collect = Stream.of(SPLIT.split(scanner.nextLine())).map(Integer::valueOf)
                                          .collect(Collectors.toList());
            values.add(collect.get(0));
            weights.add(collect.get(1));
            nums.add(collect.get(2));
        }
 
        {
            List<Integer> newWeights = new ArrayList<>();
            List<Integer> newValues = new ArrayList<>();
            List<List<Integer>> numsList = nums.stream().map(KnapsackWithLimitation::transform).collect(Collectors.toList());
            for (int i = 0; i < numsList.size(); ++i) {
                int w = weights.get(i);
                int v = values.get(i);
                newWeights.addAll(numsList.get(i).stream().map(ele -> ele * w).collect(Collectors.toList()));
                newValues.addAll(numsList.get(i).stream().map(ele -> ele * v).collect(Collectors.toList()));
            }
            System.out.println(new Main().solve(W, newValues, newWeights));
        }
    }
}