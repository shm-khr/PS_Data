import java.util.*;

public class Main{
    void solve(){
        Scanner scan = new Scanner(System.in);
        boolean xp = false;
        boolean xm = false;
        boolean yp = false;
        boolean ym = false;
        String s = scan.next();
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == 'N') yp = true;
            else if(s.charAt(i) == 'E') xp = true;
            else if(s.charAt(i) == 'S') ym = true;
            else xm = true;
        }
        if(yp == true && ym == false || xp == true && xm == false){
            System.out.println("No");
        }else if(ym == true && yp == false || xm == true && xp == false){
            System.out.println("No");
        }else{
            System.out.println("Yes");
        }
    }
    
    public static void main(String[] args){
        new Main().solve();
    }
}
