import java.util.Scanner;

public class Main {
    static Scanner stdIn = new Scanner(System.in);
    public static void main(String[] args){
        int a = stdIn.nextInt();
        int b = stdIn.nextInt();
        int c = stdIn.nextInt();
        int k = stdIn.nextInt();

        for(int i=0; i<k+2-1; i++){
            for(int j=i+1; j<k+2; j++){
                if(a * pow(2, i) < b * pow(2, j-i-1) && b * pow(2, j-i-1) < c * pow(c, k+1-j)){
                    System.out.println("Yes");
                    return;
                }
            }
        }

        System.out.println("No");
    }

    static int pow(int a, int b){
        int x = 1;
        for(int i=0; i<b; i++){
            x *= a;
        }
        return x;
    }
}
