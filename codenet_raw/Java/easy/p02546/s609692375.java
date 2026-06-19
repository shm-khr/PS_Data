import java.util.*;

class MAIN{
	public static void main(String args[]){
    	Scanner in = new Scanner(System.in);
      
      	String s = in.nextLine();
      
      	if(s.charAt(s.length()-1) == 's'){
          System.out.println(s.substring(0,s.length()-1) + "es");

        }
        else{
          System.out.println(s+"s");
        }
    }
}