import java.util.*;

public class Main {
	public static void main(String[] args) {
		new Main().execute();
	}

	public void execute() {
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();

		long[] A = new long[N];

		for (int i = 0; i < N; i++) {
			long ai = sc.nextLong();
			A[i] = ai;
		}
		long cntA, cntB;
		if (A[0] == 0) {
			A[0] = 1;
			cntA = 1 + countOps(A);
			A[0] = -1;
			cntB = 1 + countOps(A);
		} else if (A[0] > 0) {
			cntA = countOps(A);
			A[0] = -1;
			cntB = A[0] + 1 + countOps(A);
		} else {
			cntB = countOps(A);
			A[0] = 1;
			cntA = Math.abs(A[0]) + 1 + countOps(A);
		}
		System.out.println(Math.min(cntA, cntB));
		sc.close();
	}

	private long countOps(long[] A) {
		long[] arr = A.clone();
		long sum = arr[0];
		long cnt = 0;
		for (int i = 1; i < arr.length; i++) {
			if (sum > 0) {
				if (sum + arr[i] >= 0) {
					cnt += sum + arr[i] + 1;
					arr[i] = -sum - 1;
					sum = -1;
				} else {
					sum = sum + arr[i];
				}
			} else {// sum <0
				if (sum + arr[i] <= 0) {
					cnt += (sum + arr[i]) * -1 + 1;
					arr[i] = -sum + 1;
					sum = 1;
				} else {
					sum = sum + arr[i];
				}
			}
		}
		return cnt;
	}

}
