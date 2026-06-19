
import java.util.Scanner;
import java.util.stream.Stream;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int[] line = Stream.of(sc.nextLine().split(" ", 0)).mapToInt(Integer::parseInt).toArray();
		int[] A_line = Stream.of(sc.nextLine().split(" ", 0)).mapToInt(Integer::parseInt).toArray();
		int[] B_line = Stream.of(sc.nextLine().split(" ", 0)).mapToInt(Integer::parseInt).toArray();

		int[][] M_line = new int[line[2]][3];

		for (int i = 0; i < line[2]; i++) {
			M_line[i] = Stream.of(sc.nextLine().split(" ", 0)).mapToInt(Integer::parseInt).toArray();
		}

		Main main = new Main();

		System.out.println(main.solve(A_line,B_line,M_line));
	}

	public int solve(int[] A_line,int[] B_line,int[][] M_line) {
		int Amin = 1000000000;
		int Bmin = 1000000000;
		int let =0;

		for (int i = 0; i < A_line.length; i++) {
			if (Amin > A_line[i]) {
				Amin = A_line[i];
			}
		}

		for (int i = 0; i < B_line.length; i++) {
			if (Bmin > B_line[i]) {
				Bmin = B_line[i];
			}
		}

		int min = Amin+Bmin;

		for (int i = 0; i < M_line.length; i++) {
			let = A_line[M_line[i][0] - 1] + B_line[M_line[i][1] - 1] - M_line[i][2];
			if (let < min) {
				min = let;
			}
		}

		return min;
	}
}