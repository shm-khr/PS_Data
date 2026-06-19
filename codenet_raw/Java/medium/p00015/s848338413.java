
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {
	private static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		ArrayList<String> results = new ArrayList<String>();
		
		try{
			while(true){
				results.add(getSumWithInputs(sc.nextInt()));
			}
		}catch(NoSuchElementException e){
			//do nothing
		}
		
		for(int i = 0; i < results.size(); i++){
			System.out.println(results.get(i));
		}
	}
	
	private static String getSumWithInputs(int n){
		String base = "0";
		BigDecimal result = new BigDecimal(base);
		for(int i = 0; i < n; i++){
			result = result.add(new BigDecimal(sc.next()));
		}
		return result.toString();
	}
}