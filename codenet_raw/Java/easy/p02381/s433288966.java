import java.util.*;
public class Main {
public static void main(String[] args) {
	Scanner sc=new Scanner(System.in);
	while(sc.hasNext()) {
		int sum=0;
		float sum2=0;
		float a = 0;
	int n=sc.nextInt();
	if(n==0) {
		break;
	}
	int s[]=new int[n];
	for(int i=0;i<s.length;i++) {
		s[i]=sc.nextInt();
	}
	for(int i=0;i<s.length;i++) {
		sum=sum+s[i];
	}
	int m=sum/n;
	for(int i=0;i<s.length;i++) {
			a=(s[i]-m)*(s[i]-m);
			sum2=sum2+a;
	}
	float a2=sum2/n;
	float a3=(float) Math.sqrt(a2);
	System.out.println(a3);
}
}
}
