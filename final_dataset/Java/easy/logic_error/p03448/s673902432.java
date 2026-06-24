import java.io.*;

public class Main{
  public static void main(String[] arcs)throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    int[] args = new int[4];
    for(int i= 0; i<3; i++){
      args[i] = Integer.parseInt(br.readLine());
    }
    args[3]=Integer.parseInt(br.readLine())/50;
    
    int c2 = 0;
    int c10 = 0;
    int counter = 0;
    
    if(args[0] + args[1]*2 + args[2]*10 >= args[3]){
        for( ; c10 <= args[2]; c10++){
            if(c10 * 10 > args[3]){
                break;
            }else if(args[0] + args[1]*2 + c10*10<args[3]){
                //何もしない
            }else{
                for(;c2<=args[1];c2++){
                    if(c10*10 + c2*2 > args[3]){
                        break;
                    }else if(args[0] + c10*10 + c2*2<args[3]){
                        //何もしない
                    }else{
                        counter++;
                    }
                }
            }
        }
    }
    System.out.println(counter);
  }
}
    

