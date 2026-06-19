import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		AnOrdinaryGame game = new AnOrdinaryGame();
		game.run();
	}
}

class AnOrdinaryGame {
	
	String S;
	
	AnOrdinaryGame() {
		Scanner cin = new Scanner(System.in);
		this.S = cin.nextLine();
	}
	
	void run() {
		int count = 0;
		char[] str = S.toCharArray();
		char head = str[0];
		char last = str[str.length - 1];
		
 		if (head == last) {
 			last = str[1];
 		}
		
		for (int i = 0; i < str.length - 1; i++) {
			
			if (str[i] == head) {
				if (str[i + 1] == last)
					continue;
			} else if (str[i] == last) {
				if (str[i + 1] == head)
					continue;
			}
			count++;
		}
		count = Math.max(0, count--);
		
		if (count % 2 == 0) {
			System.out.println("Second");
		} else {
			System.out.println("First");
		}
	}
}
