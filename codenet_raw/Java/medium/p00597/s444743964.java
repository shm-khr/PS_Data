import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

class Main{


	public static void main(String args[]){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try{
			String str;
			while((str = br.readLine()) != null){
				int n = Integer.parseInt(str);

				switch(n){
				case 0:{
					System.out.println(0);
				}
				case 1:{
					System.out.println(1);
					break;
				}
				case 2:{
					System.out.println(2);
					break;
				}
				case 3:{
					System.out.println(5);
				}
				default:{
					if(n%2 == 0){
						int m = n/2 - 1;
						int result = n + m * (m + 1) * 2;
						System.out.println(result);
					}else{
						int m = (n - 1)/2 - 1;
						int result = n + (n - 1) + m * (m + 1) * 2;
						System.out.println(result);
					}
				}
				}
			}
		}catch(Exception e){
		}
	}
}