import java.util.Scanner;

import static java.lang.Math.PI;
import static java.lang.Math.sin;
import static java.lang.Math.pow;
import static java.lang.Math.cos;
import static java.lang.Math.sqrt;

class Main{
    
    public static void main(String[] arg){

        Scanner in = new Scanner(System.in);

        String input = in.nextLine();

        int cnt = Integer.parseInt(input);

        while(cnt != 0){
            int sum = 0;
            input = in.nextLine();
            String [] param_line = input.split(" ", 0);
            int [] points = new int[param_line.length];
            for(int i=0; i<points.length; i++){
                points[i] = Integer.parseInt(param_line[i]);
                sum += points[i];
            }
            double avg = sum/points.length;
            double tmp = 0;
            for(int i=0; i<points.length; i++)
                tmp += pow(points[i]-avg,2);

            double bunsan = tmp/points.length;
            double hyohen = sqrt(bunsan);

            System.out.println(hyohen);

            input = in.nextLine();
            cnt = Integer.parseInt(input);
        }
    }
}