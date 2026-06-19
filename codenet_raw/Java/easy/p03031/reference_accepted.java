import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new java.io.InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        String[][] input_multiArray = new String[M][N];

        for(int i = 0; i < M; i++) {
            input_multiArray[i] = br.readLine().split(" ");
        }

        String[] p_array = br.readLine().split(" ");

        int ans = 0;

        for(int i = 0; i < (1<<N); i++) {

            boolean ableFlag = false;

            for(int j = 0; j < M; j++) {

                int onNum = 0;

                for(int k = 1; k <= Integer.parseInt(input_multiArray[j][0]); k++) {
                    if((i>>Integer.parseInt(input_multiArray[j][k])-1 & 1) == 1) {
                        onNum++;
                    }
                }

                if(onNum % 2 == Integer.parseInt(p_array[j])) {
                    ableFlag = true;
                } else {
                    ableFlag = false;
                    break;
                }
            }

            if(ableFlag) ans++;

        }

        pw.print(ans);
        br.close();
        pw.close();
    }
}