import java.util.Scanner;
 
public class Main {    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int red = Integer.parseInt(sc.next());
        int green = Integer.parseInt(sc.next());
        int blue = Integer.parseInt(sc.next());
        int k = Integer.parseInt(sc.next());
        String flag = "No";
        while(true){
            if(green > red && blue > green){
                flag = "Yes";
                break;
            }
            if(k==0){
                break;
            }
            if(red > green){
                green = green * 2;
                k--;
//                System.out.println("k:" + k + "blue:" + blue + "green:" + green + "red:" + red);
            }if(green > blue){
                blue = blue * 2;
                k--;
//                System.out.println("k:" + k + "blue:" + blue + "green:" + green + "red:" + red);
            }
        }
        System.out.println(flag);
    }
}

