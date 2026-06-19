import java.util.*;
import static java.lang.Integer.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class Main {
	public static void main(String[] args) {
		int i,j;
		Scanner sc = new Scanner(in);
		int h = parseInt(sc.next());
		int w = parseInt(sc.next());
		sc.close();
		int ans = 100000;
		int hmod = h % 3; 
		if(hmod == 0) {
			ans = 0;
		} else {
			if(w % 2 == 0) {
				ans = w/2;
			} else if(hmod == 1){
				ans = Math.min(Math.max(h/3+(w/2)*2+1, (h/3)*2), Math.max(h/3+1, w/2+1));
			} else {
				ans = Math.min(Math.max((h/3)*2+2, (w/2)*2+2), Math.max((h/3)*2+1, w/2 + h/3 + 1));
//				ans = w/2 + h/3 + 1;
			}
		}
		int ans1 = 100000;
		int wmod = w % 3; 
		if(wmod == 0) {
			ans1 = 0;
		} else {
			if(h % 2 == 0) {
				ans1 = h/2;
			} else if(hmod == 1){
				ans1 = Math.min(Math.max(w/3+(h/2)*2+1, (w/3)*2), Math.max(w/3+1, h/2+1));
			} else {
				ans1 = Math.min(Math.max((w/3)*2+2, (h/2)*2+2), Math.max((w/3)*2+1, h/2 + w/3 + 1));
//				ans1 = h/2 + w/3 + 1;
			}
		}
		ans = Math.min(ans, ans1);
		out.println(ans);
	}
}
