import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        try{
            String a = sc.nextLine();
            String b = sc.nextLine();
            a = a+b;
            int num = Integer.parseInt(a);
            num = Math.abs(num);
            int n = (int)Math.sqrt(num);
            if(n*n==num) System.out.println("Yes");
            else System.out.println("No");
        }catch(Exception e){
            System.out.println("No");
        }
    }
}