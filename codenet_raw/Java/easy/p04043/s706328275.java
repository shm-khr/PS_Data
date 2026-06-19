
import java.util.Scanner;

public class  IrohaAndHaiku{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int fiv = 0;
        int sev = 0; //初期値設定
        
        for(int i = 0; i < 3; i++) {
            int num = sc.nextInt();//入力値
            switch(num){ //
            case 5:
                fiv++;
                break;
            case 7:
                sev++;
                break;
            }
        }
        if(fiv == 2 && sev == 1) {
            System.out.println("YES");
        }
        else{
            System.out.println("no");
        }
    }
}