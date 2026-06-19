import java.util.Scanner;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int h = sc.nextInt();
    int w = sc.nextInt();
    int n = sc.nextInt();
    
    int min = 1000000;
    
    for(int i=0; i<w; i++){
      for(int j=0; j<h; j++){
        if(h*i + w*j >= n){
          if(i + j < min){
            min = i + j;
          }
        }
      }
    }
    
    System.out.println(min);
    
  }
}
