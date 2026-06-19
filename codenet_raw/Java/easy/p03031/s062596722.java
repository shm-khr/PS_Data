import java.util.*;

class Main{
	static int[] swi = new int[10];

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] k = new int[m];
		int[][] s = new int[m][];
		for(int i = 0; i < m; i++){
			k[i] = sc.nextInt();
			s[i] = new int[k[i]];
			for(int j = 0; j < k[i]; j++){
				s[i][j] = sc.nextInt()-1;
			}
		}
		int[] p = new int[m];
		for(int i = 0; i < m ; i++){
			p[i] = sc.nextInt();
		}
		int ans = 0;
		for(int i = 0; i < Math.pow(2,n)-1; i++){
			pra();
			/*for(int aaa : swi){
				System.out.print(aaa);
			}
			System.out.println();*/
			int ba = 0;
			int sumsum = 0;
			for(int j = 0; j < m; j++){
				int sum = 0;
				for(int l = 0; l < k[j]; l++){
					if(swi[s[j][l]] == 1){
						sum++;
					}
				}
				if(sum%2 == p[j]){
					sumsum++;
				}
			}
			if(sumsum == m){
				ans++;
			}
		}
		System.out.print(ans);
	}

	static void pra(){
		int idx = 0;
		while(true){
			if(swi[idx] == 0){
				swi[idx] = 1;
				break;
			}else{
				swi[idx] = 0;
				idx++;
			}
		}
	}
}
