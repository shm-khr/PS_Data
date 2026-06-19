import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		int N = sc.nextInt();
      Map<Long, Long> map = new TreeMap<>();
      long X,L;
      X=0L;
      L=0L;
      for(int i=0;i<N;i++){
        X=sc.nextLong();
        L=sc.nextLong();
        map.put(X,L);
      }
      int count=0;
      boolean flg = true;
      Long[] Xs=map.keySet().toArray(new Long[map.size()]);
      Long Xn,Ln;
      boolean fflg=false;
      for (int j=0;j<N-1;j++){
        if(flg){
          X=Xs[j];
          L=map.get(X);
          Xn=Xs[j+1];
          Ln=map.get(Xn);
          if(X+L>Xn-Ln){
            count++;
            flg=false;
            if(j==0){
              fflg=true;
            }
          }
        }else{
          flg =true;
          Xn=Xs[j+1];
          Ln=map.get(Xn);
          if(X+L>Xn-Ln){
            count++;
            flg=false;
          }
        }
      }
      if(fflg){
        int count2=1;
        for (int k=1;k<N-1;k++){
        if(fflg){
          X=Xs[k];
          L=map.get(X);
          Xn=Xs[k+1];
          Ln=map.get(Xn);
          if(X+L>Xn-Ln){
            count2++;
            fflg=false;
          }
        }else{
          fflg =true;
          Xn=Xs[k+1];
          Ln=map.get(Xn);
          if(X+L>Xn-Ln){
            count2++;
            flg=false;
          }
        }
      }
        if(count2<count){
          System.out.println(N-count2);
          return;
        }
      }
      System.out.println(N-count);
    }
}