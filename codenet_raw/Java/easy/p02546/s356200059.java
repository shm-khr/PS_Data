import  java.util.Scanner;
public class Plural {
       public static void main(String[]args){
             Scanner scan=new Scanner(System.in);
              String S;
               S=scan.nextLine();
                if(S.charAt(S.length()-1)=='s')  System.out.println(S+"es");
                else System.out.println(S+"s");
       }

}
