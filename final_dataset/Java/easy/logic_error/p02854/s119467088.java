import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
       
        Scanner sc = new Scanner(System.in);
        int hoge = sc.nextInt();
        int[] array = new int[hoge];
        int sum = 0;
        int num2 = 0;
        int num = 0;
        int count = 0;
        for(int i = 0; i < hoge; i++){
            array[i] = sc.nextInt();
            sum += array[i];
        }
        if(sum % 2 != 0){
            sum++;
        }
        for(int i= 0; i < hoge; i++){
            num += array[i];
            if(num > (sum/2)){
                for(int j = i + 1; j< hoge; j++){
                    num2 += array[j];
                }
                break;
            }else if(num == (sum/2)){
                for(int k = i + 1; k < hoge; k++){
                    num2 += array[k];
                }
                break;
            }
        }
        while(true){
            if(num != (sum/2)){
                num--;
                count++;
            }
            if(num2 != (sum/2)){
                num2++;
                count++;
            }
            if(num == (sum/2) && num2 == (sum/2)){
                break;
            }
        }
        System.out.println(count);
    }     
}