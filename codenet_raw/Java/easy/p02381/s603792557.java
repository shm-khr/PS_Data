import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	    
		String x = "";
		try {
			while (x.equals("0") == false) {
				int n = Integer.parseInt(in.readLine());
				String[] data = in.readLine().split(" ");
			
				double sum = 0;
				
				int[] score = new int[n];
				for (int i = 0; i < n; i++) {
					score[i] = Integer.parseInt(data[i]);
					sum = sum + score[i];
				}
				
				double m = sum / n;
				sum = 0;
				for (int i = 0; i < n; i++) {
					sum = sum + (score[i] - m) * (score[i] - m);
				}
				System.out.println(Math.sqrt(sum / n));
			}
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}