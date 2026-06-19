import java.util.*;
import static java.lang.System.*;

public class Main {

	Scanner sc = new Scanner(in);
	
	boolean[][][] dice = new boolean[6][3][3];
	
	int minrote(int n) {
		if (n == 0) {
			if ((dice[0][2][0] || dice[0][2][1] || dice[0][2][2]) && (dice[2][2][0] || dice[2][2][1] || dice[2][2][2]))
				return 0;
			if ((dice[0][0][2] || dice[0][1][2] || dice[0][2][2]) && (dice[2][0][0] || dice[2][1][0] || dice[2][2][0]))
				return 1;
			if ((dice[0][0][0] || dice[0][1][0] || dice[0][2][0]) && (dice[2][0][2] || dice[2][1][2] || dice[2][2][2]))
				return 1;
			if ((dice[0][0][0] || dice[0][0][1] || dice[0][0][2]) && (dice[2][0][0] || dice[2][0][1] || dice[2][0][2]))
				return 1;
		}
		if (n == 1) {
			if ((dice[1][2][0] || dice[1][2][1] || dice[1][2][2]) && (dice[3][2][0] || dice[3][2][1] || dice[3][2][2]))
				return 3;
			if ((dice[1][0][2] || dice[1][1][2] || dice[1][2][2]) && (dice[3][0][0] || dice[3][1][0] || dice[3][2][0]))
				return 2;
			if ((dice[1][0][0] || dice[1][1][0] || dice[1][2][0]) && (dice[3][0][2] || dice[3][1][2] || dice[3][2][2]))
				return 2;
			if ((dice[1][0][0] || dice[1][0][1] || dice[1][0][2]) && (dice[3][0][0] || dice[3][0][1] || dice[3][0][2]))
				return 3;
		}
		if (n == 2) {
			if ((dice[4][2][0] || dice[4][2][1] || dice[4][2][2]) && (dice[5][0][0] || dice[5][0][1] || dice[5][0][2]))
				return 1;
			if ((dice[4][0][2] || dice[4][1][2] || dice[4][2][2]) && (dice[5][0][2] || dice[5][1][2] || dice[5][2][2]))
				return 2;
			if ((dice[4][0][0] || dice[4][1][0] || dice[4][2][0]) && (dice[5][0][0] || dice[5][1][0] || dice[5][2][0]))
				return 2;
			if ((dice[4][0][0] || dice[4][0][1] || dice[4][0][2]) && (dice[5][2][0] || dice[5][2][1] || dice[5][2][2]))
				return 1;
		}
		return 10000;
	}
	
	void run() {
		String s;
		
		while (true) {
			s = sc.nextLine();
			if (s.equals("#")) break;
			
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 3; j++) {
					for (int k = 0; k < 3; k++) {
						dice[i][j][k] = s.charAt(k) == '*';
						
					}
					s = sc.nextLine();
				}
			}
			
			int min = 10;
			for (int i = 0; i < 3; i++)
				min = Math.min(min, minrote(i));
			
			out.println(min);
			
		}
	}
	
	public static void main(String[] args) {
		new Main().run();
	}

}