import java.util.Scanner;
import java.util.Arrays;

public class Main { //HDL-style Disjoint Set
	static int N; // int_maxsize > 10000 (constrain)
	static int Q; // int_maxsize > 110000 (worstcase = 10000initial set  + 100000 new set)
	static boolean Com; //com only have two kind;
	static int V1;
	static int V2;
	static int[] S;
	static Scanner scanner;
	public static void main(String[] args){
		scanner = new Scanner(System.in);
		N = scanner.nextInt();
		N = 100000;
		S = new int[N];
		reset();
		Q = scanner.nextInt();
		FSM();
	}
	//end of main
	private static void reset(){
		Com = false;
		V1 = 0;
		V2 = 0;
		for(int i = 0; i<N; i++){
			S[i]=i;
		}
	}
	//end of reset
	private static void FSM(){
		while(Q>0){
			fetch();
			dispatch();
			Q--;
			System.gc();
		}
	}
	//end of FSM
	private static void fetch(){
		Com = (scanner.nextInt() > 0)?true:false;
		V1 = scanner.nextInt();
		V2 = scanner.nextInt();
	}
	//end of feteh
	private static void dispatch(){
		if(Com){
			same();
		}else {
			unite();
		}
	}
	//end of dispatch
	private static void unite(){
		if(S[V1] == S[V2]){
			return;
		}else{
			merge();
		}
	}
	//end of unite
	private static void same(){
		if(S[V1] == S[V2]){
			System.out.println(1);
		}else{
			System.out.println(0);
		}
	}
	//end of same
	private static void merge(){
		V1 = S[V1];// use variable 1 to store the set code of V1
		V2 = S[V2];// use variable 2 to store the set code of V2
		for(int i = 0; i< N;i++)
		{
			if(S[i] == V1){
				S[i] = V2;
			}else{
				continue;
			}
		}
	}
}	

