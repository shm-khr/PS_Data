import java.io.*;
public class Main{
        public static void main(String[] args) throws IOException {
                BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
                String is; 
                while((is = in.readLine()) != null){
                        int n = Integer.parseInt(is);
                        int c = 0;
                        for(int i = 0;i < n; ++i){
                                c += 1 + 2 * Math.floor(i/2);
                        }   
                        System.out.println(c);
                }   
        }   
}