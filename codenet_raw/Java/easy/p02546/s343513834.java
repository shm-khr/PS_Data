import java.util.Scanner;


public class justAClass {

    public static void main( String[] args) {
        Scanner input = new Scanner(System.in);
        String S = input.next();
        if(S.endsWith("s")) {
            out.println(S+"es");
        }
        else {
            out.println(S+"s");
        }


     }
}