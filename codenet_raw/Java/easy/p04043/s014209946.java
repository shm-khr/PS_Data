import java.util.Scanner;
public class Main {
public static void main(String[] args) {
	Scanner scanner = new Scanner (System.in);
	int [] a;a=new int [3];boolean dool =false;
	for (int i=0;i<3;i++) {
		int x = scanner.nextInt();
		if (x!=5&&x!=7) {System.out.println("NO");dool=true; break;}
		a[i]=x;
	}
	if (dool==false) {
		boolean chool =false;
		for (int i=0;i<2;i++) {
			if (a[i]>a[i+1]) {System.out.println("NO");chool=true;break;}
		}
		if (chool==false) System.out.println("YES");
	}
	
	scanner.close();
}
}