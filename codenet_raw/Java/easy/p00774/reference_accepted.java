import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

	int[][] f;
	int h;

	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	private void run() {
		Scanner sc = new Scanner( System.in );
		while(true){
			h = sc.nextInt();
			f = new int [h][5];
			if(h==0) return;
			for(int i=0;i<h;i++){
				for(int j=0;j<5;j++){
					f[i][j] = sc.nextInt();
				}
			}
			int score = 0;
			while(true){
				while(true){
					int delScore = delete();
					if(delScore==-1) break;
					score += delScore;
				}
				int cntDown = down2();
				if(cntDown==0) break;
			}
			System.out.println(score);
		}
	}

	private int down2() {
		int res = 0;
		int id = h - 1;
		for (int i = 0; i < 5; i++) {
			id = h - 1;
			for (int j = h - 1; 0 <= j; j--) {
				if (f[j][i] != -1) {
					f[id][i] = f[j][i];
					if (id != j) {
						res++;
					}
					id--;
				}
			}
			for (int j = id; j >= 0; j--) {
				f[j][i] = -1;
			}
		}
		return res;
	}

	private int delete() {
		for(int i=0;i<h;i++){
			for(int j=0;j<5;j++){
				if(f[i][j]==-1) continue;
				int start = j;
				int goal = j;
				while(true){
					if(goal+1>=5) break;
					if(f[i][start]==f[i][goal+1]){
						goal++;
					}
					else{
						break;
					}
				}
				if(goal-start+1>=3){
					int element = f[i][start];
					for(int k=start;k<=goal;k++){
						f[i][k] = -1;
					}
					return (goal-start+1)*element;
				}
			}
		}
		return -1;
	}
}