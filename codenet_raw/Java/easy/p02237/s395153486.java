import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main{
    //directed graph
    LinkedList<Integer>[] adg;
    Main(int n){
        //adg = new LinkedList<Integer>[n+1];
        for(int i = 0; i<=n; i++){
            adg[i] = new LinkedList<>();
        }
    }
    void addEdge(int index, int vertex){
        adg[index].add(vertex);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Main graph = new Main(n);
        for(int i = 0; i<n; i++){
            int index = in.nextInt();
            int m = in.nextInt();
            for(int j = 0; j<m; j++){
                int temp = in.nextInt();
                graph.addEdge(index,temp);
            }
        }
        //change to matrix
        int[][] matrix = new int[n+1][n+1];
        for(int i = 1; i<=n; i++){
            if(graph.adg[i].size()!=0) {
                for (int c : graph.adg[i]) {
                    matrix[i][c] = 1;
                }
            }
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(j!=n) System.out.print(matrix[i][j]+ " ");
                else System.out.print(matrix[i][j]);
            }
            System.out.println();
        }

    }
}

