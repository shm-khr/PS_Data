import java.io.*;
public class Main{
        public static void main(String[] args) throws IOException {
                BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
                String is; 
                while((is = in.readLine()) != null){
                        int n = Integer.parseInt(is);
                        int c = 0;
                        int i = 0;
                        for(;i < n && i < 4; ++i){
                                c += 1 + 2 * Math.floor(i/2);
                        }
                        int d = 9;
                        for(;i < n; ++i){
                                c += d;
                                if(i%2 == 1){
                                        d += 6;
                                }
                        }
                        System.out.println(c);
                }   
        }   
}