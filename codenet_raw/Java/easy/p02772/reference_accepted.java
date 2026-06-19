import java.util.*;
public class Main{
	public static void main(String[] args){
    	Scanner sc = new Scanner(System.in);
      	int N = sc.nextInt();
      	int[] A = new int [N];
      	for(int i = 0; i < N; i++){
        	A[i] = sc.nextInt();
        }
      	boolean isTrue = true;
      	for(int i = 0; i < N; i++){
        	if(A[i] % 2 == 0){
            	if(A[i]%3==0 || A[i]%5==0){
                	
                }else{
                	isTrue = false;
                }
            }
        }
      	if(isTrue) System.out.println("APPROVED");
      	else System.out.println("DENIED");
    }
}