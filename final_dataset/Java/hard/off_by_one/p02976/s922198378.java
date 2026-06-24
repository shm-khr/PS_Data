import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] srcCount = new int[N+1];

        ArrayList<String>[] list =new ArrayList[N+1];
        for(int i=0;i<N+1;i++){
            list[i] = new ArrayList<String>();
        }

        if(M % 2 == 1){
            System.out.println(-1);
            System.exit(0);
        }

        for(int i=0;i<M;i++){
            int A = sc.nextInt();
            int B = sc.nextInt();
            list[A].add(Integer.toString(B));
            list[B].add(Integer.toString(A));
        }

        for(int i=1;i<N+1;i++){
            if(list[i].size() == 1) {
                String src = list[i].get(0);
                int dst = Integer.parseInt(src);
                System.out.println(dst + " " + i);
                srcCount[dst]++;
                list[dst].remove(Integer.toString(i));
                list[i].remove(0);
            }
        }

        for(int i=1;i<N+1;i++){
            if((srcCount[i] + list[i].size()) % 2 == 1 && list[i].size() > 0){
                String src = list[i].get(0);
                int dst = Integer.parseInt(src);
                System.out.println(dst + " " + i);
                srcCount[dst]++;
                list[dst].remove(Integer.toString(i));
                list[i].remove(0);
            }

            for(int j=0;j<list[i].size();j++){
                String dst = list[i].get(j);
                System.out.println(i + " " + dst);
                list[Integer.parseInt(dst)].remove(Integer.toString(i));

            }




        }








    }



}
