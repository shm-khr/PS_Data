import java.util.*;

public class Main {
    public static int MOD = 100000007;

    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        String str = s.next();
        System.out.println(new Main().ABC(str.toCharArray()));
        s.close();
    }

    private int ABC(char[] str){
        int c = 0, bc = 0, abc = 0;

        for(int i = str.length-1; i >= 0; --i){
            char ch = str[i];
            if(ch == 'A')
                abc += bc;
            else if(ch == 'B')
                bc += c;
            else if(ch == 'C')
                ++c;
            else {
                abc += bc;
                bc += c;
                ++c;
            }
            if(abc > MOD)
                abc -= MOD;
        }
        return abc;
    }
}