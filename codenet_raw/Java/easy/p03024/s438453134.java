import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
        String line = sc.next();
        String[] s = line.split("");
        int count = 0;
        boolean check = false;
        for(int i=0; i<s.length(); i++){
          if(s[i].equals("x")) count++;
          if(count >= 8) {
            check = true;
            break;
          }
        }
        if(check) System.out.println("NO");
        else System.out.println("YES");
	}
}