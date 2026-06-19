import java.util.*;

class Main{
	public static void main(String args[]){
		Solve s = new Solve();
		s.solve();
	}
}

class Solve{
	Scanner in = new Scanner(System.in);

	void solve(){
		while(in.hasNext()){
			int n = in.nextInt();
			int ans = 0, t = 1;
			for(int i = 0; i < n /2; i++){
				ans += t;
				t *= 3;
			} 
			ans *= 2;
			if(n % 2 ==1) ans += t;
			System.out.println(ans);
		}
	}
}