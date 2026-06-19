import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Main main = new Main();
		main.solveD();
	}

	private void solveD() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		Map<Integer, List<Integer>> mapList = new HashMap<>();
		for (int i = 0; i < N - 1; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			if (!mapList.containsKey(a)) {
				mapList.put(a, new ArrayList<Integer>());
			}
			if (!mapList.containsKey(b)) {
				mapList.put(b, new ArrayList<Integer>());
			}
			mapList.get(a).add(b);
			mapList.get(b).add(a);
		}
		if (judge(N, mapList)) {
			System.out.println("First");
		} else {
			System.out.println("Second");
		}
	}

	private boolean judge(int N, Map<Integer, List<Integer>> graph) {
		if (N % 2 == 1) {
			return true;
		}
		int[] leafAdjCount = new int[N + 1];
		for (int a = 1; a <= N; a++) {
			int count = 0;
			int lastNode = 0;
			List<Integer> adjList = graph.get(a);
			if (adjList.size() == 1) {
				leafAdjCount[adjList.get(0)]++;
			}
		}
		for (int count : leafAdjCount) {
			if (count > 1) {
				return true;
			}
		}
		return false;
	}
}