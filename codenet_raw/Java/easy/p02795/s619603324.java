import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int len = sc.nextInt();
      	int n[] = new int[len];
      	int l[] = new int[len];
        int ans[] = new int[len];
      for (int i=0; i < len;i++) {
        n[i]=sc.nextInt();
        l[i]=sc.nextInt();
      }
      for (int i=0; i < len-1;i++) {
      for (int j=i+1; j < len;j++) {

        if (n[i] > n[j]) {
          int wkn = n[i];
          int wkl = l[i];
          n[i]=n[j];
          l[i]=l[j];
          n[j]=wkn;
          l[j]=wkl;

          
        }
      }
      }
      
      for (int i = 0; i < len-1; i++) {
		int nglen = n[i] - l[i];
        int pslen = n[i] + l[i];

              for (int j = i+1; j < len; j++) {
                  if (n[j] > n[i] + l[i]) {
                  } else {               
                    ans[i]= -1;
                    break;
                  }
                  if (n[i] < n[j] - l[j]){
                  }
              }
      }
      int ret =0;
      for (int i=0; i < len;i++) {
        if (ans[i]>-1) {
          ret++;
        }
      }
//      for (int i=0; i < len;i++) {


 //     System.out.println(n[i] + " " + l[i] + " " + ans[i]);
   //   }
      System.out.println(ret);

	}
}