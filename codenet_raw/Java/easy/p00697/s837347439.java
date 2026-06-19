import java.util.Scanner;


public class Jigsaw {

	static char[][] input = new char[9][4];
	static char[][] puzzles = new char[9][4];
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int cnt = Integer.parseInt(s.nextLine());
		for(int i=0 ; i<cnt ; i++) {
			String[] tmp = s.nextLine().split(" ");
			for(int j=0 ; j<9 ; j++) {
				input[j] = tmp[j].toCharArray();
			}
			boolean[] isUsed = new boolean[9];
			System.out.println(solve(0, isUsed));
		}
	}

	public static int solve(int position, boolean[] isUsed) {
		if(position == 9)
			return 1;
		int cnt = 0;
		for(int i=0 ; i<9 ; i++) {
			// ??¢???????±?????????????????????????????????´???
			if(isUsed[i])
				continue;
			char[] puzzle = input[i];
			puzzles[position] = puzzle;
			for(int j=0 ; j<4 ; j++) {
				if(check(position)) {
					isUsed[i] = true;
					cnt += solve(position+1, isUsed);
					isUsed[i] = false;
				}
				rotate(position);
			}
		}
		puzzles[position] = null;
		return cnt;
	}

	public static boolean check(int position) {
		boolean result = false;
		return result;
	}

	public static void rotate(int position) {
		char[] tmp = puzzles[position];
		char tm = tmp[0];
		for(int i=1 ; i<tmp.length ; i++) {
			tmp[i-1] = tmp[i];
		}
		tmp[tmp.length-1] = tm;
	}
}