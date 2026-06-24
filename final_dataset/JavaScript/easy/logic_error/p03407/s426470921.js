import java.util.Scanner;
public class A {
  public static void main(String[] args){
    short coina;
    short coinb;
    short toyc;
    Scanner sc = new Scanner(System.in);
    System.out.println("Coin A Coin B Toy's price");
    coina = sc.nextShort();
    coinb = sc.nextShort();
    toyc = sc.nextShort();
    if(coina+coinb<toyc||coina<0||coinb<0){
      System.out.println("no");

    }
    else{System.out.println("yes");
  }
    }
}