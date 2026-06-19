import java.util.*;
public class Main{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        int c = 0;
        for (int i = 1; i < s.length(); i++) {
            if(s.charAt(i) != s.charAt(i-1)){
                c++;
            }
        }
        System.out.println(c);
    }
}
