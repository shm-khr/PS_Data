import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
        int n = sc.nextInt();
   	    HashSet hs = new HashSet();
        for(int i = 0;i < n; i++){
			hs.add(sc.nextInt());
        }
        System.out.println(hs.size());
    }
}