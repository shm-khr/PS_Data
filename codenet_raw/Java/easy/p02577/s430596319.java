import java.io.*;

public class Main {

	public static void main(String[] args) {
		int sum = 0;
		
		try(FileReader fw = new FileReader("data.txt");) {
			int input = fw.read();
			while(input != -1) {
				sum += input;
			}
		} catch (Exception e) {
			;
		}
		if(sum%9 == 0) {
			System.out.print("YES");
		} else {
			System.out.print("NO");
		}
	
	}

}