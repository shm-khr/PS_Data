import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int n = Integer.parseInt(line);
        for(int i=0; i<n/2;i++){
        	BigDecimal bd1 = new BigDecimal(br.readLine());
        	BigDecimal bd2 = new BigDecimal(br.readLine());
        	if(bd1.add(bd2).precision()>80 ){
        		System.out.println("overflow");
        	}else{
        		System.out.println(bd1.add(bd2));
        	}
        }
    }
}