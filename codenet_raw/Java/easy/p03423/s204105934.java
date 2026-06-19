import java.util.Scanner;

public class Main {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        String line = sc.nextLine();
        System.out.println(line.indexOf('Y')>=0?"Four":"Three");
    }

}
