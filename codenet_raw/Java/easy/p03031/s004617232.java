import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
      	int N = sc.nextInt();
      	int M = sc.nextInt();
		int[][] aiTD = new int[M][N];
      	for(int i=0; i< M;  i++){
			int K = sc.nextInt();
          	for(int j=0; j< K;  j++){
              aiTD[i][sc.nextInt()-1] = 1;
            }
        }
      	int[] al = new int[M];
      	for(int i=0; i< M;  i++){
			al[i] = sc.nextInt();
        }
      
      	for(int i=0; i< M;  i++){
          	String tmp = "";
          	for(int j=0; j< N;  j++){
        		tmp += String.valueOf(aiTD[i][j]);
            }
          	System.out.println(tmp);
        }
      
      	for(int i=0; i< M;  i++){
          	int sum = 0;
          	for(int j=0; j< N;  j++){
        		sum += aiTD[i][j];
            }
          	if((sum%2)==al[i]){}else{
            	System.out.println(0);
              	return;
            }
        }
        System.out.println(1);
        return;
	}
}
