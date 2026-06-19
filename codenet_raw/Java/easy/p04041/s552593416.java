import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int[] elements = new int[3];
		for(int i=0; i<3; i++) elements[i] = sc.nextInt();
		
		int res = 0;
		for(int i=num; i>=3; i--) res += (int)Math.pow(10, num-i) * count(i, elements, 0, elements[0]);
		System.out.println(res);
	}
	
	public static int count(int num, int[] elements, int pos, int ele) {
		if(pos==2 && ele==0) {
			return 1 * (int)Math.pow(10, num);
		} else if(num==0 || ele<0) {
			return 0;
		} else {
			if(ele==0) {
				ele = elements[++pos];
			}
			int res = 0;
			for(int i=1; i<=10; i++) res += count(num-1, elements, pos, ele-i);
			return res;
		}
	}
}