import java.util.*; 

class Main{
public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int ans=0;

  		int[] a=new int[n];
		for(int c=0;c<n;c++){
    		a[c]=sc.nextInt();
    	}
  
  		Arrays.sort(a);
       for(int d=1;d<n;d++){
       	for(int e=0;e<=d-1;e++){
        if(a[d]%a[e]==0){
        ans++;
          break;
        }
        }
       }
		if(a[0]==a[1]){
        ans++;
        }
    	System.out.println(n-ans);
    }
}
