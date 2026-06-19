import java.util.*;
class Main {
	public static void main(String[] args) {
		int big=20;
		int sml=19;
		Scanner scn=new Scanner(System.in);
		int n=scn.nextInt();
		int[][] dat=new int[n][3];
		int[] ans=new int[n];
		for (int i=0;i<dat.length;i++){
			for(int j=0;j<3;j++){
				dat[i][j]=scn.nextInt();
			}
			int cnt=dat[i][0];
			int bcnt=0;
			int scnt=0;
			int a=0;
                        if(dat[i][1]<10){
			if(dat[i][1]%2==0){
				if(dat[i][0]%3==0){a++;}
				for(int d=dat[i][2];d<=sml;d++) a++;
			}else{
				for(int d=dat[i][2];d<=big;d++) a++;
			}
			for(int m=dat[i][1]+1;m<=10;m++){
				if(m%2==0&&dat[i][0]%3!=0){scnt++;}
				else{bcnt++;}
			}
                        cnt++;
                        }else{
			for(int d=dat[i][2];d>=1;d--) a--;
			}
			while(cnt<1000){
				if(cnt%3==0){
					bcnt+=10;
				}else{
					bcnt+=5;
					scnt+=5;
				}
				cnt++;
			}
			ans[i]=bcnt*big+scnt*sml+a;
		}

		for(int i=0;i<ans.length;i++){
			System.out.println(ans[i]);
		}
	}
}