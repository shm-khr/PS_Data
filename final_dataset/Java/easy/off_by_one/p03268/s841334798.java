import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		try{
			//ここに問題ごとのロジックを書く
			int n =scanner.nextInt();
			int k = scanner.nextInt();
			int cnt =0;
			for(int a=n;a>=1;a--){
//				System.out.println(a);
				for(int b=n;b>=1;b--){
					if(a+b<k) break;
					if( (a+b) % k !=0 ) continue;
					for(int c=n;c>=1;c--){
//						System.out.println("a:"+a+"b:"+b+"c:"+c);
						if(c+a<k) break;
						if(b+c<k) break;
						if( (a+b) % k ==0 && (b+c) % k==0 && (c+a) % k==0){
							cnt++;
						}
					}
				}
			}
			
			System.out.print(cnt);
		}finally{
			scanner.close();
		}
	}
}