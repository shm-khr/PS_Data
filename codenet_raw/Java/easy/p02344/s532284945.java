import java.util.Scanner;
import java.util.Arrays;

public class Main { //HDL-style Disjoint Set
	static int N; // int_maxsize > 10000 (constrain)
	static int Q; // int_maxsize > 110000 (worstcase = 10000initial set  + 100000 new set)
	static boolean Com; //com only have two kind;
	static int V1;
	static int V2;
	static int V3;
	static int[] S1;
	static int[] S2;
	static Scanner scanner;
	public static void main(String[] args){
		scanner = new Scanner(System.in);
		N = scanner.nextInt();
		S1 = new int[N];
		S2 = new int[N];
		reset();
		Q = scanner.nextInt();
		FSM();
	}
	//end of main
	private static void reset(){
		Com = false;
		V1 = 0;
		V2 = 0;
		V3 = 0;
		for(int i = 0; i<N; i++){
			S1[i]=i;
		}
	}
	//end of reset
	private static void FSM(){
		while(Q>0){
			fetch();
			dispatch();
			Q--;
		}
	}
	//end of FSM
	private static void fetch(){
		Com = (scanner.nextInt() > 0)?true:false;
		//V1 = scanner.nextInt();
		//V2 = scanner.nextInt();
	}
	//end of feteh
	private static void dispatch(){
		if(Com){
			V1 = scanner.nextInt();
			V2 = scanner.nextInt();
			query();
		}else {
			V1 = scanner.nextInt();
			V2 = scanner.nextInt();
			V3 = scanner.nextInt();
			relate();
		}
	}
	//end of dispatch
	private static void relate(){
		if(S1[V1] == S1[V2]){
			return;
		}else{
			merge();
		}
	}
	//end of unite
	private static void query(){
		if(S1[V1] == S1[V2]){
			System.out.println(S2[V2] - S2[V1]);
		}else{
			System.out.println("?");
		}
	}
	//end of same
	private static void merge(){
		V3 = S2[V2] - V3 - S2[V1];
		V1 = S1[V1];// use variable 1 to store the set code of V1
		V2 = S1[V2];// use variable 2 to store the set code of V2
		for(int i = 0; i< N;i++)
		{
			if(S1[i] == V1){
				//System.out.println("V1 = "+ V1 + "V2 = " + V2+ "V3 = " + V3);
				S1[i] = V2;
				S2[i] = S2[i] + V3;
				//System.out.println("S2[i] = "+ S2[i]);
			}else{
				continue;
			}
		}
	}
}	

