import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {
	int N;
	long K;
	long[] A;
	long result = 0;

	public static void main(String[] args) throws IOException {
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);
		Main ins = new Main(in);
		ins.calc();
		ins.showResult();
	}

	Main(BufferedReader in) throws IOException {
		String[] tokens = in.readLine().split(" ");
		N = Integer.parseInt(tokens[0]);
		K = Long.parseLong(tokens[1]);
		tokens = in.readLine().split(" ");
		A = new long[N];
		for (int i = 0; i < N; ++i) {
			A[i] = Long.parseLong(tokens[i]);
		}
	}

	void calc() {
		for (int i = 0; i < N; ++i) {
			check(0L, i, 1);
		}
	}

	void check(long prevSum, int index, int num) {
		long sum = prevSum + A[index];
		if (sum % K == num) {
			++result;
		}
		if (index + 1 >= N) {
			return;
		} else {
			check(sum, index + 1, num + 1);
		}
	}

	void showResult() {
		System.out.println(result);
	}
}