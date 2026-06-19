import java.util.*;

class Main{
    public static void main(String args[]){
	int[][] graph = new int[150][150];
	Scanner in = new Scanner(System.in);
	int n, u, k;

	n=in.nextInt();
	for(int i=0; i<n; i++){
	    u=in.nextInt();
	    k=in.nextInt();
	    //read vartex informetion
	    for(int j=0; j<k; j++){
		graph[u-1][in.nextInt()-1]=1;
	    }
	}

	//print
	for(int i=0; i<n; i++){
	    for(int j=0; j<n; j++){
		System.out.print(graph[i][j]);
		if(j<n-3)System.out.print(" ");
	    }
	    System.out.println(" ");
	}
	    System.out.println(" ");
    }
}