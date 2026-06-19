import java.util.Scanner;


public class Main {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()){
			int H = sc.nextInt();
			int[][] puz=new int[H][5];
			int result =0;
			for(int i=0;i<=H-1;i++){
				for(int j=0;j<=4;j++){
					puz[i][j]=sc.nextInt();
				}
			}
			if(H==0){
				break;
			}
			if(H==1){
					if(puz[0][2]==puz[0][3] && puz[0][2]==puz[0][1] && puz[0][2]!=0){
						if(puz[0][2]==puz[0][0] && puz[0][2]==puz[0][4]){
							result = puz[0][2]*5;
						}
						else if(puz[0][2]==puz[0][0] || puz[0][2]==puz[0][4]){
							result = puz[0][2]*4;
						}
						else{
							result =result + puz[0][2]*3;
							}
					}
					else if(puz[0][2]==puz[0][1] && puz[0][2]==puz[0][0] && puz[0][2]!=0){
						result = result + puz[0][2]*3;				
					}
					else if(puz[0][2]==puz[0][3] && puz[0][2]==puz[0][4] && puz[0][2]!=0){
						result=result+puz[0][2]*3;			
					}
					else{
						result = 0;
					}
					System.out.println(result);
			}
			else{
			while(true){
				int cd=0;
				for(int i=0;i<=H-1;i++){
					if(puz[i][2]==puz[i][3] && puz[i][2]==puz[i][1] && puz[i][2]!=0){
						if(puz[i][2]==puz[i][0] && puz[i][2]==puz[i][4]){
							result = result + puz[i][2]*5;
							for(int j=0;j<=4;j++){
								puz[i][j]=0;
							}
							for(int j=i-1;j>=0;j--){
								int c=0;
								for(int k=0;k<=4;k++){
									if(puz[j][k]!=0){
										puz[j+1][k]=puz[j][k];
										puz[j][k]=0;
									}
									else{
										c++;
									}
								}
								if(c==5){
									break;
								}								
							}
							
						}
						else if(puz[i][2]==puz[i][0]){
							//4
							result = result + puz[i][2]*4;
							for(int j=0;j<=3;j++){
								puz[i][j]=0;
							}
							for(int j=i-1;j>=0;j--){
								int c=0;
								for(int k=0;k<=3;k++){
									if(puz[j][k]!=0){
										puz[j+1][k]=puz[j][k];
										puz[j][k]=0;
									}
									else{
										c++;
									}
								}
								if(c==4){
									break;
								}								
							}
						}
						else if(puz[i][2]==puz[i][4]){
							result = result + puz[i][2]*4;
							for(int j=4;j>=1;j--){
								puz[i][j]=0;
							}
							for(int j=i-1;j>=0;j--){
								int c=0;
								for(int k=4;j>=1;j--){
									if(puz[j][k]!=0){
										puz[j+1][k]=puz[j][k];
										puz[j][k]=0;
									}
									else{
										c++;
									}
								}
								if(c==4){
									break;
								}								
							}
						}
						else{
							result =result + puz[i][2]*3;
							for(int j=1;j<=3;j++){
								puz[i][j]=0;
							}
							for(int j=i-1;j>=0;j--){
								int c=0;
								for(int k=1;k<=3;k++){
									if(puz[j][k]!=0){
										puz[j+1][k]=puz[j][k];
										puz[j][k]=0;
									}
									else{
										c++;
									}
								}
								if(c==3){
									break;
								}								
							}
						}
					}
					else if(puz[i][2]==puz[i][1] && puz[i][2]==puz[i][0] && puz[i][2]!=0){
						result = result + puz[i][2]*3;
						for(int j=0;j<=2;j++){
							puz[i][j]=0;
						}
						for(int j=i-1;j>=0;j--){
							int c=0;
							for(int k=0;k<=2;k++){
								if(puz[j][k]!=0){
									puz[j+1][k]=puz[j][k];
									puz[j][k]=0;
								}
								else{
									c++;
								}
							}
							if(c==3){
								break;
							}								
						}
					}
					else if(puz[i][2]==puz[i][3] && puz[i][2]==puz[i][4] && puz[i][2]!=0){
						result=result+puz[i][2]*3;
						for(int j=2;j<=4;j++){
							puz[i][j]=0;
						}
						for(int j=i-1;j>=0;j--){
							int c=0;
							for(int k=2;k<=4;k++){
								if(puz[j][k]!=0){
									puz[j+1][k]=puz[j][k];
									puz[j][k]=0;
								}
								else{
									c++;
								}
							}
							if(c==3){
								break;
							}								
						}
					}
					else{
						cd++;
					}
				}
				if(cd==H){
					break;
				}
			}
			System.out.println(result);
			
		}
		}
	}
}