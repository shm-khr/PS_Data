import java.io.*;
 
public class Main{
  public static void main(String[] args) {
    try {
      long result;
      int n, i = 0;
      long num[] = {0, 0, 0, 0, 0};
 
      BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
 
      n = Integer.parseInt(reader.readLine());
      String name[] = new String[n];
      char nameF[] = new char[n];
 
      for(i = 0; i < n; i++){
        name[i] = reader.readLine();
      }
      
      for(i = 0; i < n; i++){
        nameF[i] = name[i].charAt(0);
      }
      
      for(i = 0; i < n; i++){
        if (nameF[i] == 'M') {
          num[0] = ++num[0];
        }
        if (nameF[i] == 'A') {
          num[1] = ++num[1];
        }
        if (nameF[i] == 'R') {
          num[2] = ++num[2];
        }
        if (nameF[i] == 'C') {
          num[3] = ++num[3];
        }
        if (nameF[i] == 'H') {
          num[4] = ++num[4];
        }
      }
 
      result = num[0]*num[1]*(num[2]+num[3]+num[4])+num[0]*num[2]*(num[3]+num[4])+num[0]*num[3]*num[4]
               +num[1]*num[2]*(num[3]+num[4])+num[1]*num[3]*num[4] + num[2]*num[3]*num[4];
      
      System.out.println(result);
    }
    catch (Exception e) {
      
    }
  }
}