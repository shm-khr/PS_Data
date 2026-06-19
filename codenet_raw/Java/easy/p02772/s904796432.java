import java.util.Scanner;

public class Main { //クラス名はMain
    public static void main(String[] args) {
        //コード
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        boolean j = true;

        for(i=0; i<n ; i++){
            int a = Integer.parseInt(sc.next());
            if(a%2 == 0){
                if(a%3 != 0 && a%5 != 0){
                    j = false;
                }
            }
        }
        if(j){
            System.out.println("APPROVED");
        }else{
            System.out.println("DENIED");
        }
    }
}