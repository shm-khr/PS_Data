import java.util.Scanner;

public class Main {

    private static final Scanner  SC = new Scanner(System.in);
    private static final String RESULT = SC.next();

    public static void main(String[] args) {
        byte victory = 0;
        for(char c : RESULT.toCharArray()){
            if(c=='o'){
                victory++;
            }
        }
        if(victory >= 8){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}