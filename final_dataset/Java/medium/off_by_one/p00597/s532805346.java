import java.io.*;

public class Main {
	public static void main(String[] args) {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));       
		try {
			String line;
			while((line=r.readLine())!=null){
				/* input from here */
				int n = Integer.parseInt(line);
				/* input till here */

				/* processing from here */
				int size=0;
				for(int i=1;i<=n;i++){
					size = size + i - ((i+1)%2);
				}
				/* processing till here */
				/* output */
				System.out.println(size);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}