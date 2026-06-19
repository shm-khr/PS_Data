import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n;

        while(true){
            n = Integer.parseInt(br.readLine());
            if(n == 0){
                break;
            }

            String[] str = br.readLine().split(" ");
            double ave = 0;
            double alpha = 0;
            double[] line = new int[n];
            for(int i = 0; i < n; i++){
                line[i] = Double.parseDouble(str[i]);
                ave += line[i];
            }
            ave /= n;

            for(int i = 0; i < n; i++){
                alpha += Math.pow((line[i]-ave), 2);
            }
            alpha /= n;
            sb.append(Math.sqrt(alpha)).append("\n");
        }
        System.out.print(sb.toString());
    }
}